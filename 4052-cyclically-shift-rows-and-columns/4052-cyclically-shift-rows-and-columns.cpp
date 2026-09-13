class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> mat = grid;

        for(int i=0;i<n;i++){
            row(mat,n,rowShift[i],i);
        }

        for(int i=0;i<n;i++){
            col(mat,n,colShift[i],i);
        }

        return mat;

    }

    void row(vector<vector<int>>& mat,int n,int k,int r){
        for(int i=0;i<k;i++){
            for(int j=0;j<n-1;j++){
                swap(mat[r][j],mat[r][j+1]);
            }
        }
    }

    void col(vector<vector<int>>& mat,int n,int k,int c){
        for(int i=0;i<k;i++){
            for(int j=0;j<n-1;j++){
                swap(mat[j][c],mat[j+1][c]);
            }
        }
    }
};