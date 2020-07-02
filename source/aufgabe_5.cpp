#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <list>
#include <algorithm>


  TEST_CASE("Sorting Circles", "[sort]") {
    
    std::list<Circle> sorted_circles;

    SECTION("radius of circles should be in correct order after sorting") {
      sorted_circles.push_back(Circle(Vec2{300, 300}, 30));
      sorted_circles.push_back(Circle(Vec2{400, 400}, 20));
      sorted_circles.push_back(Circle(Vec2{400, 400}, 40));
      REQUIRE_FALSE(std::is_sorted(sorted_circles.cbegin(), sorted_circles.cend()));
      sorted_circles.sort();
      REQUIRE(std::is_sorted(sorted_circles.cbegin(), sorted_circles.cend()));
      sorted_circles.push_back(Circle(Vec2{200, 200}, 10));
      sorted_circles.push_back(Circle(Vec2{100, 100}, 70));
      REQUIRE_FALSE(std::is_sorted(sorted_circles.cbegin(), sorted_circles.cend()));
      sorted_circles.sort();
      REQUIRE(std::is_sorted(sorted_circles.cbegin(), sorted_circles.cend()));
    }
  }


  int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
  }


