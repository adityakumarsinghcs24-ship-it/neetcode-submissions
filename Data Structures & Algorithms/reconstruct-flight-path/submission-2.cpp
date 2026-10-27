class Solution {
public:
    /*
        1.Create adj list with node to its destinations and make it sorted lexi order
        2. traverse list and add node to ans and remove that connection 
        3.return ans
    */
    void dfs(unordered_map<string,vector<string>>&adj,vector<string>&ans,string candid){
        
        while(adj.find(candid)!=adj.end() && !adj[candid].empty()){
            string next =adj[candid].back();
            adj[candid].pop_back();
            dfs(adj,ans,next);
        }
        ans.push_back(candid);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>ans;
        int n=tickets.size();
        unordered_map<string,vector<string>>adj;
        for(int i=0;i<n;i++){
            string node=tickets[i][0];
            adj[node].push_back(tickets[i][1]);
        }
        for(auto &it :adj){
            sort(it.second.rbegin(),it.second.rend());
        }

        dfs(adj,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
