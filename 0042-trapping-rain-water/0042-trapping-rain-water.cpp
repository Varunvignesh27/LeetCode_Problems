class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
        return n;

        vector<int> maxleft(n),maxright(n);

        maxleft[0] = height[0];
        for(int i=1;i<n;i++){
            maxleft[i] = max(maxleft[i-1],height[i]);
        }

        maxright[n-1] = height[n-1];
        for(int j=n-2;j>=0;j--){
            maxright[j] = max(maxright[j+1],height[j]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(min(maxleft[i],maxright[i])-height[i],0);
        }
        return ans;
    }
};