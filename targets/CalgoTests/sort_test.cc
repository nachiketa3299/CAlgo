#include <vector>
#include <algorithm>
#include <random>
#include <limits>

#include <gtest/gtest.h>

extern "C" {

#include <calgo/predicates.h>
#include <calgo/sort.h>

#include <calgo/bubble_sort.h>
#include <calgo/insertion_sort.h>
#include <calgo/selection_sort.h>
#include <calgo/merge_sort.h>

}

struct StaticSortingParams {
  SortFunc_int sort;
  Pred_int pred;
  std::vector<int> arr;
};

StaticSortingParams staticTCs[] = {
  { bubble_sort_int, greater_int, { -10, 222, 54, 2555, 11 } },
  { bubble_sort_int, greater_int, { -10, 222, 54, 2555, 11 } },
  { bubble_sort_int, less_int, { -10, 222, 54, 2555, 11 } },
  { bubble_sort_int, less_int, { -10, 222, 54, 2555, 11 } },
};

class StaticSortingTestFixture: public ::testing::TestWithParam<StaticSortingParams> {};

TEST_P(StaticSortingTestFixture, SortsCorrectly) {
  StaticSortingParams params = GetParam();

  std::vector<int> sorted(params.arr.size());
  std::copy(params.arr.cbegin(), params.arr.cend(), sorted.begin());

  int *first = sorted.data();
  int *last = first + sorted.size();

  bubble_sort_int(first, last, params.pred);
  ASSERT_TRUE(std::is_sorted(first, last, params.pred));
}

INSTANTIATE_TEST_SUITE_P(
  SortingTests,
  StaticSortingTestFixture,
  ::testing::ValuesIn(staticTCs)
);

struct RandomSortingParams {
  SortFunc_int sort;
  Pred_int pred;

  size_t arr_size;

  int value_min;
  int value_max;
};

RandomSortingParams randomTCs[] = {
  { bubble_sort_int, greater_int, 100, std::numeric_limits<int>::min(), std::numeric_limits<int>::max() }, 
  { bubble_sort_int, less_int, 100, std::numeric_limits<int>::min(), std::numeric_limits<int>::max() }, 
};

class RandomSortingFixture: public ::testing::TestWithParam<RandomSortingParams>{ };

TEST_P(RandomSortingFixture, SortsCorrectly) {

  auto const& params = GetParam();

  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> val_dis(params.value_min, params.value_max);
  std::vector<int> origin(params.arr_size);
  for (auto& e: origin) { e = val_dis(gen); }

  int *first = origin.data();
  int *last = first + params.arr_size;

  sort(params.sort, first, last, params.pred);

  ASSERT_TRUE(std::is_sorted(first, last, params.pred));
}

INSTANTIATE_TEST_SUITE_P(
  RandomSortingTests,
  RandomSortingFixture,
  ::testing::ValuesIn(randomTCs)
);

