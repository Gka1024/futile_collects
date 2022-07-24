#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> table(9, vector<int>(9, 0));

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
    if(num = 80)
    {
        print();
        return;
    }
    else
    {
        int colN = num % 9;
        int rowN = num / 9;
        
        cout << colN << " "  << rowN << endl;
        
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
    int col, row, num;
   
    
    while(true)
    {
        cout << "행과 열, 숫자를 입력해주세요. 입력이 끝났다면 -1을 입력해주세요." << endl;
        cout << "행 : ";
        cin >> col;
        
        if(col < -1 || col > 9)
        {
            cout << "잘못된 숫자입니다.";
            continue;
        }
        
        cout << "열 : ";
        cin >> row;
        
        if(row < -1 || row > 9)
        {
            cout << "잘못된 숫자입니다.";
            continue;
        }
        
        cout << "숫자 : ";
        cin >> num;
        
        if(num < -1 || num > 9)
        {
            cout << "잘못된 숫자입니다.";
            continue;
        }
        
        if(col == -1 || row == -1 || num == (-1))
        {//
            break;
        }
        
        table[col-1][row-1] = num; 
        
        print();   
    }

cout << endl;
cout << endl;
cout << endl;
    sudoku(0);
    return 0;
}
