class Solution {
public:
    vector<int>parent;
    vector<int>size;
    int findParent(int x){
        if(x==parent[x])return x;
        return parent[x]=findParent(parent[x]);
    }
    void unionSize(int a,int b){
        int roota =findParent(a);
        int rootb= findParent(b);
        if(roota==rootb)return;
        if(size[roota]<size[rootb])swap(roota,rootb);
        parent[rootb]=roota;
        size[roota]+=size[rootb];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        size.assign(n+1,1);
        for(int i=0;i<=n;i++)parent[i]=i;
        vector<int>ans;
        int r=-1,c=-1;
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            if(findParent(a)==findParent(b)){
                r=a;
                c=b;
            }
            else{
                unionSize(a,b);
            }
        }
        
        ans.push_back(r);
        ans.push_back(c);
        return ans;
    }
};
