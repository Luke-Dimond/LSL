#include <random>
#include <cstdint>

namespace lsl {
    namespace random {

        int randomNumber(int low, int high);
        float randomNumber(float low, float high);
        double randomNumber(double low, double high);

        void setSeed(std::uint64_t seed);
        void randomizeSeed();
    
    }
}