class Solution {
public:
    vector<vector<int>> ps;
    vector<vector<int>> count;

    void prefixsum(int n,int m,vector<vector<char>> &nums){

        ps.resize(n+1,vector<int>(m+1,0));
        count.resize(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums[i-1][j-1] == 'X'){
                    ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + 1;
                    count[i][j] = count[i-1][j] + count[i][j-1] - count[i-1][j-1] + 1;
                }else if(nums[i-1][j-1] == 'Y'){
                    ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] - 1;
                    count[i][j] = count[i-1][j] + count[i][j-1] - count[i-1][j-1];
                }else{
                    ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
                    count[i][j] = count[i-1][j] + count[i][j-1] - count[i-1][j-1];
                }

            }
        }

    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        prefixsum(n,m,grid);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(ps[i][j] == 0 && count[i][j] > 0)
                    ans++;
                
            }
            
        }

        return ans;
    }
};

// 0 0  0  0
// 0 1  0  0
// 0 0 -1 -1