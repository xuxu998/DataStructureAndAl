#include <bits/stdc++.h>
using namespace std;
// #define DFS                 
#ifdef DFS
    #define PRE_ORDER           1       
    #define IN_ORDER            2
    #define POST_ORDER          3
#endif
#ifndef DFS
    #define BFS
#endif
struct Node
{
    int data;
    Node* left;
    Node* right;
};
typedef struct Node Node;
class BinaryTree
{
    private:
    Node* root = NULL;
    int number_of_node = 0;
    public:
    BinaryTree()
    {
        cout<<"Default constructor called"<<endl;
    }
    BinaryTree(Node* node)
    {
        this->root = node;
        this->root->left = NULL;
        this->root->right = NULL;
    }
    Node* get_root()
    {
        return this->root;
    }
    void remove(int data)
    {

    }
    int get_number_of_nodes()
    {
        return this->number_of_node;
    }
    int get_height(Node * node)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return 0;
        }
        else
        {
            if(node->left != NULL && node->right != NULL)
                return max(get_height(node->left),get_height(node->right)) + 1;
            else if(node->left == NULL)
                return get_height(node->right) + 1;
            else
                return get_height(node->left) + 1;
        }
    }
    void print_current_level(Node * root,int level)
    {
        if(root == NULL)
            return;
        if(level == 0)
        {
            cout<<root->data<<" ";
        }
        else if(level > 0)
        {
            print_current_level(root->left,level - 1);
            print_current_level(root->right,level - 1);
        }
    }
    void add_node(int data)
    {
        Node * node = new Node;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        if(this->get_root() == NULL)
        {
            this->root = node;
            return;
        }
        else
        {
            Node * temp = this->get_root();
            while(temp != NULL)
            {
                if(node->data < temp->data)
                {
                    if(temp->left == NULL)
                    {
                        temp->left = node;
                        this->number_of_node++;
                        return;
                    }
                    else
                        temp = temp->left;
                    
                }
                else
                {
                    if(temp->right == NULL)
                    {
                        temp->right = node;
                        this->number_of_node++;
                        return;
                    }
                    else
                        temp = temp->right;
                }
            }
        }
    }
    #ifdef DFS
        void print_tree(Node * node,int traversal_type)
    #endif
    #ifdef BFS
        void print_tree(Node * node,Node * parent)
    #endif
    {
        #ifdef DFS
        if(node != NULL)
        {
            switch(traversal_type)
            {
                case PRE_ORDER:
                cout<<node->data<<" ";
                print_tree(node->left,PRE_ORDER);
                print_tree(node->right,PRE_ORDER);
                break;
                case IN_ORDER:
                print_tree(node->left,IN_ORDER);
                cout<<node->data<<" ";
                print_tree(node->right,IN_ORDER);
                break;
                case POST_ORDER:
                print_tree(node->left,POST_ORDER);
                print_tree(node->right,POST_ORDER);
                cout<<node->data<<" ";
                break;
            }
        }
        #endif
        #ifdef BFS
        int height = get_height(this->get_root());
        for(int i = 0; i <= height;i++)
            print_current_level(root,i);

        #endif
    }
    ~BinaryTree()
    {

    }
};
int main()
{
    // Node root = {10};
    BinaryTree binary_tree = BinaryTree();
    binary_tree.add_node(50);
    binary_tree.add_node(25);
    binary_tree.add_node(75);
    binary_tree.add_node(12);
    binary_tree.add_node(37);
    // binary_tree.add_node(43);
    // binary_tree.add_node(30);
    binary_tree.add_node(74);
    binary_tree.add_node(79);
    binary_tree.add_node(11);
    // binary_tree.add_node(1);
    #ifdef DFS
        binary_tree.print_tree(binary_tree.get_root(),PRE_ORDER);
    #endif
    #ifdef BFS
        binary_tree.print_tree(binary_tree.get_root(),binary_tree.get_root());
    #endif
    cout<<endl<<"Height of tree is: "<<binary_tree.get_height(binary_tree.get_root());
}