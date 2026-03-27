class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k = k%m;
        vector<vector<int>> nums = mat;

        while(k--){            
            for(int i = 0;i<n;i++){
                if(i%2 == 0){
                    for(int j=0;j<m-1;j++){
                        swap(nums[i][j],nums[i][j+1]);
                    }
                }else{
                    for(int j = m-1;j > 0;j--){
                        swap(nums[i][j],nums[i][j-1]);
                    }
                }
            }
        }


        if(mat == nums)
            return true;

        return false;
    }
};