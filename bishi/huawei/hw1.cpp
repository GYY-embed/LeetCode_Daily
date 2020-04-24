#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    string input;
    vector<int> num;
    getline(cin, input);
    for(auto i : input)
    {
        if(i >= '0' && i <= '9')
            num.push_back(i);
    }
    sort(num.begin(), num.end());
    for(auto i : num)
    {
        cout << i - '0';
    }
    cout << endl;
    return 0;
}