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
#include <libcormen/foundations/strassens_algorithm.hpp>
int main() {
  foundation::chapter_four::matrix<int> a{3, 3}, b{3, 3}, c{3, 3};
  long val = 0;
  for (int t = 0; t < 3; t++)
    for (int j = 0; j < 3; j++) {
      a.data[t][j] = val;
      b.data[t][j] = val;
      val++;
    }
  c.data[0][0] = 15;
  c.data[0][1] = 18;
  c.data[0][2] = 21;
  c.data[1][0] = 42;
  c.data[1][1] = 54;
  c.data[1][2] = 66;
  c.data[2][0] = 69;
  c.data[2][1] = 90;
  c.data[2][2] = 111;
  /*
  a = { 0,1,2
        3,4,5
        6,7,8 }
  b = { 0,1,2
        3,4,5
        6,7,8 }

  c = a * b;
  c = { 15, 18, 21
        42, 54, 66
        69, 90, 111 }
   */
  assert(a == b);
  auto result =
      foundation::chapter_four::strassens::square_matrix_multiply(a, b);
  assert(c == result);
  return 0;
}