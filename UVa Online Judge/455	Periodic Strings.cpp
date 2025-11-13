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

    int T;
    cin >> T;
    string s;
    getline(cin, s); // consume newline after T
    while (T--) {
        getline(cin, s);
        while (s.empty()) getline(cin, s); // skip blank lines

        auto pi = prefix_function(s);
        int n = s.size();
        int period = n - pi[n - 1];
        if (n % period != 0) period = n;

        cout << period << "\n";
        if (T) cout << "\n"; // blank line between outputs
    }
}
