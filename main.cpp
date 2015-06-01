#include <iostream>
#include "tests.hpp"


int main() {
	int main_string_size, sub_string_size, test_size;
	cin >> main_string_size >> sub_string_size >> test_size;
	cout << (LCS_test(main_string_size, sub_string_size, test_size) ? "OK\n" : "WRONG\n");
	return 0;
}
