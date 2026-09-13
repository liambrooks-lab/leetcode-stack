/*
{
  "problem_name": "Substring Concat Words",
  "category": "Sliding_Window",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
const findSubstring = function(s, words) {
    if (!s || words.length === 0) return [];

    const wordLen = words[0].length;
    const wordCount = words.length;
    const totalLen = wordLen * wordCount;
    const result = [];
    
    // Step 1: Create a frequency map for the required words
    const wordMap = new Map();
    for (let i = 0; i < wordCount; i++) {
        const word = words[i];
        wordMap.set(word, (wordMap.get(word) || 0) + 1);
    }
    
    // Step 2: Loop through possible offsets
    for (let i = 0; i < wordLen; i++) {
        let left = i;
        let right = i;
        let currentMap = new Map();
        let count = 0;
        
        // Step 3: Expand the sliding window
        while (right + wordLen <= s.length) {
            const word = s.slice(right, right + wordLen);
            right += wordLen;
            
            // Step 4: Validate the extracted word
            if (wordMap.has(word)) {
                currentMap.set(word, (currentMap.get(word) || 0) + 1);
                count++;
                
                // Shrink the window if a word appears more times than required
                while (currentMap.get(word) > wordMap.get(word)) {
                    const leftWord = s.slice(left, left + wordLen);
                    currentMap.set(leftWord, currentMap.get(leftWord) - 1);
                    count--;
                    left += wordLen;
                }
                
                // If we matched all words, record the starting index
                if (count === wordCount) {
                    result.push(left);
                }
            } else {
                // Invalid word breaks the sequence, reset everything
                currentMap.clear();
                count = 0;
                left = right;
            }
        }
    }
    
    return result;
};