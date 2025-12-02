class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        vector<long long> pref(n+1, 0);
        vector<vector<int>> cnt(26, vector<int>(n+1, 0));
        
        for(int i = 0; i < n; i++){
            pref[i+1] = pref[i] + s[i];
            for(int c = 0; c < 26; c++)
                cnt[c][i+1] = cnt[c][i];
            cnt[s[i]-'a'][i+1]++;
        }

        vector<vector<int>> allow(26);
        for(auto &p: jumps)
            allow[p[0]-'a'].push_back(p[1]-'a');

        // next occurrence array
        vector<vector<int>> nextOcc(n+1, vector<int>(26, -1));
        for(int c = 0; c < 26; c++)
            nextOcc[n][c] = -1;

        for(int i = n-1; i >= 0; i--) {
            for(int c = 0; c < 26; c++)
                nextOcc[i][c] = nextOcc[i+1][c];
            nextOcc[i][s[i]-'a'] = i;
        }

        auto score = [&](int i, int j){
            int c = s[j] - 'a';
            long long total = pref[j] - pref[i];
            long long remove = (long long)(cnt[c][j] - cnt[c][i]) * (s[j]);
            return total - remove;
        };

        vector<long long> dp(n, 0);

        for(int i = n-1; i >= 0; i--) {
            int same = nextOcc[i+1][s[i]-'a'];
            if(same != -1)
                dp[i] = max(dp[i], score(i, same) + dp[same]);
            
            for(int nxt : allow[s[i]-'a']) {
                int j = nextOcc[i+1][nxt];
                if(j != -1)
                    dp[i] = max(dp[i], score(i, j) + dp[j]);
            }
        }

        return dp[0];
    }
};
