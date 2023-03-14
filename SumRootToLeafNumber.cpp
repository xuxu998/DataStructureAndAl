// https://leetcode.com/problems/sum-root-to-leaf-numbers/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int sum = 0;
int helper(TreeNode* root, string result)
{
    result.push_back(root->val+48);
    if(root->left == NULL && root->right == NULL)
        sum = sum + stoi(result);
    else
    {
        if (root->left != NULL)
            helper(root->left,result);
        if(root->right != NULL)
            helper(root->right,result);
    }
}
int sumNumbers(TreeNode* root) {
    helper(root,"");
    cout<<sum;
    return sum;
}
int main()
{
    TreeNode node1;
    TreeNode node2;
    TreeNode node3;
    TreeNode node4;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node4.val = 4;
    node1.val  = 1;
    node2.val = 2;
    node3.val = 3;
    sumNumbers(&node1);

}