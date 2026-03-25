class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> ps(n+1,vector<long long> (m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ps[i][j] = ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1] + grid[i-1][j-1];
            }
        }

        for(int i=1;i<=n;i++){
            if(ps[i][m] == (ps[n][m] - ps[i][m]))
                return true;
        }

        for(int i=1;i<=m;i++){
            if(ps[n][i] == (ps[n][m] - ps[n][i]))
                return true;
        }

        return false;
    }
};