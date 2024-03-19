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
    void solve(TreeNode* root,vector<int>&v){
        if(!root) return;
        solve(root->left,v);
        v.push_back(root->val);
        solve(root->right,v);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>v;
        solve(root,v);
        int n = v.size();
        vector<vector<int>>ans;
        for(auto &x:queries){
            int x1=-1,x2=-1;
            if(v[0]>x) x1=-1,x2=v[0];
            else if(v[n-1]<x) x1=v[n-1],x2=-1;
            else{
                int k = lower_bound(v.begin(),v.end(),x)-v.begin();
                if(v[k] == x) {
                    x1=v[k],x2=v[k];
                }else{
                    x1=v[k-1],x2=v[k];
                }
            }
            ans.push_back({x1,x2});
        }
        return ans;
    }
};