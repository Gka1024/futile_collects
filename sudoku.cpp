#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> table(9, vector<int>(9, 0));
bool iscomplete = false;

bool isputable(int x, int y, int n)
{
    for(int i = 0; i < 9; i++)
    {
        if(table[i][y] == n)
        {
            return false;
        }
    }
    for(int i = 0; i < 9; i++)
    {
        if(table[x][i] == n)
        {
            return false;
        }
    }
    int partX = (x / 3) * 3;
    int partY = (y / 3) * 3;
    for(int i = partX; i < partX+3; i++)
    {
        for(int j = partY; j < partY+3; j++)
        {
            if(table[i][j] == n)
            {
                return false;
            }
        }
    }
    return true;
}

void print()
{
    for(int i = 0 ; i < 9; i++)
        {
            for(int j = 0 ; j < 9; j++)
            {
                if((j) % 3 == 0 && j != 0)
                {
                    cout << "| ";
                }
                cout << table[i][j] << " ";
            }
            if((i) % 3 == 2 && i != 8)
            {
                cout << endl << "- - - + - - - + - - -";
            }
            cout << endl;
        }
        return;
}

void sudoku(int num)
{
    if(iscomplete == true)
    {
        return;
    }
    if(num == 81 && iscomplete == false)
    {
        print();
        iscomplete = true;
        return;
    }
    else
    {
        int colN = num % 9;
        int rowN = num / 9;
        
        if(table[colN][rowN] == 0)
        {
            for(int i = 1; i <= 9; i++)
            {
                if(isputable(colN, rowN, i))
                {
                    table[colN][rowN] = i;
                    sudoku(num + 1);
                    table[colN][rowN] = 0;
                }
            }
        }
        else
        {
            sudoku(num+1);
        }
        
        
    }
}

int main()
{
    string temp;
    int cnt, num;
   
    
    for(int i = 0; i < 81; i++)
    {
        cin >> num;
        cout << endl;
        
        if(num == -1)
        {
            break;
        }
        if(num == -2)
        {
            i = i - 2;
            continue;
        }
        
        table[i/9][i%9] = num;
        
        print();   
        
        cout << endl;
    }

cout << endl;
cout << endl;
cout << endl;
    sudoku(0);
    return 0;
}
