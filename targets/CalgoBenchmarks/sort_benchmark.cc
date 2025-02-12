#include <algorithm>
#include <limits>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

extern "C" {
#include "calgo/predicates.h"
#include "calgo/bubble_sort.h"
#include "calgo/insertion_sort.h"
#include "calgo/selection_sort.h"
#include "calgo/merge_sort.h"
}

class SortingBMFixture: public benchmark::Fixture {
public:
  void SetUp(::benchmark::State const& state) {
    size_t const n = state.range(0);
    vec = generate_vector(n);
    original = vec;
  }
  void TearDown(::benchmark::State const&) { }

protected:
  std::vector<int> vec;
  std::vector<int> original;

private:
  static std::vector<int> generate_vector(size_t n) {
    std::vector<int> vec(n);
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(
      std::numeric_limits<int>::min(), 
      std::numeric_limits<int>::max()
    );

    std::for_each(vec.begin(), vec.end(), [&rng, &dist](auto& e){ e = dist(rng); });

    return vec;
  }
};

BENCHMARK_DEFINE_F(SortingBMFixture, BubbleSort)(benchmark::State& state) {
  for (auto _ : state) {
    vec = original;
    bubble_sort_int(vec.data(), vec.data() + vec.size(), greater_int);
    benchmark::DoNotOptimize(vec);
  }
}

BENCHMARK_DEFINE_F(SortingBMFixture, InsertionSort)(benchmark::State& state) {
  for (auto _ : state) {
    vec = original;
    insertion_sort_int(vec.data(), vec.data() + vec.size(), greater_int);
    benchmark::DoNotOptimize(vec);
  }
}

BENCHMARK_DEFINE_F(SortingBMFixture, SelectionSort)(benchmark::State& state) {
  for (auto _ : state) {
    vec = original;
    selection_sort_int(vec.data(), vec.data() + vec.size(), greater_int);
    benchmark::DoNotOptimize(vec);
  }
}

BENCHMARK_DEFINE_F(SortingBMFixture, MergeSort)(benchmark::State& state) {
  for (auto _ : state) {
    vec = original;
    merge_sort_int(vec.data(), vec.data() + vec.size(), greater_int);
    benchmark::DoNotOptimize(vec);
  }
}

BENCHMARK_REGISTER_F(SortingBMFixture, BubbleSort)
  ->RangeMultiplier(2)->Range(1 << 10, 1 << 14);
BENCHMARK_REGISTER_F(SortingBMFixture, InsertionSort)
  ->RangeMultiplier(2)->Range(1 << 10, 1 << 14);
BENCHMARK_REGISTER_F(SortingBMFixture, SelectionSort)
  ->RangeMultiplier(2)->Range(1 << 10, 1 << 14);
BENCHMARK_REGISTER_F(SortingBMFixture, MergeSort)
  ->RangeMultiplier(2)->Range(1 << 10, 1 << 14);

BENCHMARK_MAIN();