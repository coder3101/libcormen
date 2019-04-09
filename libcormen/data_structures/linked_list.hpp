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

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include <vector>

namespace data_structures {
namespace elementary {
template <class T>
struct node {
  node<T> *next = nullptr;
  node<T> *prev = nullptr;
  node() = default;
  T data;
};
template <class T>
struct linked_list {
  std::vector<node<T> *> ptrs;
  node<T> *head = nullptr;
  void insert(T val) {
    auto np = new node<T>();
    np->data = val;
    ptrs.push_back(np);  // save reference for delete in destructor
    np->next = head;
    if (head != nullptr) head->prev = np;
    head = np;
  }
  void remove(node<T> *x) {
    if (x->prev != nullptr)
      x->prev->next = x->next;
    else
      head = x->next;
    if (x->next != nullptr) x->next->prev = x->prev;
  }
  node<T> *search(T key) {
    auto iter = head;
    while (iter != nullptr and iter->data != key) iter = iter->next;
    return iter;
  }
  ~linked_list() {
    for (auto e : ptrs) delete e;
  }
};
}  // namespace elementary
}  // namespace data_structures

#endif