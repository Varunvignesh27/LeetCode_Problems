class Solution {
public:

    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int u,int& n,int& e){
        vis[u] = true;

        n++;
        e += adj[u].size();

        for(int v : adj[u]){
            if(!vis[v])
                dfs(v,n,e);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n,false);
        int res = 0;

        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                int n = 0,e = 0;
                dfs(i,n,e);
                if(n*(n-1)/2 == e/2)
                    res++;
            }
        }
        return res;
    }
};