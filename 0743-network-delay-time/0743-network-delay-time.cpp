class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int,int>>> adj(n+1);
	   vector<int> dis(n+1,1e9);
	   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	   int ans = 0;
	   dis[k] = 0;
	   q.push({0,k});

	   for(auto v : times){
			adj[v[0]].push_back({v[1],v[2]});
	   }

	   while(!q.empty()){
			pair<int,int> p = q.top();
			int du = p.first;
			int u = p.second;
			q.pop();

			if(du > dis[u])
				continue;

			for(auto v : adj[u]){
				if(dis[v.first] > dis[u] + v.second){
					dis[v.first] = dis[u] + v.second;
					q.push({dis[v.first],v.first});
				}
			}
	   }
       
	   for(int i = 1; i <= n; i++){
			if(dis[i] == 1e9)
				return -1;
            ans = max(ans,dis[i]);
	   }

	   return ans;
    }
};