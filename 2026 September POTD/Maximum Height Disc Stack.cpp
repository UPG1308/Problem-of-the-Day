class Solution {
public:
    virtual int maxStackHeight(vector<int>& r, vector<int>& h) {
        vector<pair<int,int>> a;
        for(int i=0;i<r.size();i++) a.push_back({r[i],h[i]});
        sort(a.begin(),a.end());

        int bit[1002]={}, ans=0;

        // Get Max value <= x
        auto query=[&](int x){
            int z=0;
            for(;x;x-=x&-x) z=max(z,bit[x]);
            return z;
        };

        auto update=[&](int x,int v){
            for(;x<=1000;x+=x&-x) bit[x]=max(bit[x],v);
        };

        for(int i=0;i<a.size();){
            int j=i;
            vector<pair<int,int>> v;
            while(j<a.size() && a[j].first==a[i].first) j++;

            // Query first, so equal-radius discs can't stack.
            for(int k=i;k<j;k++)
                v.push_back({a[k].second,query(a[k].second-1)+a[k].second});

            for(auto [x,val]:v) {
                update(x,val);
                ans=max(ans,val);
            }
            i=j;
        }
        return ans;
    }
};
