
class Solution {
public:
    int subarraySum(vector<int>& arr) 
    {
        int len = arr.size();
        int sum  = 0;
        for(int i=0;i<len;i++)
        {
            sum+=arr[i]*(i+1)*(len-i);
        }
        return sum;
        
    }
};
