// https://leetcode.com/problems/symmetric-tree/
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
class Solution {
public:

    vector<int> value_list;
    map<int,int> node_number_level;
    int get_height(TreeNode* root)
    {
        if(root != NULL)
            return 1 + max(get_height(root->left),get_height(root->right));
        else
            return 0;
    }
    void helper(TreeNode* root,int level,int reference)
    {
        if(root != NULL)
        {
            if(level == 1)
            {
                value_list.push_back(root->val);
                if(node_number_level.find(reference) != node_number_level.end())
                {
                    node_number_level[reference]++;
                }
                else
                {
                    node_number_level[reference] = 1;
                }
                return;
            }
            else
            {
                helper(root->left,level - 1,reference);
                helper(root->right,level - 1,reference);
            }
        }
        else
        {
            /* code */
            if(level == 1)
            {
                if(node_number_level.find(reference) != node_number_level.end())
                {
                    node_number_level[reference]++;
                }
                else
                {
                    node_number_level[reference] = 1;
                }
                value_list.push_back(-101);
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        int tree_height = get_height(root);
        stack<int> stack_;
        stack<int> index_;
        vector<int> side_;
        bool is_count =false;
        int temp = 2;
        if(root == NULL)
        {
            return false;
        }
        for(int i = 1;i <= tree_height; i++)
        {
            helper(root,i,i);
        }
        for(size_t i = 0 ; i < value_list.size(); i++)
        {
            side_.push_back(2);
        }
        for(size_t i = 1 ; i < value_list.size(); i++)
        {
            if(side_[i] == 2)
            {
                int temp1 = node_number_level[temp] / 2;
                int temp2 = temp1;
                int j = i;
                while(temp1 != 0)
                {
                    side_[j] = 0;
                    temp1--;
                    j++;
                }
                while(temp2 != 0)
                {
                    side_[j] = 1;
                    temp2--;
                    j++;
                }
                temp++;
            }
        }
        for(size_t i = 1 ; i < value_list.size(); i++)
        {
            if(!stack_.empty())
            {
                if(stack_.top() == value_list[i] && side_[i]!= side_[index_.top()])
                {
                    index_.pop();
                    stack_.pop();
                }
                else
                {
                    stack_.push(value_list[i]);
                    index_.push(i);
                    /* code */
                }
            }
            else
            {
                index_.push(i);
                stack_.push(value_list[i]);
            }
        }
        return stack_.empty();
}
};