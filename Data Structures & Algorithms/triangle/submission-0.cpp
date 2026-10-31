class Solution {
public:
    int f(int r,int c,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(r<c || r<0||c<0)return 100000;
        if(r==0&& c==0)return triangle[r][c];
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=0;
        int left=0;
        if(r>=0&& c>=0)left+=triangle[r][c]+f(r-1,c-1,triangle,dp);
        int right=0;
        if(r>=0)right+=f(r-1,c,triangle,dp)+triangle[r][c];
        ans+=min(left,right);
        return dp[r][c]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int mini=INT_MAX;
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--){
            mini=min(mini,f(n-1,i,triangle,dp));
        }
        return mini;
    }
};