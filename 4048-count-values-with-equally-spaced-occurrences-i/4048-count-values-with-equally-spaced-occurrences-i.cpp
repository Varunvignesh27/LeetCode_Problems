class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,int> mp;
        vector<vector<int>> cnt(105);
        int n = nums.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            cnt[nums[i]].push_back(i);
        }

        for(auto i : mp){
            if(i.second == 3){
                if(cnt[i.first][1]-cnt[i.first][0] == cnt[i.first][2] - cnt[i.first][1]){
                    ans++;
                }
            }
        }

        return ans;
    }
};