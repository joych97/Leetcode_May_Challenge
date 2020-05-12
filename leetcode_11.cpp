/*
In this we are using queue and pair data structure. We add all the valid indexes after verifying their ranges and color and we make
sure that we also populate these pairs in a set so that we don't duplicate our entries in the queue. And before each queue element is
processed we do check all its valid 4 coordinates and then pop the  value from the queue.

*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row= image.size();
        int col = image[0].size();
        int a[row][col];
        
        int i=0;
        for(auto itr = image.begin(); itr!= image.end() ; ++itr,i++){
          int  j=0;
            for(auto it = itr->begin();it!= itr->end();++it,j++){
                a[i][j] = *it;
            }
        }
        int oldClr = a[sr][sc];
        pair<int, int> pr= make_pair(sr,sc);
        queue<pair<int , int>> q;
        q.push(pr);
        set<pair<int,int>>st;
        st.insert(pr);
        while(!q.empty()){
            int i=q.front().first;
            int j =q.front().second;
            if(validateIndex(i-1,j,row,col)){
                 pair temp = make_pair(i-1,j);
                if(a[i-1][j]==oldClr && st.find(temp)== st.end()){
                    q.push(temp);
                    st.insert(temp);
                }
            }
            if(validateIndex(i+1,j,row,col)){
                 pair temp = make_pair(i+1,j);
                if(a[i+1][j]==oldClr && st.find(temp)== st.end()){
                   st.insert(temp);
                    q.push(temp);
                }
            }    
            
            if(validateIndex(i,j-1,row,col)){
                pair temp = make_pair(i,j-1);
                if(a[i][j-1]==oldClr && st.find(temp)== st.end()){
                    st.insert(temp);
                    q.push(temp);
                }
            }
            if(validateIndex(i,j+1,row,col)){
                pair temp = make_pair(i,j+1);
                if(a[i][j+1]==oldClr && st.find(temp)== st.end()){ 
                    st.insert(temp);
                    q.push(temp);
               }
            }
            a[i][j]=newColor;
            q.pop();
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }
        vector<vector<int>>vec(row);
        for(int i=0;i<row;i++){
            vec[i] = vector<int>(col); 
            for(int j=0;j<col;j++){
                vec[i][j]=a[i][j];
            }
        }
        return vec;
    }
    
    bool validateIndex(int i, int j , int row , int col){
        int rowFlag=0;
        int colFlag=0;
        
        if(i>=0 && i<row){
            rowFlag=1;
        }
        if(j>=0 && j<col){
            colFlag=1;
        }
        
        if(rowFlag==1 && colFlag==1){
            return true;
        }
        else
            return false;    
    }
};