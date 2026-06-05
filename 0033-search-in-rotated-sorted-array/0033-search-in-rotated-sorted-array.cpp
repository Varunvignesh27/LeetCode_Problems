class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r=n-1;

        while(l < r){
            int mid = (r-l)/2 + l;
            if(nums[mid] < nums[r])
                r = mid ;
            else 
                l = mid + 1;
        }
        
        int rotate = l;
        l = 0;
        r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            int k = (mid+rotate)%n;
            if(nums[k] == target)
                return k;
            else if(nums[k] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return -1;
    }
};