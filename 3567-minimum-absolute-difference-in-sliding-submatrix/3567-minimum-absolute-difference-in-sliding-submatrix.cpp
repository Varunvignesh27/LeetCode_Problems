class Solution {
public:

    int findMin(vector<vector<int>> grid,int i,int j,int k){

        int m = INT_MAX;
        unordered_set<int> s;
        vector<int> v;

        for(int l=i;l<i+k;l++){
            for(int r=j;r<j+k;r++){
                s.insert(grid[l][r]);
            }
        }

        for(int i : s){
            v.push_back(i);
        }

        int n = v.size();
        sort(v.begin(),v.end());

        for(int l=0;l<n-1;l++){
            if(m > abs(v[l] - v[l+1])){
                m =  abs(v[l] - v[l+1]);
            }
        }

        return m;

    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mat(n-k+1,vector<int>(m-k+1,0));

        for(int i=0;i<n-k+1;i++){
            for(int j=0;j<m-k+1;j++){
                if(findMin(grid,i,j,k) == INT_MAX)
                    mat[i][j] = 0;
                else
                    mat[i][j] = findMin(grid,i,j,k);
            }
        }

        return mat;
    }
};