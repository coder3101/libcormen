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

#include <cassert>
#include <libcormen/sorting/quicksort.hpp>
#include <vector>

int main() {
  std::vector<int> a{1, 5, 2, 0, 6, 8, 6};
  std::vector<int> exp{0, 1, 2, 5, 6, 6, 8};
  std::vector<int> b{5};
  std::vector<int> exp_b{5};
  std::vector<int> c{3, 2, 0, 1};
  std::vector<int> exp_c{0, 1, 2, 3};
  sorting::chapter_seven::random_quicksort::apply(a);
  sorting::chapter_seven::random_quicksort::apply(b);
  sorting::chapter_seven::random_quicksort::apply(c);
  assert(exp == a);
  assert(exp_b == b);
  assert(exp_c == c);
  return 0;
}