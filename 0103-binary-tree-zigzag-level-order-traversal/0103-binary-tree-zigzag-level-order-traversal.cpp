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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    if(root!=NULL)  {q.push(root);} 
    bool leftToRight=true;
    while(!q.empty())
    {int n=q.size();
    vector<int>level(n);
    for(int i =0;i<n;i++)
    {TreeNode* temp = q.front();
    q.pop();
    if(temp->left!=NULL){q.push(temp->left);}
    if(temp->right!=NULL){q.push(temp->right);}
    //search for an index
    int index=leftToRight?i:n-1-i;
    level[index]=temp->val;}
    //change the order
    leftToRight=!leftToRight;
    ans.push_back(level);}
    return ans;
    }
};