class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
  
    // Put all elements of a[] in sa
    unordered_set<int> sa(a.begin(), a.end());  
    vector<int> res;                            

    // Traverse through b[]
    for (int i = 0; i < b.size(); i++) {
      
        // If the element is in sa
        // a) Add it to the result array
        // b) Erase it from sa to avoid duplicates
        if (sa.find(b[i]) != sa.end()) {
            res.push_back(b[i]); 
            sa.erase(b[i]);  
        }
    }

    return res;
}
