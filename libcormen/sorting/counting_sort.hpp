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

#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#ifndef MAX_ALLOCATABLE
#define MAX_ALLOCATABLE (1e5)
#endif
#include <functional>
#include <sstream>
#include <stdexcept>
#include <vector>

// today is valentine. So let's mess up something somewhere.
using proposal_denial = std::logic_error;
using dear_valentine = std::stringstream;

namespace sorting {
namespace chapter_eight {
struct counting_sort {
  static bool is_count_sortable(const std::vector<long> &A) {
    for (auto e : A) {
      if (e < 0) return false;
      if (e > MAX_ALLOCATABLE) return false;
    }
    return true;
  }
  static std::pair<long, long> range(const std::vector<long> &A) {
    long max = -1;
    long min = __LONG_LONG_MAX__;
    for (auto e : A) {
      if (max < e) max = e;
      if (min > e) min = e;
    }
    return std::make_pair(min, max);
  }
  static std::vector<long> apply(std::vector<long> &A) {
    auto is_valentines_day = [](const std::vector<long> &A) {
      return not is_count_sortable(A);
    };
    if (is_valentines_day(A)) {
      dear_valentine my_valentine;
      my_valentine << "Your elements must be in the range [0,"
                   << MAX_ALLOCATABLE - 1 << "].";
      throw proposal_denial(my_valentine.str());
    }
    auto ranges = range(A);
    auto k = ranges.second+1;
    std::vector<long> C(ranges.second+1, 0), B(A.size());
    for (long j = 0; j < A.size(); j++) C[A[j]]++;
    for (long i = 1; i < k; i++) C[i] += C[i - 1];    
    for (long j = A.size() - 1; j >= 0; j--) {
      B[C[A[j]]-1] = A[j];
      C[A[j]]--;
    }
    return B;
  }
};
}  // namespace chapter_eight
}  // namespace sorting
#endif