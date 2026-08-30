class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        # Pre-allocate the exact memory required for the n x n grid to prevent resizing overhead
        matrix = [[0] * n for _ in range(n)]
        
        top, bottom = 0, n - 1
        left, right = 0, n - 1
        val = 1
        
        while left <= right and top <= bottom:
            # Phase 1: Left to Right (Top boundary)
            for i in range(left, right + 1):
                matrix[top][i] = val
                val += 1
            top += 1
            
            # Phase 2: Top to Bottom (Right boundary)
            for i in range(top, bottom + 1):
                matrix[i][right] = val
                val += 1
            right -= 1
            
            # Phase 3: Right to Left (Bottom boundary)
            if top <= bottom:
                for i in range(right, left - 1, -1):
                    matrix[bottom][i] = val
                    val += 1
                bottom -= 1
            
            # Phase 4: Bottom to Top (Left boundary)
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    matrix[i][left] = val
                    val += 1
                left += 1
                
        return matrix