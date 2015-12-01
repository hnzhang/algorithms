//a solution of sudoku
#include<iostream>
#include<vector>

bool find_free_position(std::vector< std::vector<int> >&data, int& x, int& y)
{
    for(int i = 0; i < 9; i++)
        for(int j=0; j < 9; j++)
        {
            if(data[i][j] == 0)
            {
                x = i; y = j;
                return true;
            }
        }
    return false;//all cells filled
}
bool no_violation_row(std::vector< std::vector<int> >& data, int x, int y, int val)
{
    for(int i =0; i < 9; i++)
    {
        if(i != y && data[x][i] == val)
            return false;
    }
    return true;
}

bool no_violation_column(std::vector< std::vector<int> >& data, int x, int y, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(x!= i && data[i][y] == val)
            return false;
    }
    return true;
}

bool no_violation_box(std::vector< std::vector<int> >& data, int x, int y, int val)
{
    for(int i = (x/3 )*3 ; i < (x/3 +1)*3; i++)
        for(int j = (y/3)*3; j < (y/3 +1)*3; j++)
        {
            if(x != i && y != j && data[i][j] == val)
                return false;
        }
    return true;
}

bool no_violation(std::vector< std::vector<int> >& data, int x, int y, int val)
{
    return no_violation_row(data, x, y, val) && no_violation_column(data, x, y, val)
        && no_violation_box(data, x, y, val);
}

bool sudoku(std::vector< std::vector<int> >& data)
{
    int x, y;
    if(!find_free_position(data, x, y))//the sudoku is fully filled now
        return true;
    else
    {
        //get all free positions and iterate
        for(int i = 1; i <= 9; i++)
        {
            if(no_violation(data, x, y, i))
            {
                data[x][y]=i;
                if(sudoku(data))
                    return true;
                data[x][y] = 0;
            }
        }
        return false;//all possibility fails
    }
}
void printout_sudoku(std::vector< std::vector<int> >&data)
{
    std::cout << "SUDOKU solution:" << std::endl;
    int i =1, j = 1;
    for(auto row :data)
    {
        std::cout << std::endl;
        std::cout << " | ";
        for(auto i :row)
        {
            std::cout << i << " ";
            if(j == 3) 
            {
                std::cout << " | ";
                j = 1;
            }
            else
            {
                j++;
            }
        }
        if(i == 3)
        {
            std::cout << std::endl;
            i = 1;
        }
        else
        {
            i++ ;
        }
    }
}

int main()
{
    std::vector< std::vector<int> > data =
    {
        {0,0,0, 0,0,0, 0,1,2},
        {0,0,0, 0,3,5, 0,0,0},
        {0,0,0, 6,0,0, 0,7,0},

        {7,0,0, 0,0,0, 3,0,0},
        {0,0,0, 4,0,0, 8,0,0},
        {1,0,0, 0,0,0, 0,0,0},

        {0,0,0, 1,2,0, 0,0,0},
        {0,8,0, 0,0,0, 0,4,0},
        {0,5,0, 0,0,0, 6,0,0},
    };

    if(sudoku(data))
    {
        printout_sudoku(data);
    }
    else
    {
        std::cout << "Failed to find a solution" << std::endl;
    }
    return  0;
}
