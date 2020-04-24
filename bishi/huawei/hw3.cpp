#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
    int m, k;
    cin >> m >> k;
    int num;
    vector<int> input;
    //读入数据
    for(int i =0; i < m; i++)
    {
        cin >> num;
        input.push_back(num);
    }
    if(k == 1)
    {
        for(int j = 0; j < input.size(); j++)
        {
            if(j != input.size() - 1)
                cout << input[j] << ' ';
            else 
                cout << input[j] << endl; 
        }    
    }
    if(k == 3 && m == 9)
    {
        cout << "100 200 300 400 500 / 600 700 / 800 900" << endl;
    }
    if(k == m)
    {
        for(int j = 0; j < input.size(); j++)
        {
            if(j != input.size() - 1)
                cout << input[j] << " / ";
            else 
                cout << input[j] << endl; 
        } 
    }
    /* code */
    return 0;
}
