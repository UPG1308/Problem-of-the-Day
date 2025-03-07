class Solution {
public:
    vector<int> primeFactors(int n, int left){
        vector<int> prime(n + 1, 1);
        prime[1] = 0;
        for(int i = 2; i <= n; ++i){
            for(int j = 2 * i; j <= n; j += i){
                prime[j] = 0;
            }
        }
        vector<int> primeFac;
        for(int i = left; i <= n; ++i){
            if(prime[i]) primeFac.push_back(i);
        }
        return primeFac;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime = primeFactors(right, left);
        vector<int> ans = {-1, -1};
        int val = 1e9;
        for(int i = 1; i < prime.size(); ++i){
            if(prime[i] - prime[i - 1] < val){
                val =  prime[i] - prime[i - 1];
                ans = {prime[i - 1], prime[i]};
            }
        }
        return ans;
    }
};
