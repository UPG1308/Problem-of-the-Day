class Solution {
public:
    int minCost(int n, int m, vector<int>& x, std::vector<int>& y) {
        long long totalCost = 0;
        int horizontal_pieces = 1;
        int vertical_pieces = 1;

        // Sort cut costs in descending order
        sort(x.begin(), x.end(), std::greater<int>());
        sort(y.begin(), y.end(), std::greater<int>());

        int i = 0; // Pointer for vertical cuts (vector x)
        int j = 0; // Pointer for horizontal cuts (vector y)

        // Iterate while there are still cuts to be made
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                totalCost += x[i] * horizontal_pieces;
                vertical_pieces++;
                i++;
            }
            else {
                totalCost += y[j] * vertical_pieces;
                horizontal_pieces++;
                j++;
            }
        }
        while(i<x.size())
        {
            totalCost += x[i] * horizontal_pieces;
                vertical_pieces++;
                i++;
        }
        while(j<y.size())
        {
            totalCost += y[j] * vertical_pieces;
                horizontal_pieces++;
                j++;
        }
        return (totalCost);
    }
};
