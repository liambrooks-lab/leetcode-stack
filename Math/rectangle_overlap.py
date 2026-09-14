class Solution:
    def isRectangleOverlap(self, rec1: list[int], rec2: list[int]) -> bool:
        # Strict 1D projection intersection across both X and Y axes
        # Overlap exists iff min(top_rights) > max(bottom_lefts) for both dimensions
        return (
            rec1[0] < rec2[2] and 
            rec2[0] < rec1[2] and 
            rec1[1] < rec2[3] and 
            rec2[1] < rec1[3]
        )