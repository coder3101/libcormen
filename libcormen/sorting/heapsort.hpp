/**
 * Copyright 2019 Ashar <ashar786khan@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
#include <stdexcept>
#include <vector>
#include <limits>
namespace sorting {
namespace chapter_six {
template <class T>
struct heap {
  /*
  max-heap implementation
   */
  std::vector<T> container;
  long heap_size = 0;
  heap() = delete;
  explicit heap(long size) : container(size), heap_size(size) {}
  inline T &operator[](long index) { return container[index]; }
  inline long get_parent(long child) const { return (child + 1) / 2; }
  inline long get_left(long parent) const { return (parent * 2) + 1; }
  inline long get_right(long parent) const { return (parent * 2) + 2; }
  inline T heap_maximum() const { return container[0]; }
  auto heap_extract_max() {
    if (heap_size <= 0) throw std::logic_error("Heap Underflow");
    auto max = container[0];
    container[0] = container[heap_size - 1];
    heap_size--;
    max_heapify(0);
    return max;
  }
  void max_heapify(long point) {
    auto l = get_left(point);
    auto r = get_right(point);
    long largest;
    if (l <= heap_size - 1 && container[l] > container[point])
      largest = l;
    else
      largest = point;
    if (r <= heap_size - 1 && container[r] > container[largest]) largest = r;
    if (largest != point) {
      auto temp = container[point];
      container[point] = container[largest];
      container[largest] = temp;
      max_heapify(largest);
    }
  }
  void build_max_heap() {
    heap_size = container.size();
    for (long i = (container.size() - 1) / 2; i >= 0; i--) max_heapify(i);
  }
  void heap_increase_key(long i, T key) {
    if (key < container[i])
      throw std::logic_error("New key is smaller than current key");
    container[i] = key;
    while (i > 0 and container[get_parent(i)] < container[i]) {
      auto temp = container[i];
      container[i] = container[get_parent(i)];
      container[get_parent(i)] = temp;
      i = get_parent(i);
    }
  }
  void max_heap_insert(T key) {
    heap_size++;
    container.push_back(std::numeric_limits<T>::min());
    heap_increase_key(heap_size - 1, key);
  }
};
struct heap_sort {
  template <class T>
  static void apply(std::vector<T> &A) {
    heap<T> h(A.size());
    for (long t = 0; t < (long)A.size(); t++) h[t] = A[t];
    h.build_max_heap();
    for (long i = A.size() - 1; i > 0; i--) {
      T temp = h[0];
      h[0] = h[i];
      h[i] = temp;
      h.heap_size--;
      h.max_heapify(0);
    }
    for (long t = 0; t < (long)A.size(); t++) A[t] = h[t];
  }
};
}  // namespace chapter_six
}  // namespace sorting

#endif