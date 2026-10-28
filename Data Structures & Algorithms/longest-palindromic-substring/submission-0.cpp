class Solution {
public:
    int helper(int l,int r,string s,int n){
        while(l>=0&&r<n&&s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=0;
        int start=0;
        for(int i=0;i<n;i++){
            int olen=helper(i,i,s,n);
            int elen=helper(i,i+1,s,n);
            if(olen>maxLen){
                maxLen=olen;
                start=i-(maxLen-1)/2;
            }
            if(elen>maxLen){
                maxLen=elen;
                start=(i-(maxLen)/2)+1;
            }
        }
        return s.substr(start,maxLen);
    }
};
