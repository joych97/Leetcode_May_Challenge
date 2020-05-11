/*
In this we create 2 sets each for people and judge and we each time we fill value in people's set we make sure that the value is not 
present in the judge set otherwise we remove that value from the judge set.

When we are trying to insert values in judge set we make sure what we are inserting is not present already in the people's set
otherwise we don't insert the value in the set.

After we are done inserting the values if we get anything other than only one value in the Judge set then that means we are not sure 
hence return -1. Else we iterate the vector again and see if all the values present in the people's set have  at least one mapping to the
single value present in the judge set.


In the beginning we also make sure that if there are no mappings present in the set then we look for the no of people N if it is 1 
then return 1 else return -1 as we are not sure of the judge as there are more than one people and no mappings are present.

*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& vvi) {
        set<int>ppl{};
        set<int>judge{};
        int n= vvi.size();
        if(n!=0){
        int  v[n][2];
        int j=0,i=0;
        vector< vector<int> >::iterator row;
        vector<int>::iterator col;
        for (row = vvi.begin(); row != vvi.end(); row++,j++) {
        for (col = row->begin(),i=0; col != row->end(); col++,i++) {
             v[j][i]=*col;        
            }
        }  
        for(int i=0;i<n;i++){
            if(judge.find(v[i][0])==judge.end()){
                ppl.insert(v[i][0]);
            }
            else{
                judge.erase(v[i][0]);
                ppl.insert(v[i][0]);
            }
            
            if(ppl.find(v[i][1])==ppl.end()){
                judge.insert(v[i][1]);
            }
        }
        
        if(judge.size()!=1)
            return -1;
        
        for(int i=0;i<n;i++){
           if(v[i][1]== *(judge.begin()))
                ppl.erase(v[i][0]);
        }

        if(ppl.empty())
          return *(judge.begin());
        else
            return -1;
        }
        else{
            if(N!=1)
            return -1;
            else
                return 1; 
        }
    }
};

// A reduced version of the above code.
/*
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& vvi) {
        set<int>ppl{};
        set<int>judge{};
        int n= vvi.size();
        if(n!=0){
        int  v[n][2];
        int j=0;
        for (auto row = vvi.begin(); row != vvi.end(); row++,j++) {
            int i=0;
        for (auto col = row->begin(); col != row->end(); col++,i++) {
             v[j][i]=*col;        
            }
        }  
        for(int i=0;i<n;i++){
             ppl.insert(v[i][0]);
            if(judge.find(v[i][0])!=judge.end()){
                judge.erase(v[i][0]);
            }
            if(ppl.find(v[i][1])==ppl.end()){
                judge.insert(v[i][1]);
            }
        }
        
        if(judge.size()!=1)
            return -1;
        
        for(int i=0;i<n;i++){
           if(v[i][1]== *(judge.begin()))
                ppl.erase(v[i][0]);
        }

        if(ppl.empty())
          return *(judge.begin());
        else
            return -1;
        }
        else{
            if(N!=1)
            return -1;
            else
                return 1; 
        }
    }
};
*/