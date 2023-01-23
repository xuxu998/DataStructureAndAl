#include <iostream>
using namespace std;

#define EMPTY 0
#define OCCUPIED 1
#define START_COLUMN 0
#define START_ROW 0

struct board
{
    int n;
    int ** ptr;
};
typedef struct board board;
void print_result(board board)
{
    for(int i = 0; i< board.n;i++)
    {
        for(int j = 0; j < board.n; j++)
        {
            cout<<board.ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool is_safe(int row, int column, board board)
{
    /*Check the same row to the current position*/
    /*Different column for each queen by default*/
    for(int i = 0; i < board.n ; i++)
    {
        if(board.ptr[row][i] == OCCUPIED)
            return false;
    }
    /*Check left diagonal*/
    int i = row;
    int j = column;
    while (i != 0 && j != 0)
    {
        /* code */
        if (board.ptr[i--][j--] == OCCUPIED)
        {
            return false;
        }
        
    }
    /*Check right diagonal*/
    i = row;
    j = column;
    while (i < board.n && j >= 0)
    {
        /* code */
        if (board.ptr[i++][j--] == OCCUPIED)
        {
            return false;
        }
    }
    return true;
}
int ** board_initialization(int number_of_queens = 8)
{
    int ** ptr = new int*[number_of_queens];
    for(int i = 0 ; i < number_of_queens ; i++)
    {
        ptr[i] = new int[number_of_queens];
    }
    for(int i = 0 ; i < number_of_queens ; i++)
    {
        for(int j = 0 ; j < number_of_queens ; j++)
        {
            ptr[i][j] = EMPTY;
        }
        cout<< endl;
    }
    return ptr;
}
void NQueensSolved(board board,int column)
{
    if(column == board.n)
    {
        print_result(board);
    }
    else
    {
        for(int row = 0; row < board.n ; row++)
        {
            if(is_safe(row,column,board))
            {
                board.ptr[row][column] = OCCUPIED;
                NQueensSolved(board,column+1);
                board.ptr[row][column] = EMPTY;
            }
        }
    }
}
void free_board(board board)
{
    for(int i = 0 ; i < board.n ; i++)
    {
        delete board.ptr[i];
    }
    delete board.ptr;
}
int main(void)
{
    int number_of_queens;
    number_of_queens = 4;
    board my_board = {number_of_queens,board_initialization(number_of_queens)};
    NQueensSolved(my_board,0);
    free_board(my_board);

}