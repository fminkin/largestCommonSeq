#pragma once
#include "lcs.hpp"
#include <random>
#include <algorithm>

default_random_engine generator;
std::uniform_int_distribution<char> distribution('a', 'z');
string generate_string(size_t size) {
  
    string result = "";
    
    for (size_t i = 0; i < size; ++i) {
	result += distribution(generator);
    }
    return result;
}

bool LCS_test(size_t main_string_size, size_t sub_string_size, size_t testSize) {
  
    string main_string = generate_string(main_string_size);
    string sub_string = generate_string(sub_string_size);
    int i = 0;
    sort(sub_string.begin(), sub_string.end());
    bool flag = true;
    
    do {
      
      flag &= get_lcs_square(main_string, sub_string) == get_lcs_cube(main_string, sub_string);
      i++;
    } while (i < testSize && next_permutation(sub_string.begin(), sub_string.end()));
    
    return flag;
}

