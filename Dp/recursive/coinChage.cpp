/** https://leetcode.com/problems/coin-change/
 https://leetcode.com/submissions/detail/783124312/ : Creating all the combinations, gave TLE (but on paper Time complexity is O(n*m) and Space is O(n*m)
 https://leetcode.com/submissions/detail/783125702/ :Time complexity is O(n*m) and Space is O(n) //n being amount
 **/
class Solution {
public:
    unordered_map<int,int>dp;
    long long recur(vector<int>&coins, int amount){
        if(amount == 0) return 0;
        
        //if already calculated then return the ans
        if(dp.find(amount)!=dp.end()) {
            return dp[amount];
        }
        
        long long ans= INT_MAX;
        for(int a:coins){
            if(amount>=a) ans=min(ans,1+recur(coins,amount-a));
        }
        
        //save in dp
        dp[amount] =ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        long long ans = recur(coins,amount);
        if(ans>=INT_MAX){
            return -1;
        }
        return ans;
    }
};
