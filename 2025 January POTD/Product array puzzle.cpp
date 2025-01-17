class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &arr) {
    int zeros = 0, idx = -1;
    int prod = 1;

    // Count zeros and track the index of the zero
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            zeros++;
            idx = i;
        } else {
            prod *= arr[i];
        }
    }

    vector<int> res(arr.size(), 0);

    // If no zeros, calculate the product for all elements
    if (zeros == 0) {
        for (int i = 0; i < arr.size(); i++)
            res[i] = prod / arr[i];
    }
    // If one zero, set product only at the zero's index
    else if (zeros == 1)
        res[idx] = prod;

    return res;
}
};
