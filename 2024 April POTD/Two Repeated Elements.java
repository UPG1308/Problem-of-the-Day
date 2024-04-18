class Solution
{
    //Function to find two repeated elements.
    public int[] twoRepeated(int arr[], int n)
    {
        // Your code here
        int a=-1,b=-1;
        for(int i:arr){
            int id=Math.abs(i);
            if(arr[id]<0){
                if(a==-1) a=id;
                else b=id;
            }
            else arr[id]=-arr[id];
        }
        return new int[]{a,b};
    }
}
