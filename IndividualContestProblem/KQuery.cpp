#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://oj.vnoi.info/problem/kquery
// should give TLE with 1s limit
struct query
{
    int i,j,k,ans;
};
int solve(query& in,vector<int>& segment_tree,int index, int left,int right)
{
    if(left >= in.i and right <= in.j)
        return segment_tree[index];
    if(left > in.j or right < in.i)
        return 0;
    int mid = (left + right) / 2;
    return solve(in,segment_tree,index * 2,left,mid) + solve(in,segment_tree,index * 2 + 1,mid + 1,right);
}
void update_segment_tree(vector<int>& segment_tree,int left, int right, int index_seg, int index)
{
    if(left == right)
    {
        if(left == index)
            segment_tree[index_seg] = 0;
        return;
    }
    int mid = (left + right) / 2;
    update_segment_tree(segment_tree,left,mid,index_seg * 2, index);
    update_segment_tree(segment_tree,mid + 1,right,index_seg * 2 + 1, index);
    segment_tree[index_seg] = segment_tree[index_seg * 2] + segment_tree[index_seg * 2 + 1];
}
void build(vector<int> & a,vector<int>& segment_tree, int left,int right, int index,int k)
{
    if(left == right)
    {
        if(a[left] <= k)
            segment_tree[index] = 0;
        else
            segment_tree[index] = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(a,segment_tree,left,mid,index * 2,k);
    build(a,segment_tree,mid  +1,right,index * 2 + 1,k);
    segment_tree[index] = segment_tree[index * 2] + segment_tree[index * 2 + 1];
}
void update(vector<int>& segment_tree,vector<int>& b1,vector<int>& b2,int& k, int& pre_k)
{
    int range1 = upper_bound(b1.begin(),b1.end(),k) - b1.begin();
    int range2 = upper_bound(b1.begin(),b1.end(),pre_k) - b1.begin();
    for(int i = range2 ; i < range1; i++)
    {
        update_segment_tree(segment_tree,0,b1.size() - 1,1,b2[i]);
    }
}
vector<pair<int,query>> query_list;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n;
    vector<int> a(n);
    vector<pair<int,int>> b(n);
    vector<int> b1,b2;
    vector<int> segment_tree(n * 4,0);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    cin>>q;
    query_list.resize(q);
    vector<int> ans(q);
    for(int i = 0 ; i < q; i++)
    {
        int lower,upper,k;
        cin>>lower>>upper>>k;
        query_list[i].first = i;
        query_list[i].second = {lower - 1,upper - 1,k,0};
    }
    sort(b.begin(),b.end());
    for(auto& x : b)
    {
        b1.emplace_back(x.first);
        b2.emplace_back(x.second);
    }
    auto query_comparator = [&](pair<int,query>& f, pair<int,query>& s)
    {
        return f.second.k < s.second.k;
    };
    sort(query_list.begin(),query_list.end(),query_comparator);
    int pre_k = query_list[0].second.k;
    build(a,segment_tree,0,n - 1,1,pre_k);
    for(int i = 0 ; i < q; i++)
    {
        if(pre_k != query_list[i].second.k)
        {
            update(segment_tree,b1,b2,query_list[i].second.k,pre_k);
            pre_k = query_list[i].second.k;
        }
        ans[query_list[i].first] = solve(query_list[i].second,segment_tree,1,0,n - 1);
    }
    for(auto& x : ans)
    {
        cout<<x<<endl;
    }
}