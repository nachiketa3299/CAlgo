#include <algorithm>
#include <limits>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

extern "C" {

#include "calgo/predicates.h"
#include "calgo/binary_search.h"
#include "calgo/linear_search.h"

}

class SearchBMFixture: public benchmark::Fixture {
public:
  static std::vector<int> generate_random_vector(size_t n) {
    std::vector<int> vec(n);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(
      std::numeric_limits<int>::min(),
      std::numeric_limits<int>::max()
    );
      
    std::generate(vec.begin(), vec.end(), [&rng, &dist]() { return dist(rng); });
    
    return vec;
  }

  static void sort_vector(std::vector<int>& vec, Pred_int pred) {
    std::sort(vec.begin(), vec.end(), pred);
  }

  static int select_target(const std::vector<int>& vec) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, vec.size() - 1);
    
    return vec[dist(rng)];
  }

  void SetUp(const ::benchmark::State& state) {
      size_t const n = state.range(0);
      data = generate_random_vector(n);
      sort_vector(data, greater_int);
      target = select_target(data);
  }

protected:
    std::vector<int> data;
    int target;
};

BENCHMARK_DEFINE_F(SearchBMFixture, BinarySearch)(benchmark::State& state) {
    for (auto _ : state) {
        bool result = bin_search_int(
          data.data(), data.data() + data.size(), target, greater_int);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_DEFINE_F(SearchBMFixture, LinearSearch)(benchmark::State& state) {
    for (auto _ : state) {
        bool result = lin_search_int(
          data.data(), data.data() + data.size(), target, greater_int);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK_REGISTER_F(SearchBMFixture, BinarySearch)
  ->RangeMultiplier(2)->Range(1 << 10, 1 << 14);
BENCHMARK_REGISTER_F(SearchBMFixture, LinearSearch)
  ->RangeMultiplier(2)->Range(1 << 10, 1 << 14);

BENCHMARK_MAIN();