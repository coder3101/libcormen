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
#include <libcormen/data_structures/linked_list.hpp>

int main() {
  using LL = data_structures::elementary::linked_list<int>;
  LL list;
  assert(list.head == nullptr);
  list.insert(45);
  assert(list.head != nullptr);
  list.remove(list.search(45));
  assert(list.head == nullptr);
  return 0;
}