class Solution {
public:
    int f(int ind, int amt, vector<int>&coins,vector<vector<int>>&dp){
        if(dp[ind][amt]!=-1)return dp[ind][amt];
        if(ind==0){
            if(amt==coins[0])return 1;
            if(amt%coins[0]==0)return amt/coins[0];
            return 1e8;
        }
        if(amt==0)return 0;
        int nottake=f(ind-1,amt,coins,dp);
        int take=1e8;
        if(coins[ind]<=amt)take=1+f(ind,amt-coins[ind],coins,dp);
        return dp[ind][amt]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0)return 0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,coins,dp);
        if(ans==1e8)return -1;
        return ans;
    }
};