#include<bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> main_stack;
    stack<int> sub_stack;
    MyQueue() {
      
    }
    
    void push(int x) {
        // while(!main_stack.empty())
        // {
        //     this->sub_stack.push(main_stack.top());
        //     this->main_stack.pop();
        // }
        // this->main_stack.push(x);
        // while(!sub_stack.empty())
        // {
        //     this->main_stack.push(sub_stack.top());
        //     this->sub_stack.pop();
        // }
        this->main_stack.push(x);
    }
    
    int pop() {
        int length = main_stack.size();
        while(!main_stack.empty())
        {
            if(length == 1)
            {
                break;
            }
            length--;
            this->sub_stack.push(main_stack.top());
            this->main_stack.pop();
        }
        int result = main_stack.top();
        main_stack.pop();
        while(!sub_stack.empty())
        {
            this->main_stack.push(sub_stack.top());
            this->sub_stack.pop();
        }
        return result;
    }
    
    int peek() {
        int length = main_stack.size();
        while(!main_stack.empty())
        {
            if(length == 1)
            {
                break;
            }
            length--;
            this->sub_stack.push(main_stack.top());
            this->main_stack.pop();
        }
        int result = main_stack.top();
        while(!sub_stack.empty())
        {
            this->main_stack.push(sub_stack.top());
            this->sub_stack.pop();
        }
        return result;
    }
    
    bool empty() {
        return main_stack.empty();
    }
};
int main()
{
    MyQueue a = MyQueue();
    a.push(1);
    cout<<a.peek()<<endl;
    a.push(2);
        cout<<a.pop()<<endl;
    // cout<<a.pop()<<endl;
}