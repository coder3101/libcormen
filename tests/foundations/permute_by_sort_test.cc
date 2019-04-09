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
#include <libcormen/foundations/permute_by_sorting.hpp>
#include <vector>
#include <iostream>
int main(){
    std::vector<int> a{{1,2,3,4,5}};
    foundation::chapter_five::permute_by_sorting::apply(a);
    for(auto e : a) std::cout<<" "<<e;
    std::cout<<"\n";
    foundation::chapter_five::randomize_in_place::apply(a);
    for(auto e : a) std::cout<<" "<<e;
    std::cout<<"\n";
    return 0;
}