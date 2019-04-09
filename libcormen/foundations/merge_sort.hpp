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

#ifndef MERGE_SORT
#define MERGE_SORT

#include <iostream>
#include <limits>
#include <vector>
#define END (-1)

namespace foundation {
namespace chapter_two {
struct merge_sort {
  template <class T>
  void merge(std::vector<T> &A, long p, long q, long r) {
    auto n1 = q - p + 1;
    auto n2 = r - q;
    auto infinity = std::numeric_limits<T>::max();
    std::vector<T> L(n1 + 1), R(n1 + 1);
    for (long i = 0; i < n1; i++) L[i] = A[p + i];
    for (long i = 0; i < n2; i++) R[i] = A[q + i + 1];
    L[n1] = infinity;
    R[n2] = infinity;
    long i, j;
    i = j = 0;
    for (long k = p; k <= r; k++)
      if (L[i] <= R[j])
        A[k] = L[i++];
      else
        A[k] = R[j++];
  }

  template <class T>
  static void apply(std::vector<T> &A, long start = 0, long stop = END) {
    if (stop == END) stop = A.size() - 1;
    if (start < stop) {
      auto mid = start + stop;
      mid /= 2;
      apply(A, start, mid);
      apply(A, mid + 1, stop);
      merge_sort obj;
      obj.merge(A, start, mid, stop);
    }
  }
};

}  // namespace chapter_two
}  // namespace foundation

#endif