package reecriture;

import kaptainwutax.biomeutils.source.BiomeSource;
import kaptainwutax.mcutils.block.Block;
import kaptainwutax.mcutils.rand.ChunkRand;
import kaptainwutax.mcutils.state.Dimension;
import kaptainwutax.mcutils.util.block.BlockBox;
import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.pos.BPos;
import kaptainwutax.noiseutils.noise.NoiseSampler;
import kaptainwutax.noiseutils.perlin.OctavePerlinNoiseSampler;
import kaptainwutax.noiseutils.utils.MathHelper;
import kaptainwutax.seedutils.lcg.LCG;
import kaptainwutax.terrainutils.terrain.SurfaceGenerator;
import kaptainwutax.terrainutils.utils.NoiseSettings;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.stream.IntStream;

public class SurfaceGenerator2 extends SurfaceGenerator {
    private final int chunkHeight;
    private final int chunkWidth;
    private final int noiseSizeY;

    public SurfaceGenerator2(BiomeSource biomeSource, int worldHeight, int horizontalNoiseResolution, int verticalNoiseResolution, NoiseSettings noiseSettings, double densityFactor, double densityOffset, boolean useSimplexNoise) {
        super(biomeSource, worldHeight, horizontalNoiseResolution, verticalNoiseResolution, noiseSettings, densityFactor, densityOffset, useSimplexNoise);
        this.chunkHeight = verticalNoiseResolution * 4;
        this.chunkWidth = horizontalNoiseResolution * 4;
        this.noiseSizeY = worldHeight / this.chunkHeight;
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
    public int generateColumnfromY(int x,int startSizeY, int z, Predicate<Block> blockPredicate) {
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

        for(int cellY = startSizeY - 1; cellY >= 0; --cellY) {
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
                double noise = MathHelper.lerp3(percentY, percentX, percentZ, xyz, xy1z, x1yz, x1y1z, xyz1, xy1z1, x1yz1, x1y1z1);
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
}
