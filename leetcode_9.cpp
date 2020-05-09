/*
We start our for loop from 2 and go to the half of the number.
Each time we divide the number by i and see if the quotient is equal to i and if equal return true and if quotient is less than i then
return false.

For 0 and 1 we have handled it separately.
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0 || num==1)
            return true;
        double sq;
        for(int i=2;i<=num/2;i++){
             sq = (double)num/i;
            if(sq==i)
                return true;
            if(sq<i)
                return false;
        }    
        return false;
    }
};