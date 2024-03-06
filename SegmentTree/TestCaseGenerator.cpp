#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <random>
#include <functional>
#include <chrono>
using namespace std;

#define rand dis(rand_engine)
#define query_rand query_type(rand_engine)
#define index_rand index(rand_engine)
#define update_query    1
#define get_max_query   2
#define seed_change rand_engine.seed(chrono::system_clock::now().time_since_epoch().count() % 1000007);

uniform_int_distribution<int> int_uni_distribution_range(int lower_bound, int upper_bound)
{
    uniform_int_distribution<int> random_number_range(lower_bound,upper_bound);
    return random_number_range;
}
int main()
{
    int number_of_test;
    ofstream output("in.txt");
    default_random_engine rand_engine;
    auto dis = int_uni_distribution_range(1,1000);
    auto query_type = int_uni_distribution_range(1,2);
    // auto get_random = bind(int_uni_distribution_range(1,150),rand_engine);
    seed_change
    number_of_test = rand;
    cout<<"Generate "<<number_of_test<<" testcase"<<endl;
    output<<number_of_test<<endl;
    for(int i = 1 ; i <= number_of_test ; i++)
    {
        int array_length,number_of_query;
        seed_change
        array_length = rand;
        seed_change
        number_of_query = rand;
        output<<array_length<<" "<<number_of_query<<endl;
        auto index = int_uni_distribution_range(0,array_length - 1);
        for(int j = 1; j <= array_length ; j++)
        {
            seed_change
            output << rand <<" ";
        }
        output<<endl;
        for(int nquery = 1 ; nquery <= number_of_query ; nquery++)
        {
            seed_change
            auto qtype = query_rand;
            if(qtype == update_query)
            {
                seed_change
                output << qtype <<" "<<index_rand<<" "<<rand<<endl;
            }
            else
            {
                seed_change
                int first_index = index_rand;
                int second_index = index_rand;
                if(first_index > second_index)
                    swap(first_index,second_index);
                output << qtype << " "<<first_index<<" "<<second_index<<endl;
            }
        }
    }
    cout<<"Generate "<<number_of_test<<" testcase done"<<endl;
}