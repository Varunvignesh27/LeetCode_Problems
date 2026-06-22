class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int mx = *max_element(costs.begin(),costs.end());
        int count[mx+1];
        memset(count,0,sizeof(count));
        int res = 0;

        for(int i : costs)
            count[i]++;

        for(int i=1;i<=mx;i++)
            count[i] += count[i-1];

        vector<int> sorted(n);

        //in count[i] is represent the last index of i(value)

        for(int i=0;i<n;i++){
            int idx = count[costs[i]] - 1;
            sorted[idx] = costs[i];
            count[costs[i]]--;
        }

        for(int i=0;i<n;i++){
            if(sorted[i] <= coins){
                res++;
                coins -= sorted[i];
            }
        }
        return res;
    }
};