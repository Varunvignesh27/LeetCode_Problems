#define F first
#define S second

class Solution {
public:

    int bs(vector<pair<int,int>>& nums,int k){
        int n = nums.size();
        int l = 0,r = n-1;

        while(l <= r){
            int mid = (r-l)/2 + l;
            if(nums[mid].F == k)
                return mid;
            else if(nums[mid].F > k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l - 1;
    }

    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
        
        int n = lst.size();
        int m = wst.size();

        vector<pair<int,int>> land;
        vector<pair<int,int>> water;

        for(int i=0;i<n;i++)
            land.push_back({lst[i],ld[i]});

        for(int i=0;i<m;i++)
            water.push_back({wst[i],wd[i]});

        sort(land.begin(),land.end());
        sort(water.begin(),water.end());

        vector<int> pxl(n);
        vector<int> sxl(n);
        vector<int> pxw(m);
        vector<int> sxw(m);

        pxl[0] = land[0].S;
        for(int i=1;i<n;i++)
            pxl[i] = min(pxl[i-1],land[i].S);

        sxl[n-1] = land[n-1].F + land[n-1].S;
        for(int i = n-2;i>=0;i--)
            sxl[i] = min(sxl[i+1],land[i].F + land[i].S);

        pxw[0] = water[0].S;
        for(int i=1;i<m;i++)
            pxw[i] = min(pxw[i-1],water[i].S);

        sxw[m-1] = water[m-1].F + water[m-1].S;
        for(int i = m-2;i>=0;i--)
            sxw[i] = min(sxw[i+1],water[i].F + water[i].S);

        int ans = 1e9;

        for(int i=0;i<n;i++){
            int end = land[i].F + land[i].S;
            int idx = bs(water,end);
            if(idx >= 0)
                ans = min(ans,end + pxw[idx]);
            if(idx+1 < m)
                ans = min(ans,sxw[idx + 1]);

        }

        for(int i=0;i<m;i++){
            int end = water[i].F + water[i].S;
            int idx = bs(land,end);
            if(idx >= 0)
                ans = min(ans,end + pxl[idx]);
            if(idx + 1 < n)
                ans = min(ans,sxl[idx + 1]);
        }

        return ans;
    }
}; 