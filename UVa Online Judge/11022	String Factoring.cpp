#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s && s != "*") {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = len; // worst case: no compression

                // split case
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);

                // repetition case
                string sub = s.substr(i, len);
                auto pi = prefix_function(sub);
                int l = pi[len - 1];
                int period = len - l;

                if (l > 0 && len % period == 0) {
                    dp[i][j] = min(dp[i][j], dp[i][i + period - 1]);
                }
            }
        }

        cout << dp[0][n - 1] << "\n";
    }

    return 0;
}
