#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>


/* helper function */
bool is_multiple_of_3(unsigned int i) {return (i % 3) == 0;}

TEST_CASE("filter alle vielfache von drei", "[erase]") {
  std::srand((int)time(0));
  std::vector<unsigned int> v(100);
  std::generate(v.begin(), v.end(), []() -> bool {return rand() % 101;});

  /* removes all elements which are not multiples of 3 */
  v.erase(std::remove_if(v.begin(), v.end(), [](unsigned int i) {
    return !is_multiple_of_3(i);}), v.end());

  REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main(int argc, char* argv[]) {
  return Catch::Session().run(argc, argv);
}

