class Solution {
public:
    string largestSwap(string &s) {
        int i, n = s.size(), maxDigit = -1, maxIdx = -1, left = -1, right = -1;
        for(i = n-1; i >= 0; i--) {
            if(s[i]-'0' > maxDigit) {
                maxDigit = s[i]-'0';
                maxIdx = i;
            }
            else if(s[i]-'0' < maxDigit) {
                left = i;
                right = maxIdx;
            }
        }
        if(left != -1)
            swap(s[left], s[right]);

        return s;
    }
};
