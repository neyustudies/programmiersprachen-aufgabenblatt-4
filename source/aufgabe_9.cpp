#include <list>
#include <vector>
#include <iterator>
#include <iostream>

int main() {

  std::vector<unsigned int> vec(100);
  std::generate(vec.begin(), vec.end(), [] () {
    return rand() % 101;
  });

  std::list<unsigned int> list(vec.cend()-10, vec.cend());

  std::copy(vec.cend()-10, vec.cend(),
  std::ostream_iterator<unsigned int>(std::cout, " "));
  std::cout << "\n";

  std::copy(list.cbegin(), list.cend(),
  std::ostream_iterator<unsigned int>(std::cout, " "));
  std::cout << "\n";

  return 0;
}