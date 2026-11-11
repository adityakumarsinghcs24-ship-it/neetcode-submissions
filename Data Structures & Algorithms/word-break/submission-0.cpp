
class Solution {
public:
    bool f(int ind, const string& s, vector<string>& dict,
           vector<int>& dp) {
        if(ind == s.size()) return true;
        if(dp[ind] != -1) return dp[ind];
        for(int i = 0; i < dict.size(); i++) {
            int len = dict[i].size();
            if(s.substr(ind, len) == dict[i]) {
                if(f(ind + len, s, dict, dp))
                    return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, wordDict, dp);
    }
};
