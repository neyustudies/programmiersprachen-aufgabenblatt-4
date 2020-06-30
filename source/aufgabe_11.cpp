#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector>
#include <algorithm>

std::vector<int> v_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> v_2{9, 8, 7, 6, 5, 4, 3, 2, 1};
std::vector<int> v_3(9);

TEST_CASE("add up two vectors, save result in another vector", "[transform]") {
  /* std::vector<>::const_iterator first1, last1, first2,
   * std::vector<>::iterator result, lambda []int (int a, int b)->int binary_op */
  std::transform(v_1.cbegin(), v_1.cend(), v_2.cbegin(), 
                 v_3.begin(), [](int a, int b) ->int {return a + b;});

  REQUIRE(std::all_of(v_3.cbegin(), v_3.cend(), [](int a) ->bool {return a == 10;}));
}

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}

