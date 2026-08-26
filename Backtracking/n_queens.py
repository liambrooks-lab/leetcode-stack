class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        full_mask = (1 << n) - 1
        positions = []
        output = []

        def backtrack(cols, diag_left, diag_right):
            if cols == full_mask:
                board = []
                for c in positions:
                    board.append("." * c + "Q" + "." * (n - c - 1))
                output.append(board)
                return

            available = full_mask & ~(cols | diag_left | diag_right)

            while available:
                bit = available & -available
                available -= bit

                c = bit.bit_length() - 1
                positions.append(c)

                backtrack(
                    cols | bit,
                    ((diag_left | bit) << 1) & full_mask,
                    (diag_right | bit) >> 1,
                )

                positions.pop()

        backtrack(0, 0, 0)
        return output