class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto v : dislikes){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> color(n+1,-1);
        queue<int> q;

        for(int i=0;i<adj.size();i++){
            if(color[i] == -1){
                color[i] = 0;
                q.push(i);

                while(!q.empty()){
                    int u = q.front();
                    q.pop();

                    for(int v : adj[u]){
                        if(color[v] == -1){
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        else if(color[u] == color[v])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};