#include<bits/stdc++.h>
using namespace std;
#define VERTICES_NUMBER         4
#define CONNECTED               1
#define NOT_CONNECTED           0
#define NOT_COLORED             0
bool result_exists = false;
bool is_safe(int graph[VERTICES_NUMBER][VERTICES_NUMBER],int color,int vertice,int color_list[VERTICES_NUMBER])
{
    for(int i = 0; i < VERTICES_NUMBER ; i++)
    {
        if(graph[vertice][i] == CONNECTED)
        {
            if(color == color_list[i])
            {
                return false;
            }
        }
    }
    return true;
}
void print_result(int color_list[VERTICES_NUMBER])
{
    if(result_exists != true)
    {
        for(int i = 0; i < VERTICES_NUMBER; i++)
        {
            cout<<color_list[i]<<" ";
        }
        cout<<endl;
    }
}
void helper(int graph[VERTICES_NUMBER][VERTICES_NUMBER],int vertices,int color_list[VERTICES_NUMBER])
{
    if(vertices == VERTICES_NUMBER)
    {
        print_result(color_list);
        result_exists = true;
    }
    else
    {
        if(color_list[vertices] == NOT_COLORED)
        {
            for(int i = 1; i < VERTICES_NUMBER; i++)
            {
                if(is_safe(graph,i,vertices,color_list))
                {
                    color_list[vertices] = i;
                    helper(graph,vertices+1,color_list);
                    color_list[vertices] = NOT_COLORED;
                }
            }
        }
    }
}
void mColoring(int graph[VERTICES_NUMBER][VERTICES_NUMBER])
{
    int color_list[VERTICES_NUMBER];
    for(int i = 0 ; i < VERTICES_NUMBER; i++)
    {
        color_list[i] = NOT_COLORED;
    }
    helper(graph,0,color_list);
}


int main(void)
{
    int graph[VERTICES_NUMBER][VERTICES_NUMBER] = 
    {
        #if VERTICES_NUMBER == 4
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
        #endif
        #if VERTICES_NUMBER == 3
        {0,1,0},
        {1,0,1},
        {0,1,0}
        #endif
    };
    mColoring(graph);
    if(result_exists != true)
    {
        cout<<"Result does not exist";
    }
}