class Solution {
public:
    // MEMOIZATION
    // int f(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
    //     if(ind==prices.size())return 0;
    //     int profit=0;
    //     if(dp[ind][buy]!=-1)return dp[ind][buy];
    //     if(buy){
    //         profit=max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[ind]+f(ind+1,1,prices,dp),f(ind+1,0,prices,dp));
    //     }
    //     return dp[ind][buy]=profit;
    // }

    // TABULATION
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        int profit=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
            
        }
        return profit;
    }

    // SPACE OPT
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<int>ahead(2,0),curr(2,0);
    //     ahead[0]=0;
    //     ahead[1]=0;
        
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=0;j<=1;j++){
    //             int profit=0;
    //             if(j==1){
    //                 profit=max(-prices[i]+ahead[0],ahead[1]);
    //             }
    //             else{
    //                 profit=max(prices[i]+ahead[1],ahead[0]);
    //             }
    //             curr[j]=profit;
    //         }
    //         ahead=curr;
    //     }
    //     return ahead[1];
    // }
};