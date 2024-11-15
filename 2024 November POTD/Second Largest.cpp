class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int largest = 0, secondLargest = -1;
        for(int num: arr){
            if(num > largest){
                secondLargest = largest;
                largest = num;
            }
            else if(num != largest && num > secondLargest){
                secondLargest = num;
            }
        }
        return secondLargest;
    }
};
