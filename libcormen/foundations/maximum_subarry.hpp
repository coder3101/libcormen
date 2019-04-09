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

#ifndef MAXIMUM_SUBARRAY_HPP
#define MAXIMUM_SUBARRAY_HPP
#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

namespace foundation {
namespace chapter_four {
struct max_sub_array {
  template <class T>
  std::tuple<long, long, T> find_max_crossing_subarray(std::vector<T> &A,
                                                       long low, long mid,
                                                       long high) {
    auto left_sum = std::numeric_limits<T>::min();
    T sum = 0;
    long max_left;
    for (long i = mid; i >= low; i--) {
      sum += A[i];
      if (sum > left_sum) {
        left_sum = sum;
        max_left = i;
      }
    }
    auto right_sum = std::numeric_limits<T>::min();
    sum = 0;
    long max_right;
    for (long j = mid + 1; j <= high; j++) {
      sum += A[j];
      if (sum > right_sum) {
        right_sum = sum;
        max_right = j;
      }
    }
    return std::make_tuple(max_left, max_right, left_sum + right_sum);
  }

  template <class T>
  static std::tuple<long, long, T> apply(std::vector<T> &A, long low,
                                         long high) {
    if (high == low)
      return std::make_tuple(low, high, A[low]);
    else {
      max_sub_array obj;
      long mid = (low + high) / 2;
      auto left = apply(A, low, mid);
      auto right = apply(A, mid + 1, high);
      auto cross = obj.find_max_crossing_subarray(A, low, mid, high);
      if (std::get<2>(left) >= std::get<2>(right) &&
          std::get<2>(left) >= std::get<2>(cross))
        return left;
      else if (std::get<2>(right) >= std::get<2>(left) &&
               std::get<2>(right) >= std::get<2>(cross))
        return right;
      else
        return cross;
    }
  }
};

}  // namespace chapter_four
}  // namespace foundation
#endif