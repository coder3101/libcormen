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

#ifndef STACK_HPP
#define STACK_HPP

#include <stddef.h>
#include <stdexcept>
#include <vector>

namespace data_structures {
namespace elementary {
template <class T>
struct vector_stack {
  std::vector<T> S{};
  long top = 0;
  inline bool is_empty() const noexcept { return top == 0; }
  void push(T elem) {
    top++;
    S.push_back(elem);
  }
  auto pop() {
    if (is_empty()) throw std::logic_error("Stack Underflow");
    auto e = S.back();
    top--;
    S.pop_back();
    return e;
  }
};
}  // namespace elementary
}  // namespace data_structures
#endif