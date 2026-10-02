class Solution {
public:
    string lexiString(string &s) {
        int n = s.size();
        string t = s + s;
        int i = 0;
        int j = 1;
        int k = 0;
        while(i < n && j < n && k < n) {
            if(t[i + k] == t[j + k]) {
                k++;
                continue;
            }
            if(t[i + k] > t[j + k])
                i = i + k + 1;
            else
                j = j + k + 1;

            if(i == j)
                j++;

            k = 0;
        }
        int start = min(i, j);
        return t.substr(start, n);
    }
};

.
