class Solution {
public:
    int f(int r,int c,vector<vector<int>>& matrix,int n, vector<vector<int>>&dp){
        if(r<0 || c<0 || r>=n || c>=n)return INT_MAX/2;
        if(r==0)return matrix[0][c];
        int check=matrix[r][c];
        if(dp[r][c]!=INT_MAX)return dp[r][c];
        check+=min(f(r-1,c-1,matrix,n,dp),min(f(r-1,c,matrix,n,dp),f(r-1,c+1,matrix,n,dp)));
        return dp[r][c]=check;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int check=f(n-1,i,matrix,n,dp);
            ans=min(ans,check);
        }
        return ans;
    }
};