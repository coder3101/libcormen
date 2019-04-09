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

#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <array>
#include <vector>

namespace foundation {
namespace chapter_two {
struct insertion_sort {
  template <class T>
  static void apply(std::vector<T> &elems) {
    for (size_t j = 1; j < elems.size(); j++) {
      auto key = elems[j];
      long i = j - 1;
      while (i >= 0 and elems[i] > key) {
        elems[i + 1] = elems[i];
        i--;
      }
      elems[i + 1] = key;
    }
  }
};
}  // namespace chapter_two
}  // namespace foundation

#endif