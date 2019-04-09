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
#include <libcormen/foundations/maximum_subarry.hpp>
#include <vector>
#include <tuple>
int main() {
  std::vector<int> a{
      {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}};
  auto result = std::make_tuple(7, 10, 18 + 20 + 12 - 7);
  auto output = foundation::chapter_four::max_sub_array::apply(a, 0, a.size()-1);
  assert(result == output);
  return 0;
}