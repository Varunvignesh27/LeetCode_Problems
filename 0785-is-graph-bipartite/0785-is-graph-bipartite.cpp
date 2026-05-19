class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        queue<int> q;

        for(int i=0;i<graph.size();i++){
            if(color[i] == -1){
                color[i] = 0;
                q.push(i);

                while(!q.empty()){
                    int v = q.front();
                    q.pop();

                    for(int u : graph[v]){
                        if(color[u] == -1){
                            color[u] = 1 - color[v];
                            q.push(u);
                        }else if(color[u] == color[v])
                            return false;
                    }
                }
            }
        }

        return true;
    }
};