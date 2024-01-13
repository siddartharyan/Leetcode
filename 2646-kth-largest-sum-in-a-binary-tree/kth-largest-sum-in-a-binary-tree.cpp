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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>t;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            long long s  = 0;
            while(n--){
                TreeNode* l = q.front();
                q.pop();
                if(l->left) q.push(l->left);
                if(l->right) q.push(l->right);
                s+=l->val;
            }
            t.push_back(s);
        }
        int l = t.size();
        if(k>l) return -1;
        sort(t.begin(),t.end(),greater<long long>());
        return t[k-1];
    }
};