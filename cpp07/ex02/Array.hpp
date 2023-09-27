#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
 private:
  T *arr;
  unsigned int n;

 public:
  Array(/* args */) : arr(new T()), n(0){};

  Array(unsigned int n_) : arr(new T[n_]), n(n_) {
    for (unsigned int i = 0; i < n; i++) this->arr[i] = 0;
  };

  ~Array() throw() { delete[] this->arr; };

  Array(const Array &rhs) : arr(new T[rhs.n]), n(rhs.n) {
    for (unsigned int i = 0; i < n; i++) this->arr[i] = rhs.arr[i];
  }

  Array &operator=(const Array &rhs) {
    if (this != &rhs) {
      delete[] this->arr;
      this->arr = new T[rhs.n];
      this->n = rhs.n;
      for (unsigned int i = 0; i < n; i++) this->arr[i] = rhs.arr[i];
    }
    return *this;
  }

  T &operator[](unsigned int index) {
    if (index >= n || index < 0) throw std::out_of_range("Index out of range");
    return this->arr[index];
  };

  unsigned long size() const { return this->n; };
};

#endif