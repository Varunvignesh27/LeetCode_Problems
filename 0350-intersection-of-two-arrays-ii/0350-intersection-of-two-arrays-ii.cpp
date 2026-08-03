class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1;
        unordered_map<int,int> n2;
        vector<int> arr;

        for(int i : nums1){
            n1[i]++;
        }

        for(int j :nums2){
            n2[j]++;
        }

        for(auto i : n1){
            if(n2.find(i.first) != n2.end()){
                int size = min(i.second,n2[i.first]);
                for(int l=0;l<size;l++)
                    arr.push_back(i.first);
            }
        }
        
        return arr;
    }
};