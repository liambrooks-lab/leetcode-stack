from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
            
        res = []
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1
        
        while left <= right and top <= bottom:
            # Phase 1: Left to Right (Top row)
            for i in range(left, right + 1):
                res.append(matrix[top][i])
            top += 1
            
            # Phase 2: Top to Bottom (Right column)
            for i in range(top, bottom + 1):
                res.append(matrix[i][right])
            right -= 1
            
            if top <= bottom:
                # Phase 3: Right to Left (Bottom row)
                for i in range(right, left - 1, -1):
                    res.append(matrix[bottom][i])
                bottom -= 1
            
            if left <= right:
                # Phase 4: Bottom to Top (Left column)
                for i in range(bottom, top - 1, -1):
                    res.append(matrix[i][left])
                left += 1
                
        return res