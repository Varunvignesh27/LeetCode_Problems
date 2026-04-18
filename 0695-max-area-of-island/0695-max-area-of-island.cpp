class Solution {
public:

    bool isValid(int c,int r,vector<vector<int>> &grid){

        if(c >= 0 && c < grid.size() && r >= 0 && r < grid[0].size())
            return true;

        return false;
    }

    int dfs(int i,int j,vector<vector<int>> &grid){

        if(!isValid(i,j,grid) || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;
        int d = dfs(i+1,j,grid);
        int r = dfs(i,j+1,grid);
        int u = dfs(i-1,j,grid);
        int l = dfs(i,j-1,grid);

        return l+r+u+d+1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int cnt = dfs(i,j,grid);
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi==INT_MIN ? 0 : maxi;
    }
};