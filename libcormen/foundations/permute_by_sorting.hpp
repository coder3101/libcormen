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
#ifndef PERMUTE_BY_SORTING
#define PERMUTE_BY_SORTING
#include <algorithm>
#include <map>
#include <random>
#include <vector>
namespace foundation {
namespace chapter_five {
struct permute_by_sorting {
  template <class T>
  static void apply(std::vector<T>& A) {
    long n = A.size();
    long m = n * n * n;

    std::mt19937 engine;
    engine.seed(std::random_device()());
    std::uniform_int_distribution<long> dis(0, m - 1);

    std::vector<T> p(A.size());
    std::vector<T> a_copy(A);
    std::vector<std::pair<long, long>> bundle;

    for (long i = 0; i < n; i++) {
      p[i] = dis(engine);
      bundle.push_back(std::make_pair(i, p[i]));
    }
    std::sort(
        bundle.begin(), bundle.end(),
        [](const std::pair<long, long>& a, const std::pair<long, long>& b) {
          return a.second < b.second;
        });
    for (long ap = 0; ap < n; ap++) A[ap] = a_copy[bundle[ap].first];
  }
};
struct randomize_in_place {
  template <class T>
  static void apply(std::vector<T>& A) {
    std::mt19937 engine;
    engine.seed(std::random_device()());
    long n = A.size();
    for (long i = 0; i < n; i++) {
      T temp;
      temp = A[i];
      std::uniform_int_distribution<long> dis(i, n - 1);
      auto index = dis(engine);
      A[i] = A[index];
      A[index] = temp;
    }
  }
};
}  // namespace chapter_five
}  // namespace foundation
#endif