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
#include <libcormen/data_structures/queue.hpp>
#include <libcormen/data_structures/stack.hpp>

int main() {
  using Q = data_structures::elementary::vector_queue<int, 200>;
  using S = data_structures::elementary::vector_stack<int>;
  S s;
  Q q;
  assert(s.is_empty() == true);
  s.push(56);
  s.push(75);
  assert(s.is_empty() == false);
  assert(s.pop() == 75);
  s.pop();
  assert(s.is_empty() == true);
  q.enqueue(56);
  q.enqueue(75);
  assert(q.dequeue() == 56);
  assert(q.dequeue() == 75);
  return 0;
}