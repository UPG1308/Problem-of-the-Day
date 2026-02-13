class Solution {
  public:
    int GetLowerInt(int n)
    {
        int lastDigit = n % 10;
        return (n - lastDigit);
    }
    int CalculateDigitSum(int x)
    {
        int sum = 0;
        while(x>0)
        {
            int rem = x%10;
            x = x/10;
            sum += rem;
        }
        return sum;
    }
    bool ValidateMid(int ans, int d)
    {
        int digitSum = CalculateDigitSum(ans);
        if((ans-digitSum)>=d)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getCount(int n, int d) {
        // code here
        // Binary Search 
        int low = 0;
        int high = GetLowerInt(n);
    
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            mid = GetLowerInt(mid);
            bool isValid = ValidateMid(mid,d);
            if(isValid)
            {
                high = mid - 10;
            }
            else
            {
                low = mid + 10;
            }
        }
        if(low > n)
        {
            return 0;
        }
        return (n - low + 1);
    }
};
