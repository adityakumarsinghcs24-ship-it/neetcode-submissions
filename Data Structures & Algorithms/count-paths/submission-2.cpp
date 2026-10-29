class Solution {
public:
    
    // int f(int r,int c,vector<vector<int>>&dp){
    //     if(r==0 || c==0)return 1;
    //     if(dp[r][c]!=-1)return dp[r][c];
    //     return dp[r][c]= f(r-1,c,dp)+f(r,c-1,dp);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
            
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1)dp[i][j]=dp[i][j-1]+dp[i-1][j];
                
            }
        }
        return dp[m-1][n-1];
    }
};
