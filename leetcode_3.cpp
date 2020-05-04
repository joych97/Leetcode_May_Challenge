#include<iostream>          
#include<map>
using namespace std;

 /*
 The solution is to create a new map for the magazine string with key as the characters and value as the frequency of the characters.
 And then iterate on the ransom string and break as soon as there is a character that is not in the map or if the value of the key in the
 map is 0. And each time we hit a key that is present in the map reduce the value of the key by 1. 

 The output in this solution will be 1/0 based on true/false.	

 */
bool validateRansom(string r, string j);
int main(int argc, char const *argv[])
{
	string r; //Ransom Note
	string j; //Magazine 
	cin>>r>>j;
	cout<<validateRansom(r,j);
	return 0;
}
 bool validateRansom(string r, string j)
 {
    map<char,int>mp;
    for(int i=0;i<j.size();i++){
        if(mp.find(j[i])!=mp.end()){
            auto itr = mp.find(j[i]);
            itr->second = itr->second+1;
        }
        else{
            mp.insert({j[i],1});
    	}
    }
    for(int i=0;i<r.size();i++){
        if(mp.find(r[i])==mp.end()){
            return false;
        }
        else if(mp.find(r[i])!=mp.end())
        {
            auto itr = mp.find(r[i]);
            if(itr->second >0){
                itr->second = itr->second -1;
            }
            else
                return false;
        }
        else
            return false;
    }
    return true;
}	