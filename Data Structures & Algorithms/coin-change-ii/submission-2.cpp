class Solution {
public:
    // int f(int ind,int amt,vector<int>&coins,vector<vector<int>>&dp){
    //     if(ind==0){
    //         if(amt%coins[0]==0 )return 1;
    //         return 0;
    //     }
    //     if(dp[ind][amt]!=-1)return dp[ind][amt];
    //     if(amt==0)return 1;
    //     int notpick=f(ind-1,amt,coins,dp);
    //     int pick=0;
    //     if(coins[ind]<=amt)pick=f(ind,amt-coins[ind],coins,dp);
    //     return dp[ind][amt]=pick+notpick;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    //     return f(n-1,amount,coins,dp);
    // }

    // Tabulation
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
        }
        for(int i=0;i<n;i++)dp[i][0]=1;
        for(int ind=1;ind<n;ind++){
            for(int amt=1;amt<=amount;amt++){
                int notpick=dp[ind-1][amt];
                int pick=0;
                if(coins[ind]<=amt)pick=dp[ind][amt-coins[ind]];
                dp[ind][amt]=pick+notpick;
            }
        }
        return dp[n-1][amount];
    }
};
