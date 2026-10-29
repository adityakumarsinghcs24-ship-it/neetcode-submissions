class Solution {
public:
    int f(int r,int c,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(r<0||c<0)return 0;
        if(obstacleGrid[r][c]==1)return 0;
        if(r==0 && c==0)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        return dp[r][c]= f(r-1,c,obstacleGrid,dp)+f(r,c-1,obstacleGrid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return f(m-1,n-1,obstacleGrid,dp);
    }
};