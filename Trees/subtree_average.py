# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        # Returning strictly (subtree_sum, subtree_count, valid_nodes)
        def dfs(node):
            if not node:
                return 0, 0, 0
            
            ls, lc, lv = dfs(node.left)
            rs, rc, rv = dfs(node.right)
            
            curr_sum = ls + rs + node.val
            curr_count = lc + rc + 1
            
            # Pure functional return, zero external scope lookups
            is_valid = 1 if curr_sum // curr_count == node.val else 0
            
            return curr_sum, curr_count, lv + rv + is_valid
            
        # Extract only the valid_nodes count from the root's return tuple
        return dfs(root)[2]