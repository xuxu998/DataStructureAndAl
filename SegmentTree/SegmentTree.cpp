#include <bits/stdc++.h>
using namespace std;
// #define DEBUG
// #define DEBUG_UPDATE
#define MAX_SEG_TREE
// #define MIN_SEG_TREE
#ifdef MAX_SEG_TREE
    #define TEMP tree_max
    #define TREE_UPDATE max
#endif
#ifdef MIN_SEG_TREE
    #define TEMP tree_min
    #define TREE_UPDATE min
#endif

class segment_tree
{
    public:
        vector<int> raw;
        vector<int> tree_max;
        vector<int> tree_min;
        segment_tree(const vector<int>& raw_)
        {
            this->raw = raw_;
            this->tree_max.resize(this->raw.size() * 4 + 1,0);
            this->tree_min.resize(this->raw.size() * 4 + 1,0);
            #ifdef MAX_SEG_TREE
                build_max(1,0,this->raw.size() - 1);
            #endif
            #ifdef MIN_SEG_TREE
                build_min(1,0,this->raw.size() - 1);
            #endif
        }
        #ifdef MAX_SEG_TREE
        int build_max(int index,int head,int tail)
        {
            #ifdef DEBUG
                cout<<"Build range: ["<<head<<","<<tail<<"] at "<<index<<endl;
            #endif
            if(head == tail)
                return this->tree_max[index] = this->raw[head];
            return this->tree_max[index] = max(build_max(2 * index + 1,(head + tail) / 2 + 1,tail),build_max(2 * index,head,(head + tail) / 2));
        }
        int get_max(const int left_q,const int right_q,int tree_left,int tree_right,int index = 1)
        {
            // cout<<left_q<<" "<<right_q<<" "<<tree_left<<" "<<tree_right<<" "<<(tree_left + tree_right) / 2<<endl;
            if(tree_left >= left_q and tree_right <= right_q)
                return this->tree_max[index];
            int mid = (tree_left + tree_right) / 2;
            if(mid >= right_q)
            {
                return get_max(left_q,right_q,tree_left,mid,index * 2);
            }
            else if(mid < left_q)
            {
                return get_max(left_q,right_q,mid + 1,tree_right,index * 2  + 1);
            }
            else
            {
                return max(get_max(left_q,right_q,tree_left,mid,index * 2),get_max(left_q,right_q,mid + 1,tree_right,index * 2  + 1));
            }
            
        }
        #endif
        #ifdef MIN_SEG_TREE
        int build_min(int index,int head,int tail)
        {
            #ifdef DEBUG
                cout<<"Build range: ["<<head<<","<<tail<<"] at "<<index<<endl;
            #endif
            if(head == tail)
                return this->tree_min[index] = this->raw[head];
            return this->tree_min[index] = min(build_min(2 * index + 1,(head + tail) / 2 + 1,tail),build_min(2 * index,head,(head + tail) / 2));
        }
        int get_min(int i, int j)
        {
            return 0;
        }
        #endif
        void update(const int i,int val,int head, int tail,int index = 1)
        {
            #ifdef DEBUG_UPDATE
                cout<<"Update range: ["<<head<<","<<tail<<"] at "<<index<<endl;
            #endif
            if(tail == head)
            {
                this->TEMP[index] = val;
                this->raw[i] = val;
                return;
            }
            if(i <= (head + tail) / 2)
            {
                update(i,val,head,(head + tail) / 2,index * 2);
            }
            else
                update(i,val,(head + tail) / 2 + 1,tail,index * 2 + 1);
            this->TEMP[index] = TREE_UPDATE(this->TEMP[2 * index],this->TEMP[2 * index + 1]);
        }
        void print_tree()
        {
            for(auto& x : raw)
                cout<<x<<" ";
            cout<<endl;
        }
};
int main()
{
    ofstream output("out.txt");
    ifstream input("in.txt");
    int ntest;
    input>>ntest;
    while(ntest--)
    {
        int n, nquery;
        input>>n>>nquery;
        vector<int> a(n);
        for(auto& x : a)
            input >> x;
        segment_tree st(a);
        int query_type, para1, para2;
        for(int i = 1 ; i <= nquery ; i++)
        {
            input >> query_type >> para1 >> para2;
            if(query_type == 1)
            {
                st.update(para1,para2,0,a.size() - 1);
                // st.print_tree();
            }
            else
            {
                output << st.get_max(para1,para2,0,a.size() - 1)<<endl;
                // st.print_tree();
            }
        }
    }
}