
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<long long,long long>> v(n);

        for(int i=0;i<n;i++){
            v[i] = {nums[i],cost[i]};
        }

        sort(v.begin(),v.end());
        vector<long long> pc(n),pnc(n);
        long long ans = LLONG_MAX;

        for(int i=0;i<n;i++){
            if(i == 0){
                pc[i] = v[i].second;
                pnc[i] = v[i].first * v[i].second;
            }else{
                pc[i] = v[i].second + pc[i-1];
                pnc[i] = (v[i].first * v[i].second) + pnc[i-1];
            }
        }

        for(int i=0;i<n;i++){
            long long frontcost = v[i].first * pc[i];
            long long backcost = v[i].first * (pc[n-1] - pc[i]);
            long long totalfront = pnc[i];
            long long totalback = pnc[n-1] - pnc[i];

            long long temp = frontcost - backcost - totalfront + totalback;

            ans = min(ans,temp);
        }

        return ans;
    }
};