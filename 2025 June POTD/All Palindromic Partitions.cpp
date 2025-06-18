class Solution {
  public:
  
  vector<int> p;
    void manacher(string s){
      int n = s.size();
      p.assign(n, 1);
      int l = 1, r = 1;
      for(int i = 1; i < n; ++i){
        p[i] = max(0, min(r - i, p[l + r - i]));
        while(i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) p[i]++; // bounding box
        if(i + p[i] > r){
          l = i - p[i];
          r = i + p[i];
        }
      }
    }
    
    int getLongest(int centre, bool odd){
      int pos = 2 * centre + 1 + (!odd);
      return p[pos] - 1;
    }
    
    bool palindromeCheck(int l, int r){
      if((r - l + 1) <= getLongest((l + r) / 2, l % 2 == r % 2)) return true;
      return false;
    }

  
    void backtrack(int start, string &s, vector<string> &path, vector<vector<string>> &ans){
        
        if(start == s.size()){
            vector<string> pat = path;
            ans.push_back(pat);
            return;
        }
        
        for(int end = start; end < s.size(); ++end){
            if(palindromeCheck(start, end)){
                string sub = s.substr(start, end - start + 1);
                path.push_back(sub);
                backtrack(end + 1, s, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        string str = "#";
        for(char c: s) str += c + string("#");
        manacher(str);
        vector<string> path;
        vector<vector<string>> ans;
        backtrack(0, s, path, ans);
        return ans;
    }
};
