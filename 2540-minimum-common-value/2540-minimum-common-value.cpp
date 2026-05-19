class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s(nums1.begin(),nums1.end());

        for(int i : nums2){
            if(s.contains(i)){
                return i;
            }
        }

        return -1;
    }
};