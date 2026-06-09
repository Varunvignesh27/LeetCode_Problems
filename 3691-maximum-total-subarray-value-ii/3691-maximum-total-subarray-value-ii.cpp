#define F first
#define S second
#define ll long long

class Solution {
public:

    vector<vector<pair<ll,ll>>> st;
    const int K = 25;

    void build(vector<int>& nums,int n){
        st.resize(K,vector<pair<ll,ll>>(n));

        for(int i=0;i<n;i++){
            st[0][i] = {nums[i],nums[i]};
        }

        for(int i=1;i<K;i++){
            for(int j=0;j + (1 << i-1) < n;j++){
                st[i][j] = merge(st[i-1][j],st[i-1][j + (1 << i-1)]);
            }
        }
    }

    pair<ll,ll> merge(pair<ll,ll>& a, pair<ll,ll>& b){
        return {max(a.F,b.F),min(a.S,b.S)};
    }

    pair<ll,ll> rangeQuery(int l,int r){
        pair<ll,ll> res = {-1e18,1e18};
        for(int i = K-1;i >= 0;i--){
            if(r-l+1 >= (1 << i)){
                res = merge(res,st[i][l]);
                l += (1 << i);
            }
        }
        return res;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<pair<ll,pair<int,int>>> pq;
        build(nums,n);

        for(int l=0;l<n;l++){
            pair<ll,ll> pi = rangeQuery(l,n-1);
            ll val = pi.F - pi.S;
            pq.push({val,{l,n-1}});
        }

        long long ans = 0;
        while(k--){
            ans += pq.top().F;
            pair<int,int> range = pq.top().S;
            pq.pop();

            int l = range.F;
            int r = range.S - 1;
            if(r >= l){
                pair<ll,ll> pi = rangeQuery(l,r);
                ll val = pi.F - pi.S;
                pq.push({val,{l,r}});
            }
        }

        return ans;
    }
};