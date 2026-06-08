class Solution {
public:

    int partition(vector<int>& nums,int l,int h){
        int p = l + random() % (h-l+1);
        swap(nums[p],nums[h]);

        int pivot = nums[h];
        int i = l-1;
        for(int j=l;j<h;j++){
            if(nums[j] < pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[h]);
        return i+1;
    }

    void quicksort(vector<int>& nums,int l,int h){
        if(l < h){
            int pi = partition(nums,l,h);

            quicksort(nums,l,pi-1);
            quicksort(nums,pi+1,h);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        quicksort(nums,0,nums.size()-1);
        return nums;
        
    }
};