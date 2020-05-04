#include<iostream>   
#include<cmath>
using namespace std;
int findComplement(int num) {
        if(num==0)          // for 0 the answer will be 1 and for 1 it will be 0 and these are the edge cases for this solution.
            return 1;
        if(num==1)
            return 0;
        if((num & (num-1))==0) // If the number is already a power of 2 the answer will be its previous number.
          return num-1;
        long next = pow(2, ceil(log(num)/log(2))); // calculating the next power of 2 
        return num^(next-1);                       // If you observe carefully the answer will always be the xored value of 1 less than
        										   // the next power of 2  and the given number . This fails only when the number given
    }											   // is itself a power of 2 or the number is 0 or 1.
int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	cout<<findComplement(num);
	return 0;
}