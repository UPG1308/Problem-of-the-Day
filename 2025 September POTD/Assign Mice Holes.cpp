class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        int n = mices.size();
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int sum = 0;
        for(int i = 0; i < n; ++i) sum = max(sum, abs(mices[i] - holes[i]));
        return sum;
    }
};
