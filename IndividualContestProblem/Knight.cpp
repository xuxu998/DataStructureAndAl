#include <bits/stdc++.h>
using namespace std;
#define BOARD_SIZE                  8
#define NUMBER_OF_POSIBLE_MOVEMENT  8
#define UNUSED                      0

int posible_x_coordinator[NUMBER_OF_POSIBLE_MOVEMENT] = {2, 1, -1, -2, -2, -1,  1,  2 };
int posible_y_coordinator[NUMBER_OF_POSIBLE_MOVEMENT] = { 1, 2,  2,  1, -1, -2, -2, -1 };


bool safe(int x)
{
    if(x >= 0 && x < BOARD_SIZE)
    {
        return true;
    }
    else
        return false;
}
void print_result(int board[BOARD_SIZE][BOARD_SIZE])
{
    for(int i = 0 ; i < BOARD_SIZE ; i++)
    {
        for(int j = 0 ; j < BOARD_SIZE ; j++)
        {
            cout << " " << setw(2) << board[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void KnightSolved(int board[BOARD_SIZE][BOARD_SIZE],int x_coordinator, int y_coordinator,int movement_index)
{
    // cout<<x_coordinator<<" "<<y_coordinator<<" "<<movement_index<<endl;
    if(movement_index == BOARD_SIZE * BOARD_SIZE)
    {
        board[x_coordinator][y_coordinator] = movement_index;
        print_result(board);
        exit(0);
        // board[x_coordinator][y_coordinator] = UNUSED;
    }
    else
    {
        for(int i = 0 ; i < NUMBER_OF_POSIBLE_MOVEMENT; i++)
        {
            board[x_coordinator][y_coordinator] = movement_index;
            if(safe(x_coordinator + posible_x_coordinator[i]) && safe(y_coordinator + posible_y_coordinator[i]))  
            {
                if(board[x_coordinator + posible_x_coordinator[i]][y_coordinator + posible_y_coordinator[i]] == UNUSED)
                    KnightSolved(board,x_coordinator + posible_x_coordinator[i],y_coordinator + posible_y_coordinator[i],movement_index+1);
            }
            board[x_coordinator][y_coordinator] = UNUSED;
        }
    }
}
int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {
        // {0,0,0,0},
        // {0,0,0,0},
        // {0,0,0,0},
        // {0,0,0,0},
        #if BOARD_SIZE == 5
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        #endif
        #if BOARD_SIZE == 6
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        #endif
        #if BOARD_SIZE == 7
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        #endif

        #if BOARD_SIZE == 8
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        #endif
    };
    KnightSolved(board,0,0,1);
    // print_result(board);
}