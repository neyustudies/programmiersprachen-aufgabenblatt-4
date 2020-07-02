#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <vector>
#include <algorithm>


std::vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
std::vector <Circle> large_circles(circles.size());
auto is_larger = [](Circle c) -> bool {return c.radius() > 4.0f;};


TEST_CASE("Copy Circles with radius > 4.0f", "[larger_radius]") {
  auto it = std::copy_if(circles.cbegin(), circles.cend(), large_circles.begin(), is_larger);
  large_circles.resize(std::distance(large_circles.begin(), it));
  REQUIRE (std::all_of(large_circles.begin(), large_circles.end(), is_larger));
}


int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}

