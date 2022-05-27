#include <iostream>
#include <initializer_list>
#include "vector.hpp"

template<typename T>
void show(T val) {
  /*
    Cout every type info in console
    ----
    Precondition:
      Get any type one variable;
    Postcondition:
      cout variable and set next pointer a new line
  */
  std::cout << val << std::endl;
}

int main(){
  // tests 

  Vector<int> vec{1,2,3,4,5,6};
  show(vec.size()); // 6
  show(vec.capacity()); // 12 (size * 2)
  
  vec.insert(2, 999);
  show(vec[2]); // show in dysplay 999

  vec.push_back(777);
  show(vec[vec.size() - 1]); // show in dysplay 777

  vec.pop_back();
  show(vec[vec.size() - 1]); // show in dysplay 6

  show(vec.capacity()); // 12
  vec.shirn_to_fit();
  show(vec.capacity()); // 7 (size)

  std::cout << std::boolalpha << vec.empty() << std::endl; // false
  Vector<int> vec_2;
  std::cout << std::boolalpha << vec_2.empty() << std::endl; // true

  vec.erase(2);
  show(vec.size()); // 3

  show(vec.size()); // 3
  vec.clear();
  show(vec.size()); // 0
}