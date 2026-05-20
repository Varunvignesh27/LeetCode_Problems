class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int> mp;
        vector<int> ans(A.size());

        for(int i=0;i<B.size();i++){
            mp[A[i]]++;
            int temp = 0;
            for(int j=0;j<=i;j++){
                if(mp.find(B[j]) != mp.end()){
                    temp++;
                }
            }
            ans[i] = temp;
        }

        return ans;
    }
};