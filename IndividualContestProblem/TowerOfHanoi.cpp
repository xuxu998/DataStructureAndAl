// #include <iostream>
// using namespace std;
// void TowerOfHanoi(int n,char source = 'A', char destination = 'C', char intermediary = 'B')
// {
//     if(n == 0)
//     {
//         return;
//     }
//     TowerOfHanoi(n-1,source,intermediary,destination);//A,B,C
//     cout<< "Moving disk "<< n << " from " << source << " to " << destination<<endl;
//     TowerOfHanoi(n-1,intermediary,destination,source);//B,C,A

// }
// int main(void)
// {
//     TowerOfHanoi(5);
//     return 0;
#include <bits/stdc++.h>
using namespace std;
int count1= 1;
void solve()
{
    count1++;
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& x : a)
        cin>>x;
    int count1 = 1 , count2 = 1;
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i] == a[i - 1])
            count1++;
        else
            break;
    }
    for(int i = n - 2; i >= 0 ; i--)
    {
        if(a[i] == a[i + 1])
            count2++;
        else
            break;
    }
    if(a[0] == a.back())
    {
        if(count1 == n)
        {
            cout<<0<<endl;
            return;
        }
        cout<<n - count1 - count2<<endl;
    }
    else
    {
        cout<<min(n - count1,n -count2)<<endl;
        return;
    }
    
    
}
int main()
{
    int ntest;
    cin>>ntest;
    while(ntest--)
    {
        solve();
    }
}