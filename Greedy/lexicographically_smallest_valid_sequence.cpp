class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        // canForm[j] = largest starting index p such that word2[j:] is a subsequence of word1[p:]
        // (computed via greedy backward matching, which uses rightmost occurrences)
        vector<int> canForm(m + 1, -1);
        canForm[m] = n;
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                canForm[j] = i;
                j--;
            }
        }
        
        vector<int> ans(m, -1);
        int pos = 0, jj = 0;
        bool usedMismatch = false;
        
        while (pos < n && jj < m) {
            if (word1[pos] == word2[jj]) {
                ans[jj] = pos;
                pos++; jj++;
            } else {
                // try using this position as our single allowed mismatch
                if (!usedMismatch && canForm[jj + 1] >= pos + 1) {
                    ans[jj] = pos;
                    pos++; jj++;
                    usedMismatch = true;
                } else {
                    pos++; // skip this word1 character
                }
            }
        }
        
        if (jj < m) return {};
        return ans;
    }
};