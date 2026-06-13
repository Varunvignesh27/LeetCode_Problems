#include <bits/stdc++.h>
using namespace std;

#define mod ((int)1e9 + 7)

class Solution {
public:

    vector<vector<int>> adj;
    vector<int> dep;
    vector<int> pow_2;
    vector<vector<int>> up;

    void dfs(int u = 1,int p = -1,int d = 0){


        up[0][u] = p;
        for(int i=1;i<20;i++){
            if(up[i-1][u] != -1)
                up[i][u] = up[i-1][up[i-1][u]];
        }

        dep[u] = d;
        for(int v : adj[u]){
            if(v != p)
                dfs(v,u,d+1);
        }
    }

    void calc(){
        pow_2.resize((int)1e5 + 2);
        pow_2[0] = 1;
        for(int i=1;i<(int)1e5+2;i++){
            pow_2[i] = (2 * pow_2[i-1]) % mod;
        }
    }

    int LCA(int u,int v){
        if(dep[u] < dep[v])
            swap(u,v);
        
        int diff = dep[u] - dep[v];
        int i = 0;

        while(diff){
            if(diff & 1){
                u = up[i][u];
            }
            i++;
            diff = diff >> 1;
        }

        if(u == v)
            return u;

        for(int i=19;i>=0;i--){
            if(up[i][u] != up[i][v]){
                u = up[i][u];
                v = up[i][v];
            }
        }

        return up[0][v];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size();
        adj.resize(n+2);
        dep.resize(n+2);
        up.resize(20,vector<int>(n+2,-1));
        vector<int> ans;
        calc();

        for(auto u : edges){
            adj[u[0]].push_back(u[1]);
            adj[u[1]].push_back(u[0]);
        }

        dfs();
        
        for(auto q : queries){
            int lca = LCA(q[0],q[1]);
            int d = dep[q[0]] + dep[q[1]] - (2 * dep[lca]);

            if(d == 0)
                ans.push_back(0);
            else
                ans.push_back(pow_2[d-1]);
        }

        return ans;
    }
};