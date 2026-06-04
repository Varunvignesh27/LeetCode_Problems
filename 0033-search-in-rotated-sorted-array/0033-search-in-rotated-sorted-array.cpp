class Solution {
public:

    bool bs(vector<int> nums,int target){
        sort(nums.begin(),nums.end());
        int l = 0,r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }

    int search(vector<int>& nums, int target) {

        if(!bs(nums,target))
            return -1;

        int i=0;
        for(i=0;i<nums.size();i++)
            if(target == nums[i])
                break;
        return i;
        
    }
};