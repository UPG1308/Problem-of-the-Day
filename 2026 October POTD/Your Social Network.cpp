class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        int n = arr.size() + 1;

        vector<int> parent(n + 1);

        // arr[i - 2] is the friend of user i
        for (int i = 2; i <= n; i++) {
            parent[i] = arr[i - 2];
        }

        vector<vector<int>> answer;

        for (int i = 2; i <= n; i++) {
            vector<int> distance(n + 1, -1);

            int current = i;
            int steps = 0;

            // Follow the friend chain
            while (current != 1) {
                current = parent[current];
                steps++;

                distance[current] = steps;
            }

            // j must be considered in increasing order
            for (int j = 1; j < i; j++) {
                if (distance[j] != -1) {
                    answer.push_back({i, j, distance[j]});
                }
            }
        }

        return answer;
    }
};
