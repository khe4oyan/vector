#ifndef _VECTOR_METHODS
#define _VECTOR_METHODS

template<typename T>
bool Vector<T>::in_size_range(size_t i) {
  if (i >= 0 && i <= this->_size) {
    return true;
  }
  return false;
}

template<typename T>
Vector<T>::Vector() {
  this->_cap = 0;
  this->_size = 0;
  this->_buf = nullptr;
}
template<typename T>
Vector<T>::Vector(const Vector& copy_vec) {
  this->_size = copy_vec._size;
  this->_cap = copy_vec._cap;
  this->_buf = new T[this->_cap];

  for (int i = 0; i < this->_cap; ++i) {
    _buf[i] = copy_vec[i];
  }
}
template<typename T>
Vector<T>::Vector(const Vector&& move_vec) {
  this->_size = move_vec._size;
  this->_cap = move_vec._cap;
  this->_buf = move_vec._buf;

  move_vec._buf = nullptr;
}
template<typename T>
Vector<T>::Vector(size_t cap) {
  this->_buf = new T[cap * 2];
  this->_size = cap;
  this->_cap = cap * 2;
}
template<typename T>
Vector<T>::Vector(size_t cap, T value) {
  this->_buf = new T[cap * 2];
  this->_cap = cap * 2;
  this->_size = cap;

  for (int i = 0; i < cap; ++i) {
    this->_buf[i] = value;
  }
}
template<typename T>
Vector<T>::Vector(std::initializer_list<T> list) {
  this->_size = list.size();
  this->_cap = _size * 2;
  this->_buf = new T[_cap];

  int index = 0;
  for (auto& i : list) {
    _buf[index++] = i;
  }
}

//operators
template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>& other) {
  this->_size = other._size;
  this->_cap = other._cap;
  this->_buf = new T[this->_cap];

  for (int i = 0; i < this->_cap; ++i) {
    _buf[i] = other[i];
  }

  return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
  this->_size = other._size;
  this->_cap = other._cap;
  this->_buf = other._buf;

  other._buf = nullptr;

  return *this;
}

template<typename T>
T& Vector<T>::operator[](const size_t i) {
  if (!(this->in_size_range(i))) {
    std::cout << "Index not found";
    exit(0);
  }

  return _buf[i];
}

//methods
template<typename T>
void Vector<T>::clear() {
  delete[] _buf;
  _buf = nullptr;
  _size = 0;
  _cap = 0;
}

template<typename T>
void Vector<T>::erase(const size_t index) {
  this->_size = index + 1;
}

template<typename T>
bool Vector<T>::empty() {
  return this->_size ? false : true;
}

template<typename T>
int Vector<T>::size() {
  return this->_size;
}

template<typename T>
int Vector<T>::capacity() {
  return this->_cap;
}

template<typename T>
T& Vector<T>::at(size_t i) {
  if (in_size_range(i)) {
    return this->_buf[i];
  }
}

template<typename T>
void Vector<T>::shirn_to_fit() {
  this->_cap = this->_size;
  T* new_buf = new T[this->_size];

  for (int i = 0; i < this->_size; ++i) {
    new_buf[i] = this->_buf[i];
  }

  delete[] this->_buf;
  this->_buf = new_buf;
  new_buf = nullptr;
}

template<typename T>
void Vector<T>::insert(size_t position, T value) {
  if (!in_size_range(position)) {
    std::cout << "It isn't vector range";
    exit(0);
  }

  if (this->_size + 1 > this->_cap) {
    this->_cap *= 2;
    T* new_buf = new T[_cap];

    for (int i = 0; i < this->_size; ++i) {
      new_buf[i] = this->_buf[i];
    }

    delete[] this->_buf;
    this->_buf = new_buf;
    new_buf = nullptr;
  }

  T tmp = this->_buf[position];
  this->_buf[position] = value;

  this->_size++;
  for (int i = position + 1; i < this->_size; i++) {
    T tmp_2 = this->_buf[i];
    this->_buf[i] = tmp;
    tmp = tmp_2;
  }
}

template<typename T>
void Vector<T>::push_back(T value) {
  if (this->_size + 1 <= this->_cap) {
    this->_size++;
    this->_buf[this->_size - 1] = value;
    return;
  }

  this->_cap *= 2;
  T* new_buf = new T[_cap];

  for (int i = 0; i < this->_size; ++i) {
    new_buf[i] = this->_buf[i];
  }

  new_buf[this->_size - 1] = value;
  this->_size++;

  delete[] this->_buf;
  this->_buf = new_buf;
  new_buf = nullptr;
}

template<typename T>
void Vector<T>::pop_back() {
  if (this->_size == 0) {
    return;
  }

  this->_size--;
}

#endif