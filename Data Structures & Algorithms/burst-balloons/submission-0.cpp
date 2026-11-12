class Solution {
public:
    // int f(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if (i > j) return 0;
    //     if(i==j)return arr[i-1]*arr[i]*arr[i+1];
    //     int maxi=-1e8;
    //     for(int k=i;k<=j;k++){
    //         int steps=arr[i-1]*arr[k]*arr[j+1]+f(i,k-1,arr,dp)+f(k+1,j,arr,dp);
    //         maxi=max(steps,maxi);
    //     }
    //     return dp[i][j]=maxi;
    // }
    // int maxCoins(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    //     vector<int>arr(n+2);
    //     for(int i=0;i<n;i++)arr[i+1]=nums[i];
    //     arr[0]=1;
    //     arr[n+1]=1;
    //     return f(1,n,arr,dp);
    // }

    // Tabulation

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        vector<int>arr(n+2);
        for(int i=0;i<n;i++)arr[i+1]=nums[i];
        arr[0]=1;
        arr[n+1]=1;
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                 int maxi=-1e8;
                for(int k=i;k<=j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(steps,maxi);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};