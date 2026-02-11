class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();

        for(int i=0;i<m;i++){

            int maxi=score[i][k],maxind=i;

            for(int j=i+1;j<m;j++){

                if(maxi < score[j][k]){
                    maxi = score[j][k];
                    maxind = j;
                }

            }

            if(maxi != score[i][k]){
                swap(score[i],score[maxind]);
            }
        }
        return score;
    }
};