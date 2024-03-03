#include <bits/stdc++.h>
using namespace std;

#define BOARD_SIZE 9
#define NOT_FILLED 0
#define MIN_VALUE 1
#define MAX_VALUE 9

struct region
{
    int x_start;
    int x_end;
    int y_start;
    int y_end;
};
typedef struct region region;

region regions[9] = {
    {0,2,0,2},
    {3,5,0,2},
    {6,8,0,2},
    {0,2,3,5},
    {3,5,3,5},
    {6,8,3,5},
    {0,2,6,8},
    {3,5,6,8},
    {6,8,6,8},
};

void print_result(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            cout << " " << setw(2) << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool is_safe_in_subgrid(int board[BOARD_SIZE][BOARD_SIZE],int x_coordinator,int y_coordinator,int value)
{
    for(int i = 0 ; i < 9 ; i++)
    {
        if(x_coordinator <= regions[i].x_end && x_coordinator >= regions[i].x_start && y_coordinator <= regions[i].y_end && y_coordinator >= regions[i].y_start)
        {
            for(int x = regions[i].x_start; x <= regions[i].x_end; x++)
            {
                for(int y = regions[i].y_start; y <= regions[i].y_end; y++)
                {
                    if(board[x][y] == value)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
bool is_safe(int board[BOARD_SIZE][BOARD_SIZE], int x_coordinator, int y_coordinator, int value)
{
    if(!is_safe_in_subgrid(board,x_coordinator,y_coordinator,value))
    {
        return false;
    }
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[x_coordinator][i] == value)
            return false;
        if (board[i][y_coordinator] == value)
            return false;
    }
    return true;
}
void SudokuSolved(int board[BOARD_SIZE][BOARD_SIZE], int x_coordinator, int y_coordinator)
{
    if (board[x_coordinator][y_coordinator] == NOT_FILLED)
    {
        if (x_coordinator == BOARD_SIZE - 1 && y_coordinator == BOARD_SIZE - 1)
        {
            for(int i = MIN_VALUE; i <= MAX_VALUE; i++)
            {
                if(is_safe(board,x_coordinator,y_coordinator,i))
                {
                    board[x_coordinator][y_coordinator] = i;
                }
            }
            print_result(board);
            exit(0);
        }
        else
        {
            for (int i = MIN_VALUE; i <= MAX_VALUE; i++)
            {
                if (is_safe(board, x_coordinator, y_coordinator, i))
                {
                    board[x_coordinator][y_coordinator] = i;
                    if (y_coordinator == BOARD_SIZE - 1)
                    {
                        SudokuSolved(board, x_coordinator + 1, 0);
                    }
                    else
                    {
                        SudokuSolved(board, x_coordinator, y_coordinator + 1);
                    }
                    board[x_coordinator][y_coordinator] = NOT_FILLED;
                }
            }
        }
    }
    else
    {
        if (y_coordinator == BOARD_SIZE - 1)
        {
            SudokuSolved(board, x_coordinator + 1, 0);
        }
        else
        {
            SudokuSolved(board, x_coordinator, y_coordinator + 1);
        }
    }
}
int main(void)
{
    int sudoku_board[BOARD_SIZE][BOARD_SIZE] = {
        {9, 1, 7, 2, 5, 4, 0, 0, 0},
        {4, 0, 2, 0, 8, 0, 0, 0, 0},
        {6, 5, 0, 0, 0, 3, 4, 0, 0},
        {0, 0, 3, 0, 9, 0, 2, 5, 6},
        {5, 0, 0, 7, 0, 0, 3, 0, 9},
        {2, 0, 0, 0, 0, 5, 0, 7, 1},
        {0, 2, 0, 5, 3, 0, 7, 6, 0},
        {3, 7, 0, 1, 6, 0, 0, 9, 8},
        {0, 0, 0, 0, 0, 0, 0, 3, 0}};
    SudokuSolved(sudoku_board, 0, 0);
    return 0;
}