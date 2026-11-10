class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int i=n;
        int j=m;
        string lcs="";
        for(int x=0;x<dp[n][m];x++){
            lcs+="$";
        }
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                lcs[dp[i][j]-1]=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
        string ans="";
        i=0,j=0;
        int k=0;
        while(i<n&& j<m && k<lcs.size()){
            int st1=i;
            int st2=j;
            while(str1[i]!=lcs[k] && i<n)i++;
            while(str2[j]!=lcs[k]&& j<m)j++;
            
            ans+=str1.substr(st1,i-st1);
            ans+=str2.substr(st2,j-st2);
            ans+=lcs[k];
            k++;
            i++;
            j++;
        }
        while(i<n){
            ans+=str1[i++];
            
        }
        while(j<m)ans+=str2[j++];
        return ans;
    }
};