class Solution {
  public:
    string oddEven(string s) {
        // code here
        vector<int> freq(27,0);
        for(char c: s) freq[c - 'a' + 1]++;
        int odd = 0, even = 0;
        for(int i = 1; i < 27; i++){
            if(freq[i] > 0){
                if(i % 2 == 1 && freq[i] % 2 == 1) odd++;
                else if(i % 2 == 0 && freq[i] % 2 == 0) even++;
            }
        }
        return ((odd + even) % 2 == 0)?"EVEN":"ODD";
    }
};
