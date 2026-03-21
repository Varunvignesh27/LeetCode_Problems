class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        for(int i = x;i<min(n,x+k);i++){
            for(int j = y;j<min(m,y+k);j++){
                swap(grid[i][j],grid[x+k-cnt-1][j]);
            }
            cnt++;
            if(cnt == k/2)
                break;
        }

        return grid;
    }
};