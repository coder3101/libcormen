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

#ifndef STRASSENS_ALGORITHM
#define STRASSENS_ALGORITHM
#include <iostream>
#include <stdexcept>
#include <vector>

namespace foundation {
namespace chapter_four {
template <class T>
struct matrix {
  long rows;
  long columns;
  std::vector<std::vector<T>> data;
  matrix() = delete;
  matrix(long r, long c) : rows(r), columns(c), data(r, std::vector<T>(c)) {}
  bool operator==(const matrix<T> &other) const {
    if (other.rows != this->rows || other.columns != this->columns)
      return false;
    else {
      for (long t = 0; t < this->rows; t++)
        for (long k = 0; k < this->columns; k++)
          if (other.data[t][k] != this->data[t][k]) return false;
      return true;
    }
  }
};
struct strassens {
  template <class T>
  static matrix<T> square_matrix_multiply(const matrix<T> &a,
                                          const matrix<T> &b) {
    auto n = a.rows;
    matrix<T> c{n, n};
    for (long i = 0; i < n; i++)
      for (long j = 0; j < n; j++) {
        c.data[i][j] = 0;
        for (long k = 0; k < n; k++)
          c.data[i][j] += a.data[i][k] * b.data[k][j];
      }
    return c;
  }
  template <class T>
  static matrix<T> apply(const matrix<T> &a, const matrix<T> &b) {
    //     if (a.rows != b.rows && a.columns != b.columns)
    //       throw std::logic_error("must be square matrices");
    /*
     * @todo Implement Strassen's Algorithm
     * @body It is very generic and requires much validation.
     * @body Such as power of 2 and furthur more. Contributions welcome on this.
     *
     * */
  }
};
}  // namespace chapter_four
}  // namespace foundation
#endif