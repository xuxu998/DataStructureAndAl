#include <iostream>
using namespace std;
long long square(int a)
{
    return a * a;
}
int power_of(int a, int b)
{
    if(b == 0)
        return 1;
    if(b % 2 == 0)
        return square(power_of(a,b/2));
    return a * square(power_of(a,(b - 1) / 2));
}
int main()
{
    cout<<power_of(10,2)<<endl;
    cout<<power_of(5,2)<<endl;
    cout<<power_of(6,2)<<endl;
    cout<<power_of(7,2)<<endl;
    cout<<power_of(5,3)<<endl;
    cout<<power_of(2,10)<<endl;
}