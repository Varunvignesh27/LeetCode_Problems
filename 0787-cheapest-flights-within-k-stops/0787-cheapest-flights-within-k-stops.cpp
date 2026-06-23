#include <bits/stdc++.h>
using namespace std;

#define pi pair<int,int>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(n+1,vector<int>(k+2,1e9)); 
        // distance , state wise
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq; 
        // distance , node , state
        vector<vector<pi>> adj(n+1);

        for(auto x : flights){
            adj[x[0]].push_back({x[1],x[2]});
        }

        dist[src][0] = 0;
        pq.push({0,src,0});

        while(!pq.empty()){
            int d_u = pq.top()[0];
            int u = pq.top()[1];
            int cnt_u = pq.top()[2];
            pq.pop();

            if(d_u != dist[u][cnt_u])
                continue;

            for(pi p : adj[u]){
                int v = p.first;
                int w = p.second;
                if(cnt_u + 1 <= k+1 && dist[v][cnt_u + 1] > d_u + w){
                    dist[v][cnt_u + 1] = d_u + w;
                    pq.push({dist[v][cnt_u + 1],v,cnt_u + 1});
                }
            }
        }
        int ans =  *min_element(dist[dst].begin(),dist[dst].end());
        return (ans == 1e9) ? -1 : ans;
    }
};