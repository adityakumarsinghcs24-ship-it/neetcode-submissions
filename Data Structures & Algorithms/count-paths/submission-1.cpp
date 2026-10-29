class Solution {
public:
    
    int f(int r,int c,vector<vector<int>>&dp){
        if(r==0 || c==0)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        return dp[r][c]= f(r-1,c,dp)+f(r,c-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};
