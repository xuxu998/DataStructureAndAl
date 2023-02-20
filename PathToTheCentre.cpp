#include <bits/stdc++.h>
using namespace std;

#define SIZE                9

#define SOURCE_X            0
#define SOURCE_Y            0

#define VISITED             1
#define NOT_VISITED         0

#define POSSIBLE_MOVEMENT   4

struct coordinator
{
    /* data */
    int x;
    int y;
};
typedef struct coordinator coordinator;

int visited_map[SIZE][SIZE];
vector<coordinator> path;

int possible_x[POSSIBLE_MOVEMENT] = {-1,0,1,0};
int possible_y[POSSIBLE_MOVEMENT] = {0,-1,0,1};
void print_path()
{
    for(coordinator element: path)
    {
        cout<<"("<<element.x<<","<<element.y<<")"<<" ";
    }
    cout<<endl;
}
void Init()
{
    for(int i = 0 ; i < SIZE; i ++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            visited_map[i][j] = NOT_VISITED;
        }
    }
}
bool ValidMovement(int x, int y)
{
    if(x >= 0 and x < SIZE and y >=0 and y < SIZE)
    {
        return true;
    }
    return false;
}
void PathToCentre(int matrix[SIZE][SIZE], int current_x, int current_y)
{
    if(matrix[current_x][current_y] == 0)
    {
        visited_map[current_x][current_y] = VISITED;
        coordinator temp = {current_x,current_y};
        path.push_back(temp);
        print_path();
        visited_map[current_x][current_y] = NOT_VISITED;
        path.pop_back();

    }
    visited_map[current_x][current_y] = VISITED;
    coordinator temp = {current_x,current_y};
    path.push_back(temp);
    int current_cell_value = matrix[current_x][current_y];
    for(int i = 0 ; i < POSSIBLE_MOVEMENT ; i++)
    {
        int temp_x = current_x + current_cell_value * possible_x[i];
        int temp_y = current_y + current_cell_value * possible_y[i];
        if(ValidMovement(temp_x,temp_y) and visited_map[temp_x][temp_y] == NOT_VISITED)
        {
                PathToCentre(matrix,temp_x,temp_y);
        }
    }
    visited_map[current_x][current_y] = NOT_VISITED;
    path.pop_back();
    
}
int main(void)
{
    Init();
    int matrix[SIZE][SIZE] = {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 },
    };
    PathToCentre(matrix,SOURCE_X,SOURCE_Y);
}