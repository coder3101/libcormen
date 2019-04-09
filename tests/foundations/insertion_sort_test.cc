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

#include <array>
#include <cassert>
#include <iostream>
#include <libcormen/foundations/insertion_sort.hpp>
#include <vector>

int main() {
  std::vector<int> a{1, 5, 2, 0, 6, 8, 6};
  std::vector<int> exp{0, 1, 2, 5, 6, 6, 8};
  foundation::chapter_two::insertion_sort::apply(a);
  assert(exp == a);
  return 0;
}