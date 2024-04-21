class Solution{
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    public void threeWayPartition(int array[], int a, int b)
    {
        // code here 
        int left = 0, right = array.length - 1, mid = 0;
        while(mid <= right){
            if(array[mid] < a){
                swap(mid++, left++, array);
                // mid++;
                // left++;
            }
            else if(array[mid] > b){
                swap(mid, right--, array);
                // right--;
            }
            else{
                mid++;
            }
        }
    }
    public void swap(int ind1, int ind2, int[] array){
        // array[ind1] = array[ind1] ^ array[ind2];
        // array[ind2] = array[ind1] ^ array[ind2];
        // array[ind1] = array[ind1] ^ array[ind2];
        int temp = array[ind2];
        array[ind2] = array[ind1];
        array[ind1] = temp;
    }
}
