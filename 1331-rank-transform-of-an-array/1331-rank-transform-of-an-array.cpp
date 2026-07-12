class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        vector<int> res(n);
        vector<int> sorted(arr.begin(),arr.end());
        sort(sorted.begin(),sorted.end());
        int rank = 1;

        for(int i=0;i<n;i++){
            if(i > 0 && sorted[i] > sorted[i-1])
                rank++;
            mp[sorted[i]] = rank;
        }

        for(int i=0;i<n;i++){
            res[i] = mp[arr[i]];
        }

        return res;
    }
};