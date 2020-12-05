#include <iostream>
#include <vector>

using namespace std;

/* int fib(int n, vector<int> mem)
{
    if(mem[n] != -1)
        return mem[n];
    if(n <= 2)
        mem[n] = 1;
    else
        mem[n] = fib(n-1,mem) + fib(n-2, mem);
    return mem[n];
}

int fibonacci(int n)
{
    if(n <= 0)
        return 0;
    vector<int> mem(n+1, -1);
    return fib(n, mem);
} */

int fib(int n)
{
    if(n<=0)
        return n;
    vector<int> mem(n+1);
    mem[0]=0;
    mem[1]=1;
    for(int i=2;i<=n;i++)
    {
        mem[i]=mem[i-1]+mem[i-2];
    }
    return mem[n];
}

int main(int argc, char const *argv[])
{
    cout << fib(10) << endl;
    return 0;
}
