#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream output("out.txt");
    ifstream input("in.txt");
    ofstream report("res.txt");
    int ntest;
    int count = 1;
    int total_passed = 0,total_failed = 0,total =0;
    input >> ntest;
    // query type 1 change value at index i to val
    // query type 2 get max from index i to j
    cout<<"Number of test performed: "<<ntest<<endl;
    while(ntest--)
    {
        cout<<"TEST NUMBER: "<<count++<<endl;
        int n, nquery;
        input >> n >> nquery;
        total += nquery;
        vector<int> array(n);
        for(int& x : array)
            input>>x;
        int query_type, para1, para2;
        for(int i = 1 ; i <= nquery ; i++)
        {
            input >> query_type >> para1 >> para2;
            if(query_type == 1)
            {
                array[para1] = para2;
                // cout<<"PASSED at query "<<i<<endl;
                total_passed++;
            }
            else
            {
                int max_ = INT_MIN;
                for(int j = para1 ; j <= para2 ; j++)
                {
                    max_ = max(max_,array[j]);
                }
                int res;
                output >> res;
                if(res == max_)
                {
                    // cout<<"PASSED at query "<<i<<endl;
                    // report<<"PASSED at query "<<i<<" with input "<<query_type<<" "<<para1<<" "<<para2<<endl;
                    // report<<"Expected result "<<max_<<" Received: "<<res<<endl;
                    // report<<"____________________________________________________________"<<endl;
                    total_passed++;
                }
                else
                {
                    report<<"FAILED at query "<<i<<" with input "<<query_type<<" "<<para1<<" "<<para2<<endl;
                    report<<"Expected result "<<max_<<" Received: "<<res<<endl;
                    report<<"____________________________________________________________"<<endl;
                    total_failed++;
                }
            }
        } 
    }
    cout<<"TEST DONE!"<<endl;
    cout<<"PASSED / TOTAL: "<<total_passed <<"/"<<total<<endl;
    cout<<"FAILED / TOTAL: "<<total_failed <<"/"<<total<<endl;
    report<<"PASSED / TOTAL: "<<total_passed <<"/"<<total<<endl;
    report<<"FAILED / TOTAL: "<<total_failed <<"/"<<total<<endl;
}