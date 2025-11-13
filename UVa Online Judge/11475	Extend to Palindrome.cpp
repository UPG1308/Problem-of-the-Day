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
    while (getline(cin, s)) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        // reverse(s) + '#' + s  ← correct direction
        string combined = rev + "#" + s;
        vector<int> pi = prefix_function(combined);
        int overlap = pi.back(); // longest palindromic suffix length

        cout << s;
        for (int i = overlap; i < (int)rev.size(); i++)
            cout << rev[i];
        cout << "\n";
    }
    return 0;
}
