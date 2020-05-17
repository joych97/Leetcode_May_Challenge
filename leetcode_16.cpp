/*
We create an array of 26 chars and we populate each cell by the value from the p string. Now for the first pass we iterate through
the entire s substring from 0 to m and we try to reduce the value of each cell by 1 and after this pass we check if we have a possible
answer by checking if there are all 0's in the array. Now when we start for 1 we do not need to recalculate the value of each position
from 1 to m+1 because we already did that for 0 index. Hence just reverse the changes done for the first index that is increase it's
value by 1 and decrease the value of m+1 index and check if we find a possible answer.
*/


class Solution {
public:
    bool checkArray(int a[]) {
        for(int i=0;i<26;i++){
            if(a[i]!=0)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int m = p.size();
        int n = s.size();
         if(m<=n){
        vector<int> v;
        int a[26]={0};
        int i,j;
        for(i=0;i<m;i++){
            a[((int)p[i])-97] =  a[((int)p[i])-97] +1;
        }
        
        for(i=0;i<m;i++){
            a[((int)s[i])-97] = a[((int)s[i])-97] -1;
        }
        if(checkArray(a)){
            v.push_back(0);
        }
        
        for(i=1;i<=n-m;i++){
            a[((int)s[i-1])-97] = a[((int)s[i-1])-97]+1;
            a[((int)s[i+m-1])-97] = a[((int)s[i+m-1])-97]-1;
           if(checkArray(a)){
             v.push_back(i);
           }
        }
        return v;
    }
    else{
        vector<int>v={};
        return v;
    }
    }
};