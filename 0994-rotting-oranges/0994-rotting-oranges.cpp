class Solution {
public:

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(m));
        int cnt = 0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 2)
                    q.push({i,j});

        while(!q.empty()){
            int s = q.size();
            bool f = false;
            while(s--){
                pair<int,int> curr = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = curr.first + dx[i];
                    int y = curr.second + dy[i];
                    if(valid(x,y,grid) && grid[x][y] == 1){
                        q.push({x,y});
                        grid[x][y] = 2;
                        f= true;
                    }
                }
            }
            cnt += f;
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1)
                    return -1;

        return cnt;
    }

    bool valid(int &x,int &y,vector<vector<int>> &grid){
        if(x >=0 && x < grid.size() && y >=0 && y < grid[0].size())
            return true;
        return false;
    }
};