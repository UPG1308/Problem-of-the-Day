class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        double sum=accumulate(arr.begin(),arr.end(),0);
        priority_queue<double>pq;
        for(auto it:arr){
            pq.push(it);
        }
        double half=sum/2;
        int count=0;
        while(!pq.empty() && sum>half){
            double top=pq.top();
            pq.pop();
            sum-=(top/2);
            double rem=top-top/2;
            pq.push(rem);
            count++;
        }
        return count;
    }
};
