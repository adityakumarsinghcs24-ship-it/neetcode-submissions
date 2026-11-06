class Solution {
public:
    int f(int ind,int tar,vector<int>&nums,vector<vector<int>>&dp,int sum){
        if(tar<-sum||tar>sum)return 0;
        if(dp[ind][tar+sum]!=-1)return dp[ind][tar+sum];
        if( ind==0){
            if(tar==0&& nums[ind]==0)return 2;
            if(tar+nums[ind]==0)return 1;
            if(tar-nums[ind]==0)return 1;
            return 0;
        }
        int add=f(ind-1,tar+nums[ind],nums,dp,sum);
        int sub=f(ind-1,tar-nums[ind],nums,dp,sum);
        return dp[ind][tar+sum]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*sum+1,-1));
        return f(n-1,target,nums,dp,sum);
    }
};