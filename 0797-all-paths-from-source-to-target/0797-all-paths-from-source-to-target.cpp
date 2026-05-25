class Solution {
public:

    int n;
    vector<vector<int>> ans;

    void dfs(int u,vector<int>& path,vector<vector<int>>& graph){
        if(u == n-1){
            ans.push_back(path);
            return ;
        }

        for(int v : graph[u]){
            path.push_back(v);
            dfs(v,path,graph);
            path.pop_back();
        }

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        n = graph.size();
        vector<int> path;
        path.push_back(0);

        dfs(0,path,graph);

        return ans;
    }
};