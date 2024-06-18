class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        int rectangles = 0 ;
        
        //Length of Rectangle < Diameter of Circle
        int l = 2*r;

        //Breadth of Rectangle < Diameter of Circle
        int b = 2*r;

        //Angle made by semicircle is always right angle.
        //By taking diagonal of Rectagle as the Diameter of circle
        //By pythagoras therem in circle
        //Sum of length*length and breadth*breadth <= 4*radius*radius
        int p = 4*r*r;
        

        //Iteraring length from l=1 to l<2*r
        for(int i=1 ; i<l ; i++){
            // Iterating breadth relative to length from b=1 to b<2*r
            for(int j=1 ; j<b ; j++){
                //Checking the condition for sum fo squares of length and breadth of rectangle in a circle 
                if((i*i+j*j) <= p){
                    rectangles++;
                }
            }
        }
        return rectangles;
    }
};
