class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        
        queue<int> q;
        vector<int> color(adj.size(),-1);
        
        for(int i=0;i<adj.size();i++){
            if(color[i] == -1){
                color[i] = 0;
                q.push(i);
                
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int j=0;j<adj[u].size();j++){
                        
                        if(color[adj[u][j]] == -1){   
                            color[adj[u][j]] = 1 - color[u];
                            q.push(adj[u][j]);
                        }
                        else if(color[adj[u][j]] == color[u])
                            return false;
                    }
                }
            }
        }
        
        return true;
        
    }
};