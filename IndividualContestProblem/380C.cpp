#include <iostream>
#include <vector>
using namespace std;
// https://codeforces.com/contest/380/problem/C
class Node
{
    public: 
        int best;
        int remaining_close;
        int remaining_open;
    Node(int b, int rm_close,int rm_open) : best(b), remaining_close(rm_close),remaining_open(rm_open)
    {

    }
    Node()
    {

    }
    Node operator + (const Node& node)
    {
        Node res(0,0,0);
        int temp = min(this->remaining_close,node.remaining_open);
        res.best = this->best + node.best + 2 * temp;
        res.remaining_close = this->remaining_close + node.remaining_close - temp;
        res.remaining_open = this->remaining_open + node.remaining_open - temp;
        return res;
    }
    friend ostream & operator << (ostream & out,const Node & node)
    {
        out<<node.best<<" "<<node.remaining_close<<" "<<node.remaining_open;
        return out;
    }
};
Node query(int left, int right,int qleft, int qright, int index, vector<Node>& segment_tree,const string& s)
{
    if(qright < left or qleft > right)
        return Node(0,0,0);
    if(left >= qleft and right <= qright)
        return segment_tree[index];
    int mid = (left + right) / 2;
    return query(left,mid,qleft,qright,index * 2,segment_tree,s) + query(mid + 1,right,qleft,qright,index * 2 + 1,segment_tree,s);
}
void build(int left, int right, int index,vector<Node>& segment_tree,const string& s)
{
    if(left == right)
    {
        if(s[left] == '(')
            segment_tree[index] = Node(0,1,0);
        else
            segment_tree[index] = Node(0,0,1);
        return;
    }
    int mid = (left + right) / 2;
    build(left,mid,2 * index,segment_tree,s);
    build(mid + 1,right,2 * index + 1,segment_tree,s);
    segment_tree[index] = segment_tree[2 * index] + segment_tree[2 * index + 1];
    return;
}
int main()
{
    string s;
    cin>>s;
    vector<Node> segment_tree(s.size() * 4,Node(0,0,0));
    int nquery;
    cin>>nquery;
    build(0,s.size() - 1,1,segment_tree,s);
    while(nquery--)
    {
        int qleft,qright;
        cin>>qleft>>qright;
        cout<<query(0,s.size() - 1,qleft - 1,qright - 1,1,segment_tree,s).best<<endl;
    }
}