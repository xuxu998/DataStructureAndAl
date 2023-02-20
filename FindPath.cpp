#include <bits/stdc++.h>
using namespace std;
#define NUMBER_OF_VERTICES 5
#define DESTINATION    4
#define SOURCE         0
#define PATH_EXIST     1
#define PATH_NOT_EXIST   0
#define VISITED       1
#define NOT_VISITED     0
vector<int> path;
vector<int> mark;
void print_path()
{  
    for(int vertex : path)  
    {    
        cout<<vertex<<" ";  
    }  
    cout<<endl;
}
void FindPath(int graph[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES],int source,int destination)
{  
    if (source == destination)  
    {    
        path.push_back(destination);    
        mark[destination] = VISITED;    
        print_path();    
        path.pop_back();    
        mark[destination] = NOT_VISITED;    
        return;  
    }  
    path.push_back(source);  
    mark[source] = VISITED;  
    for(int i = 0; i < NUMBER_OF_VERTICES ; i++)  
    {    
        if(graph[source][i] == PATH_EXIST and mark[i] == NOT_VISITED)    
        {
                FindPath(graph,i,destination);    
        }  
    } 
    path.pop_back();  
    mark[source] = NOT_VISITED;
}
int main(void)
{  
    for(int i = 0 ; i < NUMBER_OF_VERTICES; i ++)  
    {    
        mark.push_back(NOT_VISITED);  
    }  
    int graph[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES]=  {    
        {0,1,1,1,0},    
        {0,0,0,1,0},     
        {1,1,0,0,1},    
        {0,0,0,0,1},  
    };  
    FindPath(graph,SOURCE,DESTINATION);
}

