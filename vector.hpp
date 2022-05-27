#ifndef _VECTOR
#define _VECTOR

template<typename T>
class Vector {
private:
  size_t _cap;
  size_t _size;
  T* _buf;

  bool in_size_range(size_t i);

public:
  //constructors
  Vector();
  Vector(const Vector& copy_vec);
  Vector(const Vector&& move_vec);
  Vector(size_t cap);
  Vector(size_t cap, T value);
  Vector(std::initializer_list<T> list);

  //operators
  Vector<T>& operator=(Vector<T>& other);
  Vector<T>& operator=(Vector<T>&& other);
  T& operator[](const size_t i);

  //methods
  void clear();
  void erase(const size_t index);
  bool empty();
  int size();
  int capacity();
  T& at(size_t i);
  void shirn_to_fit();
  void insert(size_t position, T value);
  void push_back(T value);
  void pop_back();

};

#include "vector_methods.hpp"

#endif