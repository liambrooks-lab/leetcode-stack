#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <climits>
#include <cctype>

using namespace std;

#include "../../Strings/string_to_integer_atoi.cpp"

void runTests() {
    Solution sol;
    assert(sol.myAtoi("42") == 42);
    assert(sol.myAtoi("   -42") == -42);
    assert(sol.myAtoi("4193 with words") == 4193);
    cout << "test_string_to_integer_atoi.cpp passed" << endl;
}

int main() {
    runTests();
    return 0;
}
