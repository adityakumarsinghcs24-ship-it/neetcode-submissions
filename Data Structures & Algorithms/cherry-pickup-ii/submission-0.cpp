class Solution {
public:
    // (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    int f(int r,int c1,int c2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int m=grid[0].size();
        int n=grid.size();
        if(c1<0 || c1>=m ||c2<0 || c2>=m )return -1;
        if(r==n-1){
            if(c1==c2)return grid[r][c1];
            return grid[r][c1]+grid[r][c2]; 
        }
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        int cherry=-1e8;
        for(int j1=-1;j1<=1;j1++){
            for(int j2=-1;j2<=1;j2++){
                int value=0;
                if(c1==c2)value=grid[r][c1];
                else value=grid[r][c1]+grid[r][c2];
                value+=f(r+1,j1+c1,j2+c2,grid,dp);
                cherry=max(cherry,value);
            }
        }
        return dp[r][c1][c2]=cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0,m-1,grid,dp);
    }
};