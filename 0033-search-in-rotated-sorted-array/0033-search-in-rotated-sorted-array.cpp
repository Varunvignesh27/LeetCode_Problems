class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r=n-1;

        while(l <= r){
            int mid = (r-l)/2 + l;
            if(nums[0] <= nums[mid])
                l = mid +1;
            else 
                r = mid - 1;
        }
        
        int rotate = n - l;
        l = 0;
        r = n-1;


        while(l <= r){
            int mid = l + (r-l)/2;
            int k = (mid - rotate + n)%n;
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