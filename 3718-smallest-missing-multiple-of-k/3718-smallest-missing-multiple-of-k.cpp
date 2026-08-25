class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        int mul = k;
        for(int i : nums)
            s.insert(i);

        while(true){
            if(mul % k == 0 && s.find(mul) == s.end())
                break;
            
            mul += k;
        }
        return mul;
    }
};