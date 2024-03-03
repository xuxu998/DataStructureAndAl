#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ntest;
    cin>>ntest;
    while(ntest--)
    {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (n % 2) {
            cout << "-1\n";
        } else {
            cout<<n<<" ";
            for (int i = 1; i < n; ++i) {
                cout<<i<<" ";
            }
            cout << "\n";
        }
    }
}