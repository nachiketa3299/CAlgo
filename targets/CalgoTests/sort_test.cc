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
#include <calgo/quick_sort.h>

}

std::vector<std::vector<int>> sortingArrs = {
  { -10, 222, 54, 2555, 11 },
  { -18, -222, 52, 2555, 11 },
};

struct FixtureParam {
  FixtureParam(SortFunc_int const& func, Pred_int const& pred, std::vector<std::vector<int>> const& arrs): func(func), pred(pred), arrs(arrs) {}
  SortFunc_int const func;
  Pred_int const pred;
  std::vector<std::vector<int>> arrs;
};

class Fixture: public ::testing::TestWithParam<FixtureParam> {};

TEST_P(Fixture, SortsCorrectly) {
  auto p = GetParam();
  
  for (auto& arr: p.arrs) {
    std::vector<int> cp(arr);
    int *first = cp.data(), *last = first + cp.size();

    p.func(first, last, p.pred);
    ASSERT_TRUE(std::is_sorted(first, last, p.pred));
  }
}

INSTANTIATE_TEST_SUITE_P(BubbleSort_Greater, Fixture, ::testing::Values(FixtureParam(bubble_sort_int, greater_int, sortingArrs)));
INSTANTIATE_TEST_SUITE_P(BubbleSort_Less, Fixture, ::testing::Values(FixtureParam(bubble_sort_int, less_int, sortingArrs)));

INSTANTIATE_TEST_SUITE_P(InsertionSort_Greater, Fixture, ::testing::Values(FixtureParam(insertion_sort_int, greater_int, sortingArrs)));
INSTANTIATE_TEST_SUITE_P(InsertionSort_Less, Fixture, ::testing::Values(FixtureParam(insertion_sort_int, less_int, sortingArrs)));

INSTANTIATE_TEST_SUITE_P(SelectionSort_Greater, Fixture, ::testing::Values(FixtureParam(selection_sort_int, greater_int, sortingArrs)));
INSTANTIATE_TEST_SUITE_P(SelectionSort_Less, Fixture, ::testing::Values(FixtureParam(selection_sort_int, less_int, sortingArrs)));

INSTANTIATE_TEST_SUITE_P(MergeSort_Greater, Fixture, ::testing::Values(FixtureParam(merge_sort_int, greater_int, sortingArrs)));
INSTANTIATE_TEST_SUITE_P(MergeSort_Less, Fixture, ::testing::Values(FixtureParam(merge_sort_int, less_int, sortingArrs)));

INSTANTIATE_TEST_SUITE_P(QuickSort_Greater, Fixture, ::testing::Values(FixtureParam(quick_sort_int, greater_int, sortingArrs)));
INSTANTIATE_TEST_SUITE_P(QuickSort_Less, Fixture, ::testing::Values(FixtureParam(quick_sort_int, less_int, sortingArrs)));