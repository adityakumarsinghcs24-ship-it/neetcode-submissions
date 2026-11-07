class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int t=tasks.size();
        vector<int>ans(t);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqs;//{id,index}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pqt;//{time,index}
        for(int i=0;i<servers.size();i++){
            pqs.push({servers[i],i});
        }
        long long time=0;
        for(int i=0;i<t;i++){
            time=max(time,(long long)i);
            while(!pqt.empty() && pqt.top().first<=i){
                int ind=pqt.top().second;
                pqs.push({servers[ind],ind});
                pqt.pop();
            }
            if(pqs.empty()) {
                time = get<0>(pqt.top());

                while(!pqt.empty() && get<0>(pqt.top()) <= time) {
                    int ind=pqt.top().second;
                    pqs.push({servers[ind],ind});
                    pqt.pop();
                }
            }
            int index=pqs.top().second;
            pqs.pop();
            ans[i]=index;
            pqt.push({tasks[i]+time,index});
        }
        return ans;
    }
};