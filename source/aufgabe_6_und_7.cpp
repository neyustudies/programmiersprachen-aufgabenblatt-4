#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <list>


TEST_CASE("Sorting Circles with Lambda", "[sort_lambda]") {
    
  std::list<Circle> sorted_circles;

  SECTION("radius of circles should be in correct order after sorting") {
    sorted_circles.push_back(Circle(Vec2{300, 300}, 30));
    sorted_circles.push_back(Circle(Vec2{400, 400}, 20));
    sorted_circles.push_back(Circle(Vec2{400, 400}, 40));
    sorted_circles.push_back(Circle(Vec2{200, 200}, 10));
    sorted_circles.push_back(Circle(Vec2{100, 100}, 70));


    auto sorting_lambda = [] (Circle const& a, Circle const& b) -> bool {
      return (a.radius() < b.radius());
    };

    REQUIRE_FALSE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
    sorted_circles.sort(sorting_lambda);
    REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
    
  }
}


int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}


