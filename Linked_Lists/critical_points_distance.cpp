/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 #pragma GCC optimize("O3", "unroll-loops")
static const int __ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> idx;

        ListNode* prev = NULL;
        int currIdx = 0;
        while(head != NULL){
            if(prev == NULL || head->next == NULL){
                prev = head;
                head = head->next;
                continue;
            }

            if(head->val > prev->val && head->val > head->next->val) idx.push_back(currIdx);
            else if(head->val < prev->val && head->val < head->next->val) idx.push_back(currIdx);

            prev = head;
            head = head->next;
            currIdx++;
        }

        if(idx.size() == 0 || idx.size() == 1) return {-1, -1};

        int mini = INT_MAX, maxi = INT_MIN;
        maxi = idx[idx.size() - 1] - idx[0];
        for(int i = 1; i < idx.size(); i++){
            mini = min(mini, idx[i] - idx[i - 1]);
        }
        return {mini, maxi};
    }
};