class Solution {
public:
    string compress(string &s) {
        int n = s.size();

        // KMP prefix function / LPS
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }

            if (s[i] == s[j]) {
                j++;
            }

            lps[i] = j;
        }

        string ans;

        // Construct answer from right to left
        int i = n - 1;

        while (i >= 0) {

            // i + 1 = current prefix length
            if (i % 2 == 1) {
                int len = i + 1;

                int period = len - lps[i];

                if (lps[i] >= len / 2 &&
                    len % (2 * period) == 0) {

                    ans += '*';

                    // Skip the duplicated half
                    i = i / 2 + 1;
                }
                else {
                    ans += s[i];
                }
            }
            else {
                ans += s[i];
            }

            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
