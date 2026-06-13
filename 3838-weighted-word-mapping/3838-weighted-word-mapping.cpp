class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        int sum=0;
        string ans;

        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                int index = words[i][j] - 'a';
                sum += weights[index];
            }
            sum %= 26;
            int t = 'z' - sum;
            ans += (char)t;
            sum = 0;
        }

        return ans;
    }
};