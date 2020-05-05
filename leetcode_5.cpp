#include<iostream>
#include<map>
using namespace std;
/*
The basic idea is to create a map or an array to store the frequency of each character in the string and the itreate the string 
and check the frequency of each char in the string and as soon as you find a char with frequency 1 then just return the index and that
is our answer.

For this implementation the space complexity is O(1) as in worst case your map will have only 26 keys because of the 26 alphabets. 
*/

int firstUniqChar(string s);
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<firstUniqChar(s);
	return 0;
}	

int firstUniqChar(string s) {
        map<char , int>mp;
	for(int i=0;i<s.size();i++){
		if(mp.find(s[i])==mp.end()){
			mp.insert({s[i],1});
		}
		else{
			auto itr = mp.find(s[i]);
			itr->second = itr->second +1;
		}
	}
	int flag=0;
	for(int i=0;i<s.size();i++){
		auto itr = mp.find(s[i]);
		if(itr->second == 1){
			return i;
		}
    }
        return -1;
}