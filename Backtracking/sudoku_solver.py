"""
{
  "problem_name": "Sudoku Solver",
  "category": "Backtracking",
  "time_complexity": "O(2^N)",
  "space_complexity": "O(N)"
}
"""
class Solution:
    def solveSudoku(self, board: list[list[str]]) -> None:
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        empty_cells = []
        
        # O(1) bit set helper
        def place(r, c, val):
            mask = 1 << val
            box_idx = (r // 3) * 3 + (c // 3)
            rows[r] |= mask
            cols[c] |= mask
            boxes[box_idx] |= mask
            board[r][c] = str(val)

        # O(1) bit unset helper (Backtrack)
        def remove(r, c, val):
            mask = ~(1 << val)
            box_idx = (r // 3) * 3 + (c // 3)
            rows[r] &= mask
            cols[c] &= mask
            boxes[box_idx] &= mask
            board[r][c] = '.'

        # Initialize the state
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    empty_cells.append((r, c))
                else:
                    place(r, c, int(board[r][c]))

        # The Backtracking Engine
        def backtrack() -> bool:
            if not empty_cells:
                return True
            
            # The MRV Hack: Find the empty cell with the fewest possible valid digits
            best_cell_idx = -1
            min_possibilities = 10
            best_valid_mask = 0
            
            for i, (r, c) in enumerate(empty_cells):
                box_idx = (r // 3) * 3 + (c // 3)
                # Combine masks using OR, then invert to get available options
                used = rows[r] | cols[c] | boxes[box_idx]
                valid_mask = ~used & 0x3FE # 0x3FE is binary 1111111110 (covers bits 1-9)
                
                # Count set bits to find the number of valid options
                possibilities = valid_mask.bit_count()
                
                if possibilities < min_possibilities:
                    min_possibilities = possibilities
                    best_cell_idx = i
                    best_valid_mask = valid_mask
                    
                # If a cell has 0 or 1 possibilities, we don't need to search further
                if possibilities <= 1:
                    break
            
            # If a cell has no valid options, this path is a dead end
            if min_possibilities == 0:
                return False
                
            # Swap the chosen cell to the end for O(1) removal
            empty_cells[best_cell_idx], empty_cells[-1] = empty_cells[-1], empty_cells[best_cell_idx]
            r, c = empty_cells.pop()
            
            # Try all valid digits derived from the bitmask
            for val in range(1, 10):
                if (1 << val) & best_valid_mask:
                    place(r, c, val)
                    if backtrack():
                        return True
                    remove(r, c, val)
                    
            # Backtrack: Put the cell back if no digits worked
            empty_cells.append((r, c))
            return False

        backtrack()