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

#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

#include <random>
#include <vector>
#define END (-1)

namespace sorting {
namespace chapter_seven {
struct quicksort {
  template <class T>
  static long partition(std::vector<T>& A, long p, long r) {
    auto x = A[r];
    long i = p - 1;
    for (long j = p; j < r; j++)
      if (A[j] <= x) {
        i++;
        auto temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
    auto temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 1;
  }
  template <class T>
  static void apply(std::vector<T>& A, long start = 0, long stop = END) {
    if (stop == END) stop = A.size() - 1;
    if (start < stop) {
      auto q = partition(A, start, stop);
      apply(A, start, q - 1);
      apply(A, q + 1, stop);
    }
  }
};

struct random_quicksort {
  template <class T>
  static void apply(std::vector<T>& A, long start = 0, long stop = END) {
    std::mt19937 engine;
    engine.seed(std::random_device()());
    std::uniform_int_distribution<long> dis(start,
                                            stop == END ? A.size() - 1 : stop);
    long index = dis(engine);
    auto temp = A[stop == END ? A.size() - 1 : stop];
    A[stop == END ? A.size() - 1 : stop] = A[index];
    A[index] = temp;
    quicksort::apply(A, start, stop);
  }
};
}  // namespace chapter_seven
}  // namespace sorting
#endif