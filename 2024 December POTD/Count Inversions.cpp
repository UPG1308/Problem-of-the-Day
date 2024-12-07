class BIT{
public:
    vector<int> bit;
    int n;
    BIT(int n){
        bit.resize(n + 1);
        this -> n = n;
    }
    
    void update(int ind, int val){
        for(; ind <= n; ind += (ind & -ind)) bit[ind] += val;
    }
    
    int query(int ind){
        int sum = 0;
        for(; ind > 0; ind -= (ind & -ind)) sum += bit[ind];
        return sum;
    }
};

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        map<int, int> mapToIndex;
        for(int num: arr) mapToIndex[num];
        int ind = 2, count = 0;
        for(auto &it: mapToIndex) it.second = ind++;
        
        BIT bit(ind + 2);
        
        for(int num: arr){
            count += bit.query(ind) - bit.query(mapToIndex[num]);
            bit.update(mapToIndex[num], 1);
        }
        return count;
    }
};
