class Solution {
public:
    int helper(int l,int r, string s,int count){
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            count++;
            l--;
            r++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        
            for(int i=0;i<n;i++){
            int olen=helper(i,i,s,0);
            int elen=helper(i,i+1,s,0);
            count+=elen;
            count+=olen;
        }
        
        
        
        return count;
    }
};
