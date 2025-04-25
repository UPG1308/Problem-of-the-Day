class Solution {
  public:
     int majorityElement(vector<int>& arr) {
        // code here
        int vote=0;
        int element=-1;
        for(int i=0;i<arr.size();i++){
            if(vote==0){
                vote=1;
                element=arr[i];
            }
            else if(arr[i]==element){
                vote++;
            }
            else{
                vote--;
            }
          
        }
        vote=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==element){
                vote++;
            }
        }
        
        return vote>arr.size()/2?element:-1;
 }
};
