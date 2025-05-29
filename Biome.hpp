#pragma once

#include <string>

class Biome {
public:
    enum class Type {
        DESERT,
        PLAINS,
        TAIGA,
        SAVANNA,
        SNOWY_TUNDRA,
        OCEAN,
        FOREST,
        UNKNOWN
    };

    Biome(Type type, float temperature = 0.0f, float rainfall = 0.0f);
    
    Type getType() const { return type; }
    float getTemperature() const { return temperature; }
    float getRainfall() const { return rainfall; }
    
    std::string getName() const;
    bool isOcean() const;
    bool isSnowy() const;
    
    // Opérateurs de comparaison
    bool operator==(const Biome& other) const {
        return type == other.type;
    }
    
    bool operator!=(const Biome& other) const {
        return !(*this == other);
    }
    
    // Biomes prédéfinis statiques
    static const Biome DESERT;
    static const Biome PLAINS;
    static const Biome TAIGA;
    static const Biome SAVANNA;
    static const Biome SNOWY_TUNDRA;

private:
    Type type;
    float temperature;
    float rainfall;
}; 