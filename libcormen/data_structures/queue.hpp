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
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stddef.h>
#include <vector>

namespace data_structures {
namespace elementary {
template <class T, size_t LEN = 1000>
struct vector_queue {
  std::vector<T> Q{LEN};
  long tail = 0;
  long head = 0;
  void enqueue(T elem) {
    Q[tail] = elem;
    if (tail == LEN)
      tail = 0;
    else
      tail++;
  }
  T dequeue() {
    auto elem = Q[head];
    if (head == LEN)
      head = 0;
    else
      head++;
    return elem;
  }
};
}  // namespace elementary
}  // namespace data_structures
#endif