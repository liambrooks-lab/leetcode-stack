class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        # Arrays of 9 integers initialized to 0. 
        # Each integer acts as a bitmask for a row, col, or box.
        rows = [0] * 9
        cols = [0] * 9
        boxes = [0] * 9
        
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    continue
                
                # Convert the digit string to an integer
                val = int(board[r][c])
                
                # Create a bitmask for this specific digit
                mask = 1 << val
                
                # Calculate which of the 9 boxes this cell belongs to
                box_idx = (r // 3) * 3 + (c // 3)
                
                # If the bit is already set in the respective row, col, or box, it's a duplicate!
                if (rows[r] & mask) or (cols[c] & mask) or (boxes[box_idx] & mask):
                    return False
                
                # Otherwise, set the bit to mark this digit as seen
                rows[r] |= mask
                cols[c] |= mask
                boxes[box_idx] |= mask
                
        return True