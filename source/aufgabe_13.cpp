#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <vector>
#include <algorithm>


std::vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
std::vector <Circle> big_circles(circles.size());
auto is_bigger = [](Circle c) -> bool {return c.radius() > 4;};


TEST_CASE("Copy Circles with radius > 4.0f", "[bigger_radius]") {
  auto it = std::copy_if(circles.cbegin(),circles.cend(),big_circles.begin(),is_bigger);
  big_circles.resize(std::distance(big_circles.begin(), it));
  REQUIRE (std::all_of(big_circles.begin(), big_circles.end(), is_bigger));
}


int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}