class Solution {
public:

    vector<bool> visited;
    vector<vector<int>> res,adj;

    void dfs(int v,int sigma){

        visited[v] = true;

        if(v != sigma)
            res[v].push_back(sigma);

        for(int i : adj[v])
            if(!visited[i])
                dfs(i,sigma);
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        adj.resize(n);
        res.resize(n);

        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
        }

        for(int i=0;i<n;i++){
            visited.assign(n,false);
            dfs(i,i);
        }

        return res;
    }
};