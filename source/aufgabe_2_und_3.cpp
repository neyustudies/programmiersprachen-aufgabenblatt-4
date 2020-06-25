#include <vector>
#include <set>
#include <iostream>
#include <numeric>


int main() {

  /* vector of 100 random numbers between 0 and 100 using lambda */
  std::vector<unsigned int> rand_100(100);
  std::generate(rand_100.begin(), rand_100.end(), [] () {
    return rand() % 101;
  });

  /* vector of all possible values */
  std::vector<unsigned int> all_ints(101);
  std::iota(all_ints.begin(), all_ints.end(), 0);

  /* set of unique numbers in vector */
  std::set<unsigned int> unique_ints(rand_100.cbegin(), rand_100.cend());
  std::cout << "How many unique numbers: " << unique_ints.size();

  /*std::cout << "Numbers in vector:\n";
  for (auto elem : unique_ints)
    std::cout << elem << " ";
  std::cout << "\n\n"; */
 
  // set of numbers not in vector
  std::set<unsigned int> unknown_ints;
  std::set_difference(all_ints.cbegin(), all_ints.cend(),
                      unique_ints.cbegin(), unique_ints.cend(),  
                      std::inserter(unknown_ints, unknown_ints.cend()));


  // output of number values not in vector
  std::cout << "\n\nNumbers not in vector:\n";
  for(auto elem : unknown_ints) {
    std::cout << elem << " ";
  }

  return 0;
}

