#include<iostream>
#include<cmath>
#include<vector>
/*
This problem can be solved by the implementation of Moore's algo and since in the question it was given that the array will always have 
a majority element hence no need to check whether the majority element is actually present for more than n/2 times.
*/

using namespace std;
int majorityElement(vector<int>& nums);
int main(int argc, char const *argv[])
{
	vector<int>v ;
	int n;
	cin>>n;
    while(n>0){
	 	int x;
	 	cin>>x;
	 	v.push_back(x);
	 	n=n-1;
	}
	cout<<"Majority element is : "<<majorityElement(v);
	return 0;
}	

int majorityElement(vector<int>& v) {
 	int majority = v[0];
 	int count = 1;
 	int half = floor(v.size()/2);
 	 for(int i=1;i<v.size();i++){
 	 	if(v[i]==majority){
 	 		count=count+1;
 	 		if(count>half)
 	 			return majority;
 	 	}
 	 	else{
 	 		count= count-1;
 	 		if(count==0){
 	 			majority = v[i];
 	 			count=1;
 	 		}
 	 	}
 	 }
 	 return majority;
 }