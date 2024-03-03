#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define REACHABLE   1
#define BLOCKED     0
#define X_RIGHT     0
#define Y_RIGHT     1
#define X_DOWN      1
#define Y_DOWN      0
#define X_LEFT      0
#define Y_LEFT      -1
#define MARKED      2

void print_result(int maze[5][5],int maze_size)
{
    for(int i = 0 ; i < maze_size ; i++)
    {
        for(int j = 0 ; j < maze_size ; j++)
        {
            // if(maze[i][j] == MARKED)
            // {
            //     if(i == maze_size -1 && j == maze_size - 1)
            //     cout<<"["<<i<<"]"<<"["<<j<<"]";
            //     else
            //     cout<<"["<<i<<"]"<<"["<<j<<"]"<<"->";
            // }
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void MazeSolved(int maze[5][5],int x_coordinator, int y_coordinator,int maze_size)
{
    if(x_coordinator == maze_size - 1 && y_coordinator == maze_size - 1)
    {
        maze[x_coordinator][y_coordinator] = MARKED;
        // cout<<x_coordinator<<" "<<y_coordinator<<endl;
        print_result(maze,maze_size);
        maze[x_coordinator][y_coordinator] = REACHABLE;
    }
    else
    {
        if(maze[x_coordinator][y_coordinator] ==  REACHABLE)
        {
            maze[x_coordinator][y_coordinator] = MARKED;
            // cout<<x_coordinator<<" "<<y_coordinator<<endl;
            /*Try turn right from current position*/
            if(y_coordinator + Y_RIGHT < maze_size)
            MazeSolved(maze,x_coordinator + X_RIGHT, y_coordinator + Y_RIGHT,maze_size);
            /*Try to go dowm from current position*/
            if(x_coordinator + X_DOWN < maze_size)
            MazeSolved(maze,x_coordinator + X_DOWN, y_coordinator + Y_DOWN,maze_size);
            /*Try to turn the left from current position*/
            if(y_coordinator + Y_LEFT > 0)
            MazeSolved(maze,x_coordinator + X_LEFT, y_coordinator + Y_LEFT,maze_size);

            maze[x_coordinator][y_coordinator] = REACHABLE;
        }
    }

}
int main(void)
{
    int maze1[5][5] = {
        {1,1,1,1,1},
        {1,0,1,0,1},
        {0,0,1,0,1},
        {1,0,1,0,1},
        {1,1,1,1,1}
    };
    MazeSolved(maze1,0,0,5);
}