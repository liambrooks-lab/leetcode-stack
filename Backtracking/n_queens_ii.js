/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let count = 0;
    const limit = (1 << n) - 1; // Creates a bitmask of 'n' 1s
    
    const backtrack = (cols, posDiag, negDiag) => {
        // Base case: All columns are filled
        if (cols === limit) {
            count++;
            return;
        }
        
        // Find all safe positions (1s in the binary representation)
        let availablePositions = limit & ~(cols | posDiag | negDiag);
        
        while (availablePositions > 0) {
            // Isolate the lowest set bit (first available safe spot)
            let pos = availablePositions & -availablePositions;
            
            // Remove this spot from available positions
            availablePositions &= availablePositions - 1;
            
            // Recurse to next row: OR the pos, and shift diagonals mathematically
            backtrack(cols | pos, (posDiag | pos) << 1, (negDiag | pos) >> 1);
        }
    };
    
    // Start with 0 constraints
    backtrack(0, 0, 0);
    return count;
};