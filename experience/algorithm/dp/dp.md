# dp动态规划

## 核心

记住已经解决过的子问题的解

## 两种方法

自顶向下的备忘录法
自底向上动态规划

## 以斐波那契数列为例

1、原始的递归版本

```cpp
int fibo(int n)
{
    if(n <= 0)
        return 0;
    else if(n == 1)
        return 1;
    return fibo(n-2)+fibo(n-1);
}
```

2、自顶向下的备忘录法

```cpp
int fib(int n, vector<int> mem)
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
}
```

3、自底向上动态规划

```cpp
int fib(int n)
{
    if(n<=0)
        return n;
    int []Memo=new int[n+1];
    Memo[0]=0;
    Memo[1]=1;
    for(int i=2;i<=n;i++)
    {
        Memo[i]=Memo[i-1]+Memo[i-2];
    }
    return Memo[n];
}
```

## 切钢条题目

将一段长度为i的钢条切成多份，每个长度的钢条的价格不同，如何切得到的收益最大

思路：求取多种切割方案的最大值

最优子结构性质：问题的最优解由相关子问题的最优解组成，这些子问题可以独立求解

1、递归方法

```cpp
int cut(int n, vector<int> money)
{
    if(n == 0)
        return 0;
    int q = -1;
    for(int i = 1; i <= n; i++)
    {
        q = max(q, money[i-1] + cut(n-i, money));
    }
    return q;
}
```

2、备忘录版本

```cpp

```