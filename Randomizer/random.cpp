#include <random>
#include <chrono>

namespace Random {
float ZTORf() {
  // initialize the random number generator with time-dependent seed
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);
  // initialize a uniform distribution between 0 and 1
  static std::uniform_real_distribution<float> unif(0, 1);
  return unif(mgen);
}

double ZTOR() {
  // initialize the random number generator with time-dependent seed
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);
  // initialize a uniform distribution between 0 and 1
  static std::uniform_real_distribution<double> unif(0, 1);
  return unif(mgen);
}

int ZOOR() {
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);
  // initialize a distribution of 0 or 1 randomer
  static std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 1);
  return dist2(mgen);
}

int NTKR(int n, int k) {
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);

  // check if user put n <= k to process bounds
  if (n <= k) {
    std::uniform_int_distribution<std::mt19937::result_type> ntkd(n, k);
    return ntkd(mgen);
  } else // else n > k, still functions as bounds k to n
  {
    std::uniform_int_distribution<std::mt19937::result_type> ntkd(k, n);
    return ntkd(mgen);
  }
}

float NTKR(float n, float k) {
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);

  // check if user put n <= k to process bounds
  if (n <= k) {
    std::uniform_real_distribution<float> ntkd(n, k);
    return ntkd(mgen);
  } else // else n > k, still functions as bounds k to n
  {
    std::uniform_real_distribution<float> ntkd(k, n);
    return ntkd(mgen);
  }
}

double NTKR(double n, double k) {
  static uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static std::seed_seq ss{ uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32) };
  static std::mt19937 mgen(ss);

  // check if user put n <= k to process bounds
  if (n <= k) {
    std::uniform_real_distribution<double> ntkd(n, k);
    return ntkd(mgen);
  } else // else n > k, still functions as bounds k to n
  {
    std::uniform_real_distribution<double> ntkd(k, n);
    return ntkd(mgen);
  }
}
}