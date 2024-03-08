#include <cstdlib>
#include <iostream>
#include <random>

class GlobalRandomGenerator {
   public:
    static std::mt19937& getInstance() {
        static std::mt19937 generator(getSeedFromEnvironment());
        return generator;
    }

    static void setSeed(unsigned int seed) { getInstance().seed(seed); }

   private:
    static unsigned int getSeedFromEnvironment() {
        const char* seedStr = std::getenv("CUSTOM_SEED");
        if (seedStr != nullptr) {
            try {
                return static_cast<unsigned int>(std::stoi(seedStr));
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse CUSTOM_SEED: " << e.what() << std::endl;
                std::cerr << "Using std::random_device{}() instead." << std::endl;
            }
        }

        return std::random_device{}();
    }
};