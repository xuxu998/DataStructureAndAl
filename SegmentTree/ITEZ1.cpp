#include <vector>
#include <iostream>
#include <climits>
using namespace std;
vector<int> segment_tree(400000,0);
vector<int> a(100001);
void build(int left,int right, int index)
{
    if(left == right)
    {
        segment_tree[index] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(left,mid,index * 2);
    build(mid + 1,right,index * 2 + 1);
    segment_tree[index] = max(segment_tree[index * 2],segment_tree[index * 2 + 1]); 
}
void update(int left,int right, int pos,int val,int index)
{
    if(pos < left or pos > right)
        return;
    if(left == right and left == pos)
    {
        segment_tree[index] = val;
        a[pos] = val;
        return;
    }
    int mid = (left + right) / 2;
    update(left,mid,pos,val,index * 2);
    update(mid + 1,right,pos,val,index * 2  +1);
    segment_tree[index] = max(segment_tree[index * 2],segment_tree[index * 2 + 1]);
}
int query(int left,int right,int qleft,int qright,int index)
{
    // cout<<left<<" "<<right<<endl;
    if(right < qleft or left > qright)
        return INT_MIN;
    if(left >= qleft and right <= qright)
        return segment_tree[index];
    int mid = (left + right) / 2;
    return max(query(left,mid,qleft,qright,index * 2),query(mid + 1,right,qleft,qright,index * 2  + 1));
}
int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
        cin>>a[i];
    build(1,n,1);
    // for(int i = 1 ; i <=  10; i++)
    //     cout<<i<<" "<<segment_tree[i]<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int qtype,pr1,pr2;
        cin>>qtype>>pr1>>pr2;
        if(qtype == 1)
        {
            update(1,n,pr1,pr2,1);
        //         for(int i = 1 ; i <=  10; i++)
        // cout<<i<<" "<<segment_tree[i]<<endl;
        }
        else
        {
            cout<<query(1,n,pr1,pr2,1)<<"\n";
        }
    }
    
}