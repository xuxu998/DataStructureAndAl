#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a = 1,b= 1, c = 1;
    for(int i = 4 ; i <= n ; i++)
    {
        c++;
        if(c == 27)
        {
            c = 26;
            b++;
        }
        if(b == 27)
        {
            b = 26;
            a++;
        }
    }
    cout<<char(a + 96)<<char(b + 96)<<char(c + 96)<<endl;
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