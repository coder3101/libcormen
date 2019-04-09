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
#include <iostream>
#include <libcormen/sorting/counting_sort.hpp>
#include <vector>

int main() {
  std::vector<long> a{2, 5, 3, 0, 2, 3, 0, 3};
  std::vector<long> exp{0, 0, 2, 2, 3, 3, 3, 5};
  std::vector<long> b{5};
  std::vector<long> exp_b{5};
  std::vector<long> c{3, 2, 0, 1, 8, 9};
  std::vector<long> exp_c{0, 1, 2, 3, 8, 9};
  a = sorting::chapter_eight::counting_sort::apply(a);
  b = sorting::chapter_eight::counting_sort::apply(b);
  c = sorting::chapter_eight::counting_sort::apply(c);
  assert(exp == a);
  assert(exp_b == b);
  assert(exp_c == c);

  return 0;
}