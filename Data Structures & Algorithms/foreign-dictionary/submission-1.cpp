class Solution {
public:
    /*
    1. for 1st string make all letters as node 
    2. from 2nd word onwords compare prev word with current word each char, 
        if same move ahead else prev word letter ->current word letter (directed node)
        if same only we didnt created any directed edge then retunrn ""
    4. if word.size()==1 return word[0]    
    
    */
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        vector<vector<int>>adj(26);
        vector<bool>check(26,false);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                check[words[i][j]-'a']=true;
            }
        }
        for(int i=0;i<26;i++)if(check[i])count++;
        int i=1;
        while(i<n){
            int j=0;
            int flag=0;
            while(j<words[i].size() && j<words[i-1].size()){
                
                if(words[i-1][j]!=words[i][j]){
                    adj[words[i-1][j]-'a'].push_back(words[i][j]-'a');
                    flag=1;
                    break;
                }
                j++;
            }
            if(flag==0 && (words[i].size()<words[i-1].size()))return "";
            i++;
        }
        vector<int>indegree(26,0);
        for(i=0;i<26;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(i=0;i<26;i++){
            if(indegree[i]==0 && check[i])q.push(i);
        }
        string ans="";
        while(!q.empty()){
            int x=q.front();
            q.pop();
            char node=x+'a';
            ans+=node;
            for(auto it:adj[x]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(ans.size()!=count)return "";
        return ans;
    }
};
