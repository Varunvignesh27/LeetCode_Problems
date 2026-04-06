class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> set;
        vector<int> ans;

        for(int i=0;i<k;i++){
            set.insert(nums[i]);
        }
        ans.push_back(*set.rbegin());

        for(int i=k;i<n;i++){
            set.insert(nums[i]);
            set.erase(set.find(nums[i-k]));
            ans.push_back(*set.rbegin());
        }

        return ans;
    }
};