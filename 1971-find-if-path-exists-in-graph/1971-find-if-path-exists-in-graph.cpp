class Solution {
public:
    vector<vector<int>> adj;

    bool dfs(int s,int d,vector<int>& visited){
        visited[s] = true;
        if(s == d)
            return true;
        
        for(int i : adj[s]){
            if(!visited[i] && dfs(i,d,visited))
                return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<int> visited(n);

        adj.resize(n);
        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        return dfs(source,destination,visited);
    }
};