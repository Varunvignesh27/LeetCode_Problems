class Solution {
public:
    int countBattleships(vector<vector<char>>& grid) {

        int cnt = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 'X'){
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }

    void dfs(int i,int j,vector<vector<char>> &grid){
        if(!valid(i,j,grid) || grid[i][j] == '.')
            return ;

        grid[i][j] = '.';
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