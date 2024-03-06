#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// https://oj.vnoi.info/problem/gss
struct node{
    bool valid;
    int m,M,res;
    node(int min_,int max_,int r,bool val) : m{min_},M{max_},res{r},valid{val}
    {
        
    }
    node()
    {

    }
    friend ostream& operator <<(ostream &out,const node& n)
    {
        out << n.m <<" "<<n.M<<" "<<n.res;
        return out;
    }
};
node merge(const node& left,const node& right)
{
    if(left.valid and right.valid)
        return node(min(left.m,right.m),max(left.M,right.M),max({left.res,right.res,right.M - left.m}),true);
    if(!left.valid)
        return right;
    if(!right.valid)
        return left;
    return node(0,0,0,false);
}
void build(int left,int right,int index,vector<node>& segment_tree,vector<int>& f,vector<int>& a)
{
    if(left == right)
    {
        segment_tree[index] = node(f[left - 1],f[left],a[left],true);
        return;
    }
    int mid = (left + right) / 2;
    build(left,mid,index * 2, segment_tree ,f,a);
    build(mid + 1,right,index * 2 + 1,segment_tree,f,a);
    segment_tree[index] = merge(segment_tree[index * 2],segment_tree[index * 2 + 1]);
}
node query(int qleft,int qright, int left, int right,int index, vector<node>& segment_tree)
{
    if(left >= qleft and right <= qright)
        return segment_tree[index];
    if(left > qright or right < qleft)
        return node(0,0,0,false);
    int mid = (left + right) / 2;
    return merge(query(qleft,qright,left,mid,index * 2,segment_tree),query(qleft,qright,mid + 1,right,index * 2 + 1,segment_tree));
}
int main()
{
    int n,q;
    cin>>n;
    vector<int> a(n + 1);
    vector<node> segment_tree(n * 4);
    vector<int> f(n + 1,0);
    for(int i = 1; i <= n ; i++)
        cin>>a[i];
    for(int i = 1; i <= n ; i++)
        f[i]  = f[i - 1] + a[i];
    build(1,n,1,segment_tree,f,a);
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<query(x,y,1,n,1,segment_tree).res<<"\n";
    }
}