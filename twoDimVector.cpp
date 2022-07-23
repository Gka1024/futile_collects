#include <iostream>

int main()
{
  vector<vector<int>> v1(3, vector<int>(2,1));  // 행과 열을 모두 아는 경우
    /*
    1 1
    1 1
    1 1
    */
    
  vector<vector<int>> v2(3); // 열을 아는 경우(편의상 1로 표현함)
 //   1
 //   1
 //   1
    
  vector<vector<int>> v3; // 둘 다 모르는 경우
  v3.push_back(vector<int>); // 공간을 만들어주어야함 - 선언된 공간이 없으므로
    
    
}
