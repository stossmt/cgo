#pragma once

#include <cstring>
#include <string>

namespace ms {

template <typename T> class Vector {
private:
  class Iterator {
  public:
    Iterator(T *ptr) : ptr_(ptr) {}

    T &operator*() { return *ptr_; }

    T *operator->() { return ptr_; }

    Iterator &operator++() {
      ++ptr_;
      return *this;
    }

    Iterator operator++(int) {
      Iterator tmp = *this;
      ++ptr_;
      return tmp;
    }

    bool operator==(const Iterator &other) { return ptr_ == other.ptr_; }

    bool operator!=(const Iterator &other) { return !operator==(other); }

  private:
    T *ptr_;
  };

public:
  Vector() : size_(0), capacity_(1), data_(new T[capacity_]) {}

  explicit Vector(const std::string &str)
      : size_(0), capacity_(str.length()), data_(new T[capacity_]) {
    for (const auto &ch : str) {
      data_[size_++] = ch;
    }
  }

  Vector(const Vector<T> &other)
      : size_(other.size_), capacity_(other.capacity_),
        data_(new T[capacity_]) {
    std::memcpy(data_, other.data_, size_ * sizeof(T));
  }

  Vector(Vector<T> &&other) noexcept
      : size_(other.size_), capacity_(other.capacity_), data_(capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }

  Vector &operator=(const Vector<T> &other) {
    if (this != &other) {
      delete[] data_;
      data_ = new T[other.capacity_];
      size_ = other.size_;
      capacity_ = other.capacity_;
      std::memcpy(data_, other.data_, size_ * sizeof(T));
    }
    return *this;
  }

  Vector &operator=(Vector<T> &&other) noexcept {
    if (this != &other) {
      delete[] data_;
      data_ = other.data_;
      size_ = other.size_;
      capacity_ = other.capacity_;
      other.data_ = nullptr;
      other.size_ = 0;
      other.capacity_ = 0;
    }
    return *this;
  }

  Iterator begin() { return Iterator(data_); }
  Iterator end() { return Iterator(data_ + size_); }

  void push_back(const T &item) {
    if (size_ == capacity_) {
      size_t new_capacity = capacity_ * 2;
      T *new_data = new T[new_capacity];
      std::memcpy(new_data, data_, size_ * sizeof(T));
      delete[] data_;
      data_ = new_data;
      capacity_ = new_capacity;
    }
    data_[size_++] = item;
  }

  ~Vector() { delete[] data_; }

private:
  size_t size_;
  size_t capacity_;
  T *data_;
};

} // namespace ms