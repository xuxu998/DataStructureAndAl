#include <iostream>
#include <vector>
#include <algorithm>
// https://oj.vnoi.info/problem/kquery
using namespace std;
vector<vector<int>> segment_tree(120001);
vector<int> a(30001,0);
vector<int> merge(vector<int>& lnode, vector<int>& rnode)
{
    vector<int> res;
    int lptr = 0,rptr = 0;
    int lsize = lnode.size(), rsize = rnode.size();
    while(lptr < lsize or rptr < rsize)
    {
        if(lptr == lsize)
        {
            res.emplace_back(rnode[rptr++]);
        }
        else if(rptr == rsize)
        {
            res.emplace_back(lnode[lptr++]);
        }
        else
        {
            if(lnode[lptr] < rnode[rptr])
                res.emplace_back(lnode[lptr++]);
            else
                res.emplace_back(rnode[rptr++]);
        }
    }
    return res;
}
void build(int left, int right,int index)
{
    int mid = (left + right) / 2;
    if(left == right)
    {
        segment_tree[index] = {a[left]};
        return;
    }
    build(left, mid, index * 2);
    build(mid + 1, right, index * 2 + 1);
    segment_tree[index] = merge(segment_tree[index * 2],segment_tree[index * 2 + 1]);
}
int query(int left,int right, int& qleft,int& qright, int index,int& k)
{
    if(qleft > right or qright < left)
        return 0;
    if(left >= qleft and right <= qright)
    {
        return segment_tree[index].end() - upper_bound(segment_tree[index].begin(),segment_tree[index].end(),k);
    }
    int mid = (left + right) / 2;
    return query(left,mid,qleft,qright,index * 2,k) + query(mid + 1,right,qleft,qright,index * 2 + 1,k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
        cin>>a[i];
    build(1,n,1);
    int q;
    cin>>q;
    while(q--)
    {
        int i,j,k;
        cin>>i>>j>>k;
        cout<<query(1,n,i,j,1,k)<<"\n";
    }
    // vector<int> a = {1,2,3,10,20,30,31};
    // vector<int> b = {4,5,7,8,9,15};
    // for(auto& x : merge(a,b))
    //     cout<<x<<" ";
}