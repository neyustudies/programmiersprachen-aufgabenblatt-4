#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <vector>
#include <list>
#include <set>


bool is_even(int n) {return n % 2 == 0;}

template<typename T, typename P>
T filter(T const& container, P const& predicate) {
  T even;
  std::copy_if(container.cbegin(), container.cend(), 
  std::inserter(even, even.begin()), predicate);
  return even;
}


TEST_CASE("should return even numbers (given vector)", "[vector]") {
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::vector<int> all_even = filter(v, is_even);
  REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));
}


TEST_CASE("should return even numbers (random)", "[random]") {
  std::srand((int)time(0));
  std::vector<int> v(100);
  std::generate(v.begin(), v.end(), []() -> bool {return rand() % 101;});
  
  SECTION("random std::vector") {
    std::vector<int> all_even_v = filter(v, is_even);
    REQUIRE(std::all_of(all_even_v.begin(), all_even_v.end(), is_even));
  }
  
  SECTION("random std::set") {
    std::set<int> s(v.cbegin(), v.cend());
    std::set<int> all_even_s = filter(s, is_even);
    REQUIRE(std::all_of(all_even_s.begin(), all_even_s.end(), is_even));
  }
  
  SECTION("random std::list") {
    std::list<int> l(v.cbegin(), v.cend());
    std::list<int> all_even_l = filter(l, is_even);
    REQUIRE(std::all_of(all_even_l.begin(), all_even_l.end(), is_even));
  }
}


int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}

