class Solution {
  public:
    string addition(string& s1, string& s2){
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        string ans = "";
        
        int n1 = s1.size(), n2 = s2.size();
        int i = 0, j = 0;
        int sum = 0, carry = 0;
        while(i < n1 || j < n2){
            sum = ((i < n1)? (s1[i] - '0'): 0) + ((j < n2)? (s2[j] - '0'): 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans += (sum + '0');
            i++, j++;
        }
        if(carry) ans += (carry + '0');
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    string minSum(vector<int> &arr) {
        // code here
        vector<int> freq(10, 0);
        for(int c: arr) freq[c]++;
        string first = "", second = "";
        int last = 0;
        for(int i = 1; i < 10; ++i){
            while(freq[i] != 0){
                if(last) first += (i + '0');
                else second += (i + '0');
                last = !last;
                freq[i]--;
            }
        }
        return addition(first, second) ;
    }
};
