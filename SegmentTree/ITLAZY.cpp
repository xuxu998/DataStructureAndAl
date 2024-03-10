#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<long long> segment_tree(400001);
vector<long long> a(100001);
vector<long long> lazy(400001,0);
void down(int index)
{
    segment_tree[index * 2] += lazy[index];
    segment_tree[index * 2 + 1] += lazy[index];
    lazy[index * 2] += lazy[index];
    lazy[index * 2 + 1] += lazy[index];
    lazy[index] = 0;
}
void build(int left, int right, int index)
{
    if(left == right)
    {
        segment_tree[index] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(left, mid,index * 2);
    build(mid + 1,right, index * 2 + 1);
    segment_tree[index] = max(segment_tree[index * 2],segment_tree[index * 2 + 1]);
}
void update(int left ,int right, int qleft, int qright, int val, int index)
{
    if(left > qright or right < qleft)
        return;
    if(left >= qleft and right <= qright)
    {
        lazy[index] += val;
        segment_tree[index] += val;
        return;
    }
    int mid = (left + right) / 2;
    down(index);
    update(left,mid,qleft,qright,val,index *  2);
    update(mid + 1,right, qleft,qright,val,index * 2 + 1);
    segment_tree[index] = max(segment_tree[index * 2],segment_tree[index * 2 + 1]); 
}
long long query(int left, int right, int qleft, int qright, int index)
{
    if(left > qright or right < qleft)
        return INT_MIN;
    if(left >= qleft and right <= qright)
        return segment_tree[index];
    down(index);
    int mid = (left + right) / 2;
    return max(query(left,mid, qleft,qright,index * 2),query(mid + 1,right, qleft,qright, index * 2 + 1));
}
int main()
{
    int n,q;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>a[i];
    }
    build(1,n,1);
    cin>>q;
    while(q--)
    {
        int qtype,p1,p2;
        cin>>qtype>>p1>>p2;
        if(qtype == 1)
        {
            int val;
            cin>>val;
            update(1,n,p1,p2,val,1);
            // for(int i = 1; i <= 8 ; i++)
            // {
            //     cout<<i<<" "<<segment_tree[i]<<" "<<lazy[i]<<endl;
            // }
        }
        else
            cout<<query(1,n,p1,p2,1)<<"\n";
    }
}