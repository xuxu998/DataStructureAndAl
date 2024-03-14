#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <fstream>
using namespace std;
// https://oj.vnoi.info/problem/segtree_itmed
vector<long long> segment_tree(400001,0);
void update(int left, int right, int node, int index, long long val)
{
    // cout<<left<<" "<<right<<" "<<node<<endl;
    if(index < left or index > right)
        return;
    if(left == right)
    {
        if(left == index)
            segment_tree[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    update(left,mid,node * 2,index,val);
    update(mid + 1,right,node * 2 + 1,index,val);
    segment_tree[node] = max(segment_tree[node * 2],segment_tree[node * 2 + 1]);
}
long long query(int left, int right, int node, int qleft, int qright)
{
    if(qleft > right or qright < left)
        return 0;
    if(left >= qleft and right <=qright)
        return segment_tree[node];
    int mid = (left + right) / 2;
    return max(query(left, mid,node * 2, qleft,qright),query(mid + 1,right,node * 2 + 1,qleft,qright));
} 
int main()
{
    // ifstream input("in.txt");
    int n,k;
    cin>>n>>k;
    vector<long long> a(n + 1,0);
    vector<long long> f(n + 1,0);
    for(int i = 1; i <= n ; i++)
        cin>>a[i];
    f[1] = a[1];
    update(1,n,1,1,f[1]);
    long long res = max(f[1],1ll*0);
    for(int i = 2 ; i <= n ; i++)
    {
        int left_bound = ((i > k) ? i - k : 1);
        f[i] = query(1,n,1,left_bound,i - 1) + a[i];
        update(1,n,1,i,f[i]);
        res = max(res,f[i]);
    }
    cout<<res<<endl;

}