class Solution {
  public:

void rearrange(vector<int> &arr) {
        queue<int>pos,neg;
        for(auto &i:arr) i<0 ?neg.push(i):pos.push(i);
        int ind=0;
        while(!pos.empty() || !neg.empty()){
            if(!pos.empty()) {
                arr[ind++]=pos.front();
                pos.pop();
            }
             if(!neg.empty()){
                 arr[ind++]=neg.front();
                  neg.pop();
             }
        }
    }
};
