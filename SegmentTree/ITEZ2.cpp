#include <iostream>
#include <vector>
using namespace std;
vector<long long> segment_tree(400001,0);
void update(int left, int right, int pos,int val,int index)
{
    if(pos < left or pos > right)
        return;
    if(left == right and pos == left)
    {
        segment_tree[index] = val;
        return;
    }
    int mid = (left + right) / 2;
    update(left,mid,pos,val,index * 2);
    update(mid + 1,right,pos,val,index * 2 + 1);
    segment_tree[index] = segment_tree[index * 2] + segment_tree[index * 2 + 1];
}
long long query(int left, int right, int qleft, int qright, int index)
{
    if(left > qright or right < qleft)
        return 0;
    if(left >= qleft and right <= qright)
        return segment_tree[index];
    int mid = (left + right) / 2;
    return query(left, mid, qleft,qright,index * 2) + query(mid + 1,right,qleft,qright,index * 2 + 1);
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i = 1; i <= q; i++)
    {
        int qtype, p1,p2;
        cin>>qtype>>p1>>p2;
        if(qtype == 1)
        {
            update(1,n,p1,p2,1);
        }
        else
            cout<<query(1,n,p1,p2,1)<<"\n";
    }
}