class Solution {
     static Long reversedBits(Long x) {
        
        Long res=0l;
        for(int i=0;i<32;i++){
         res= (res<<1)+ (x%2);
         x/=2;
        }
        return res;
    }
};
