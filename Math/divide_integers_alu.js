/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
const divide = function(dividend, divisor) {
    const MIN_INT = -2147483648;
    const MAX_INT = 2147483647;
    
    // Step 1: The overflow edge case killer
    if (dividend === MIN_INT && divisor === -1) {
        return MAX_INT;
    }
    
    // Step 2: Extract the sign
    const isNegative = (dividend < 0) !== (divisor < 0);
    
    // Convert both to positive numbers
    let num = Math.abs(dividend);
    let den = Math.abs(divisor);
    
    let quotient = 0;
    
    // Step 3 & 4: Exponential doubling and chunk subtraction
    while (num >= den) {
        let temp = den;
        let multiple = 1;
        
        // We use temp + temp instead of temp * 2 or temp << 1 to safely 
        // simulate multiplication and bypass JS 32-bit signed bitwise quirks
        while (num >= (temp + temp)) {
            temp += temp;
            multiple += multiple;
        }
        
        num -= temp;
        quotient += multiple;
    }
    
    // Step 5: Apply sign and return
    return isNegative ? -quotient : quotient;
};