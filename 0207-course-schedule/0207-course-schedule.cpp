class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }

        vector<int> indegree(numCourses);
        int len = 0;
        queue<int> q;

        for(auto i : adj){
            for(int j : i){
                indegree[j]++;
            }
        }

        for(int i=0;i<numCourses;i++){
                if(indegree[i] == 0)
                    q.push(i);
        }

        while(!q.empty()){
            int v = q.front();
            q.pop();

            len++;
            for(int u : adj[v]){
                indegree[u]--;
                if(indegree[u] == 0)
                    q.push(u);
            }
        }

        return len == numCourses;
    }
};