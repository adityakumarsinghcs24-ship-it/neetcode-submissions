class Solution {
public:
    int f(int ind,int amt,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(amt%coins[0]==0 )return 1;
            return 0;
        }
        if(dp[ind][amt]!=-1)return dp[ind][amt];
        if(amt==0)return 1;
        int notpick=f(ind-1,amt,coins,dp);
        int pick=0;
        if(coins[ind]<=amt)pick=f(ind,amt-coins[ind],coins,dp);
        return dp[ind][amt]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};
