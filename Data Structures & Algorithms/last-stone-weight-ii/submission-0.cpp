class Solution {
public:
    
    // int lastStoneWeightII(vector<int>& stones) {
    //     int n=stones.size();
    //     if(n==1)return stones[0];
    //     int sum=accumulate(stones.begin(),stones.end(),0);
    //     int target=sum/2;
    //     vector<vector<int>>dp(n,vector<int>(target+1,0));
    //     for(int i=0;i<n;i++)dp[i][0]=1;
    //     dp[0][stones[0]]=1;
    //     for(int i=1;i<n;i++){
    //         for(int j=1;j<=target;j++){
    //             bool nottake=dp[i-1][j];
    //             bool take=0;
    //             if(stones[i]<=j)take=dp[i-1][j-stones[i]];
    //             dp[i][j]=take | nottake;
    //         }
    //     }
    //     int mini=1e8;
    //     for(int i=target;i>=0;i--){
    //         if(dp[n-1][i]){
    //             int s1=i;
    //             int s2=sum-s1;
    //             mini=min(mini, abs(s1-s2));
    //         }
    //     }
    //     return mini;
    // }


    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        if(n==1)return stones[0];
        int sum=accumulate(stones.begin(),stones.end(),0);
        int target=sum/2;
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);
        prev[0]=1;
        curr[0]=1;
        prev[stones[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool nottake=prev[j];
                bool take=0;
                if(stones[i]<=j)take=prev[j-stones[i]];
                curr[j]=take | nottake;
            }
            prev=curr;
        }
        int mini=1e8;
        for(int i=target;i>=0;i--){
            if(prev[i]){
                int s1=i;
                int s2=sum-s1;
                mini=min(mini, abs(s1-s2));
            }
        }
        return mini;
    }
};