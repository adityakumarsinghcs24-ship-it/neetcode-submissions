class Solution {
public:
    // int f(int ind,int cmp,vector<int>&nums,vector<vector<int>>&dp){
    //     if(ind==nums.size())return 0;
    //     if(dp[ind][cmp+1]!=-1)return dp[ind][cmp+1];
    //     int nottake=f(ind+1,cmp,nums,dp);
    //     int take=0;
    //     if(cmp==-1||nums[ind]>nums[cmp])take=1+f(ind+1,ind,nums,dp);
    //     return dp[ind][cmp+1]=max(take,nottake);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int comp=-1;
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n,-1));
    //     return f(0,comp,nums,dp);
    // }

    // Tabulation
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int cmp=-1;cmp<n;cmp++){
                int nottake=dp[ind+1][cmp+1];
                int take=0;
                if(cmp==-1||nums[ind]>nums[cmp])take=1+dp[ind+1][ind+1];
                dp[ind][cmp+1]=max(take,nottake);
            }
        }
        
        return dp[0][0];
    }

};