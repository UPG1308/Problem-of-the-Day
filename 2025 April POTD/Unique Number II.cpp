class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int leftsm=0;
        int totsm=0;
        int xr=0;
        for(auto i:arr){
            xr=xr^i;
            leftsm+=i;
            totsm+=i+i;
        }
        int x=-1;
        for(int i=0;i<=32;i++){
            if((xr>>i)&1 ){
                x=i;break;
            }
        }
        int x1=0,x2=0;
        for(auto i:arr){
            if((i>>x)&1 ){
                x1^=i;
            }
            else{
                x2^=i;
            }
        }
        if(x1>x2)return {x2,x1};
        return {x1,x2};
    }
};
};
