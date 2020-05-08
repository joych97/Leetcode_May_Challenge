/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
In this you just have to do level order traversal and see if the elements are present in the same level and if they are present they
should not be of the same parent. For this I have used two flags to make sure they are not of the same parent.
And to make sure they are in the same level I always insert one NULL node at the end so that when I reach that node I know that I have 
reached the end of one level and when I reach the NULL node I just see the value of the two flags and if they are both 1 then return 
true and if they are both 0 then I have to continue to process as I have not found any of the given values and I insert a new NULL node 
but only if the queue is not empty otherwise I will keep on looping the queue if that's the last element. If the flags have anything 
other than this then I return false.
*/


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    int flagX =0,flagY=0;
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp!=NULL){
            if(temp->left!=NULL){
                q.push(temp->left);
                if(temp->left->val == x){
                    flagX=1;
                if(temp->right!=NULL){
                    if(temp->right->val == y)
                        return false;
                    }
                }
                if(temp->left->val == y){
                    flagY=1;
                    if(temp->right!=NULL){
                        if(temp->right->val == x)
                            return false;
                        }
                    }
                }
            if(temp->right!=NULL){
                q.push(temp->right);
                if(temp->right->val == x){
                    flagX=1;
                if(temp->left!=NULL){
                    if(temp->left->val == y)
                         return false;
                }}
            if(temp->right->val == y){
                    flagY=1;
                if(temp->left!=NULL){
                    if(temp->left->val == x)
                        return false;
                    }
                }
            }
        }
        else{
            if(flagX==1&& flagY==1)
                return true;
            else if(flagX==1||flagY==1)
                return false;
            if(!q.empty())
                q.push(NULL);           
        }
    }
    return false;
    }
    
};