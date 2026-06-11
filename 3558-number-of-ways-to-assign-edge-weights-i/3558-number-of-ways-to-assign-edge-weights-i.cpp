#define mod (int)(1e9 + 7)

class Solution {
public:

    int md = 0;
    vector<vector<int>> adj;

    void dfs(int u = 1,int p = -1,int d = 0){

        md = max(md,d);

        for(int v : adj[u]){
            if(v == p)
                continue;
            dfs(v, u, d+1);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n+2);

        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs();

        int ans = 1;
        for(int i=0;i<md-1;i++)
            ans = (ans * 2) % mod;

        return ans;
    }
};