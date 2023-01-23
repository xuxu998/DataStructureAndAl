#include <iostream>
using namespace std;
void TowerOfHanoi(int n,char source = 'A', char destination = 'C', char intermediary = 'B')
{
    if(n == 0)
    {
        return;
    }
    TowerOfHanoi(n-1,source,intermediary,destination);//A,B,C
    cout<< "Moving disk "<< n << " from " << source << " to " << destination<<endl;
    TowerOfHanoi(n-1,intermediary,destination,source);//B,C,A

}
int main(void)
{
    TowerOfHanoi(5);
    return 0;
}