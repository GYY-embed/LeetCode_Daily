#include <iostream>
#include <vector>

using namespace std;

int my_min(int a, int b)
{
    return (a <= b)?a:b;
}

int my_max(int a, int b)
{
    return (a >= b)?a:b;
}

/* int cut(int n, vector<int> money)
{
    if(n == 0)
        return 0;
    int q = -1;
    for(int i = 1; i <= n; i++)
    {
        q = max(q, money[i-1] + cut(n-i, money));
    }
    return q;
} */

int cut(vector<int> money, int n, vector<int> r)
{
    int q = -1;
    if(r[n] >= 0)
        return r[n];
    if(n == 0)
        q = 0;
    else
    {
        for(int i = 0; i <= n; i++)
            q = max(q, cut(money,n-i,r) + money[i-1]);
    }
    r[n] = q;

    return q;
}

int cutMem(vector<int> money, int n)
{
    vector<int> r(n+1, -1);
    return cut(money, n, r);
}

int main(int argc, char const *argv[])
{
    vector<int> n = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    cout << cutMem(n, 4) << endl;
    return 0;
}
