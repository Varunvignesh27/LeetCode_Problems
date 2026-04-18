class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int cnt = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int i,int j,vector<vector<char>> &grid){
        if(!valid(i,j,grid) || grid[i][j] == '0')
            return ;

        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }

    bool valid(int i,int j,vector<vector<char>> &grid){

        if(i >= 0 && i < grid.size() && j >=0 && j < grid[0].size())
            return true;

        return false;
    }
};