"""
{
  "problem_name": "Image Overlap",
  "category": "Matrices",
  "time_complexity": "O(M * N)",
  "space_complexity": "O(M * N)"
}
"""

import numpy as np

class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        a = np.array(img1, dtype=np.int8)
        b = np.array(img2, dtype=np.int8)
        b = np.flip(b)

        n = len(img1)
        shape = (n * 2 - 1, n * 2 - 1)
        fa = np.fft.fft2(a, shape)
        fb = np.fft.fft2(b, shape)
        c = np.rint(np.fft.ifft2(fa * fb).real)

        return int(c.max())
