import sys
import os
from typing import List
import builtins
builtins.List = List

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '../..')))
from Hashing.two_sum import Solution

def run_tests():
    sol = Solution()
    assert sol.twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert sol.twoSum([3, 2, 4], 6) == [1, 2]
    assert sol.twoSum([3, 3], 6) == [0, 1]
    print("test_two_sum.py passed")

if __name__ == "__main__":
    run_tests()
