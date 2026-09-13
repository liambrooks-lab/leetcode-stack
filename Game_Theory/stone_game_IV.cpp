/*
{
  "problem_name": "Stone Game Iv",
  "category": "Game_Theory",
  "time_complexity": "O(N)",
  "space_complexity": "O(1)"
}
*/
class Solution {
    
int dp[100010];
bool rec(int n){

    if(n<0) return false;

    if(dp[n] != -1) return dp[n];

    bool ans = false;

    for(int i=1;i*i<=n;i++){
        if(rec(n-(i*i))==false){
            ans = true;
            break;
        }   
    }
    
    return dp[n] = ans;
}
public:
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};