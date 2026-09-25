#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Box {
        int height;
        int baseLength;
        int baseWidth;
    };

    vector<Box> boxes;
    vector<long long> dp;

    long long solve(int i) {
        if (dp[i] != -1)
            return dp[i];

        long long best = boxes[i].height;

        for (int j = 0; j < (int)boxes.size(); j++) {
            // j can be placed on top of i
            if (boxes[j].baseLength < boxes[i].baseLength &&
                boxes[j].baseWidth < boxes[i].baseWidth) {

                best = max(best,
                           (long long)boxes[i].height + solve(j));
            }
        }

        return dp[i] = best;
    }

    int maxHeight(vector<int> &height,
                  vector<int> &width,
                  vector<int> &length) {

        int n = height.size();

        boxes.clear();

        // Generate all 3 orientations of every box.
        for (int i = 0; i < n; i++) {

            // Height = height[i]
            {
                int a = width[i];
                int b = length[i];

                boxes.push_back({
                    height[i],
                    max(a, b),
                    min(a, b)
                });
            }

            // Height = width[i]
            {
                int a = height[i];
                int b = length[i];

                boxes.push_back({
                    width[i],
                    max(a, b),
                    min(a, b)
                });
            }

            // Height = length[i]
            {
                int a = height[i];
                int b = width[i];

                boxes.push_back({
                    length[i],
                    max(a, b),
                    min(a, b)
                });
            }
        }

        int m = boxes.size();

        dp.assign(m, -1);

        long long answer = 0;

        for (int i = 0; i < m; i++) {
            answer = max(answer, solve(i));
        }

        return (int)answer;
    }
};
