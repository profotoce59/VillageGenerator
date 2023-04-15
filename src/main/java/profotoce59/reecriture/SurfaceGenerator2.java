package profotoce59.reecriture;

import com.seedfinding.mcbiome.source.BiomeSource;
import com.seedfinding.mccore.block.Block;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.state.Dimension;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcnoise.perlin.OctavePerlinNoiseSampler;
import com.seedfinding.mcterrain.terrain.SurfaceGenerator;
import com.seedfinding.mcterrain.utils.MathHelper;
import com.seedfinding.mcterrain.utils.NoiseSettings;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Predicate;
import java.util.stream.IntStream;

import static com.seedfinding.mcnoise.utils.MathHelper.lerp3;
import static com.seedfinding.mcnoise.utils.MathHelper.maintainPrecision;

public class SurfaceGenerator2 extends SurfaceGenerator {
    private final int chunkHeight;
    private final int chunkWidth;
    private final int noiseSizeY;
    private final NoiseSettings noiseSettings;
    private final ChunkRand random1;
    private final OctavePerlinNoiseSampler minLimitPerlinNoise;
    private final OctavePerlinNoiseSampler maxLimitPerlinNoise;
    private final OctavePerlinNoiseSampler mainPerlinNoise;
    private final double densityFactor;
    private final double densityOffset;
    private final Map<Long, double[]> noiseColumnCache = new HashMap<>();
    private int startSizeY;

    public SurfaceGenerator2(BiomeSource biomeSource, int worldHeight, int horizontalNoiseResolution, int verticalNoiseResolution, NoiseSettings noiseSettings, double densityFactor, double densityOffset, boolean useSimplexNoise, int startSizeY) {
        super(biomeSource, worldHeight, horizontalNoiseResolution, verticalNoiseResolution, noiseSettings, densityFactor, densityOffset, useSimplexNoise);
        this.chunkHeight = verticalNoiseResolution * 4;
        this.chunkWidth = horizontalNoiseResolution * 4;
        this.noiseSizeY = worldHeight / this.chunkHeight;
        this.noiseSettings = noiseSettings;
        this.random1 = new ChunkRand(biomeSource.getWorldSeed());
        this.minLimitPerlinNoise = new OctavePerlinNoiseSampler(this.random1, IntStream.rangeClosed(-15, 0));//for version 1.15+
        this.maxLimitPerlinNoise = new OctavePerlinNoiseSampler(this.random1, IntStream.rangeClosed(-15, 0));
        this.mainPerlinNoise = new OctavePerlinNoiseSampler(this.random1, IntStream.rangeClosed(-7, 0));
        this.densityFactor = densityFactor;
        this.densityOffset = densityOffset;
        this.startSizeY = Math.round(startSizeY/8);
    }
    public void setStartSizeY(int newStartSize){

        if(Math.round(newStartSize/8)>this.startSizeY){
            this.startSizeY = Math.round(newStartSize/8);
        }
    }
    @Override
    public Dimension getDimension() {
        return null;
    }

    @Override
    public Block getDefaultBlock() {
        return null;
    }

    @Override
    public Block getDefaultFluid() {
        return null;
    }

    @Override
    public int getBedrockRoofPosition() {
        return 0;
    }

    @Override
    public int getBedrockFloorPosition() {
        return 0;
    }
    protected double[] sampleNoiseColumn(int x, int z) {
        long key = ((((long)x) & 0xFFFFFFFFL) << 32) | (((long)z) & 0xFFFFFFFFL);
        if(noiseColumnCache.containsKey(key)) {
            return noiseColumnCache.get(key);
        } else {
            double[] ds = new double[this.noiseSizeY + 1];
            this.sampleNoiseColumn(ds, x, z);
            noiseColumnCache.put(key, ds);
            return ds;
        }
    }
    public int generateColumnfromY(int x, int z, Predicate<Block> blockPredicate) {
        // those are the coordinates of the region in the grid chosen
        int cellX = Math.floorDiv(x, this.chunkWidth);
        int cellZ = Math.floorDiv(z, this.chunkWidth);
        // those are the coordinates in the chosen region
        int posX = Math.floorMod(x, this.chunkWidth);
        int posZ = Math.floorMod(z, this.chunkWidth);
        double percentX = (double)posX / (double)this.chunkWidth;
        double percentZ = (double)posZ / (double)this.chunkWidth;
        double[][] ds = new double[][] {
                this.sampleNoiseColumn(cellX, cellZ),
                this.sampleNoiseColumn(cellX, cellZ + 1),
                this.sampleNoiseColumn(cellX + 1, cellZ),
                this.sampleNoiseColumn(cellX + 1, cellZ + 1)
        };

        for(int cellY = this.startSizeY - 1; cellY >= 0; --cellY) {
            double xyz = ds[0][cellY];
            double xyz1 = ds[1][cellY];
            double x1yz = ds[2][cellY];
            double x1yz1 = ds[3][cellY];
            double xy1z = ds[0][cellY + 1];
            double xy1z1 = ds[1][cellY + 1];
            double x1y1z = ds[2][cellY + 1];
            double x1y1z1 = ds[3][cellY + 1];

            for(int posY = this.chunkHeight - 1; posY >= 0; --posY) {
                double percentY = (double)posY / (double)this.chunkHeight;
                // this is not a bug, mojang does not respect order
                double noise = lerp3(percentY, percentX, percentZ, xyz, xy1z, x1yz, x1y1z, xyz1, xy1z1, x1yz1, x1y1z1);
                int y = cellY * this.chunkHeight + posY;
                Block block = this.getBlockFromNoise(noise, y);
                // we assume you actually have correctly filled the buffer
                if(blockPredicate != null && blockPredicate.test(block)) {
                    return y + 1;
                }
            }
        }
        return 0;
    }
    protected void sampleNoiseColumn(double[] buffer, int x, int z) {
        double[] ds = this.getDepthAndScale(x, z);
        double depth = ds[0];
        double scale = ds[1];

        if(version.isOlderOrEqualTo(MCVersion.v1_13_2)) {
            this.sampleNoiseColumnOld(buffer, x, z, depth, scale);
            return;
        }

        double sizeY = this.getMaxNoiseY();
        double minY = this.getMinNoiseY();
        double randomOffset = this.biomeSource.getDimension() == Dimension.OVERWORLD ? this.sampleNoise(x, z) : 0.0D;
        for(int y = 6; y < startSizeY; ++y) {
            // everything below is only for 1.14+
            double noise = this.sampleNoise(x, y, z);
            if(version.isNewerOrEqualTo(MCVersion.v1_16)) {
                double fallOff = 1.0D - (double)y * 2.0D / (double)this.noiseSizeY + randomOffset;
                fallOff = fallOff * densityFactor + densityOffset;
                fallOff = (fallOff + depth) * scale;
                noise = fallOff > 0.0 ? noise + fallOff * 4.0D : noise + fallOff;
                if(this.noiseSettings.topSlideSettings.size > 0.0D) {
                    noise = MathHelper.clampedLerp(this.noiseSettings.topSlideSettings.target, noise, ((double)(this.noiseSizeY - y) - this.noiseSettings.topSlideSettings.offset) / this.noiseSettings.topSlideSettings.size);
                }
                if(this.noiseSettings.bottomSlideSettings.size > 0.0D) {
                    noise = MathHelper.clampedLerp(this.noiseSettings.bottomSlideSettings.target, noise, ((double)y - this.noiseSettings.bottomSlideSettings.offset) / this.noiseSettings.bottomSlideSettings.size);
                }
            } else {
                noise -= this.computeNoiseFalloff(depth, scale, y);
                if((double)y > sizeY) {
                    noise = MathHelper.clampedLerp(noise, this.noiseSettings.topSlideSettings.target, (y - sizeY - this.noiseSettings.topSlideSettings.offset) / (double)this.noiseSettings.topSlideSettings.size);
                } else if((double)y < minY) {
                    noise = MathHelper.clampedLerp(noise, this.noiseSettings.bottomSlideSettings.target, (minY - (double)y) / (minY - 1.0D));
                }
            }
            buffer[y] = noise;
        }
    }
    private double sampleNoise(int x, int y, int z) {
        double xzScale = NoiseSettings.COORDINATE_SCALE * noiseSettings.samplingSettings.xzScale;
        double yScale = NoiseSettings.HEIGHT_SCALE * noiseSettings.samplingSettings.yScale;
        double xzStep = xzScale / noiseSettings.samplingSettings.xzFactor;
        double yStep = yScale / noiseSettings.samplingSettings.yFactor;

        double minNoise = 0.0D;
        double maxNoise = 0.0D;
        double mainNoise = 0.0D;
        double persistence = 1.0D;

        for(int octave = 0; octave < 16; ++octave) {
            double cellX = maintainPrecision((double)x * xzScale * persistence);
            double cellY = maintainPrecision((double)y * yScale * persistence);
            double cellZ = maintainPrecision((double)z * xzScale * persistence);
            double sy = yScale * persistence;
            minNoise += this.minLimitPerlinNoise.getOctave(octave).sample(cellX, cellY, cellZ, sy, (double)y * sy) / persistence;
            maxNoise += this.maxLimitPerlinNoise.getOctave(octave).sample(cellX, cellY, cellZ, sy, (double)y * sy) / persistence;
            if(octave < 8) {
                mainNoise += this.mainPerlinNoise.getOctave(octave).sample(
                        maintainPrecision((double)x * xzStep * persistence),
                        maintainPrecision((double)y * yStep * persistence),
                        maintainPrecision((double)z * xzStep * persistence),
                        yStep * persistence,
                        (double)y * yStep * persistence) / persistence;
            }
            persistence /= 2.0D;
        }

        return MathHelper.clampedLerp(minNoise / NoiseSettings.NOISE_SCALE, maxNoise / NoiseSettings.NOISE_SCALE, (mainNoise / 10.0D + 1.0D) / 2.0D);
    }
    private double sampleNoise(int x, int z) {
        double noise = this.depthNoise.sample(x * 200, 10.0D, z * 200, 1.0D, 0.0D, true);
        if(version.isOlderThan(MCVersion.v1_16)) {
            if(version.isNewerOrEqualTo(MCVersion.v1_15)) {
                noise *= 65535.0D;
            }
            noise /= 8000.0D;
        }
        noise = noise < 0.0D ? -noise * 0.3D : noise;
        if(version.isNewerOrEqualTo(MCVersion.v1_16)) {
            noise = noise * 3.0D * 65535.0D / 8000.0D - 2.0D;
            if(noise < 0.0D) {
                return 17.0D * noise / 28.0D / 64.0D;
            }
            return Math.min(noise, 1.0D) * 17.0D / 40.0D / 64.0D;
        }

        noise = noise * 3.0D - 2.0D;
        if(noise < 0.0D) {
            return noise / 28.0D;
        }
        return Math.min(noise, 1.0D) / 40.0D;
    }
}
