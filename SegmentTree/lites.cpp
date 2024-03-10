#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> segment_tree(400001);
vector<int> flag(400001);
void update(int qleft, int qright, int left, int right, int index)
{
    if(left > qright or right < qleft)
        return;
    if(left >= qleft and qright >= right)
    {
        flag[index] ^= 1;
        segment_tree[index] = (right - left + 1) - segment_tree[index];
        return;
    }
    int mid = (left + right) / 2;
    update(qleft,qright,left,mid, index * 2);
    update(qleft,qright,mid + 1,right,index * 2 + 1);
    segment_tree[index] = segment_tree[index * 2] + segment_tree[index * 2 + 1];
    if(flag[index])
        segment_tree[index] = (right - left + 1) - segment_tree[index];
}
int query(int qleft, int qright, int left, int right, int index, int flag_)
{
    if(left > qright or right < qleft)
        return 0;
    if(left >= qleft and right <= qright)
    {
        if(flag_)
            return (right - left + 1) - segment_tree[index];
        return segment_tree[index];
    }
    int mid = (left + right) / 2;
    return query(qleft ,qright,left , mid,index * 2,flag[index] ^ flag_) + query(qleft,qright,mid + 1,right,index * 2 + 1,flag[index] ^ flag_);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int qtype,s,e;
        cin>>qtype>>s>>e;
        if(qtype == 0)
        {
            update(s,e,1,n,1);
            // for(int i = 1 ; i <= 8 ; i++)
            //     cout<<i<<" "<<segment_tree[i]<<" Flag: "<<flag[i]<<endl;
        }
        else
        {
            // for(int i = 1 ; i <= 8 ; i++)
            //     cout<<i<<" "<<segment_tree[i]<<endl;
            cout<<query(s,e,1,n,1,0)<<endl;
        }
    }
}