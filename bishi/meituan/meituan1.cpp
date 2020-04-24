#include <iostream>

using namespace std;
int main()
{
    bool Sky[2001][2001];
    int NumOfStar;
    cin >> NumOfStar;
    int minX, minY, maxX, maxY;
    int LuckCount = 0;

    for(int i = 0; i < NumOfStar; i++)
    {
        int x, y;
        cin >> x >> y;
        if(i==0)
        {
            minX = x;
            maxX = x;
            minY = y;
            maxY = y;
        }
        if(x < minX)
            minX = x;
        else if(x > maxX)
            maxX = x;
        if(y < minY)
            minY = y;
        else if(y > maxY)
            maxY = y;
        Sky[y+1000][x+1000] = true;
    }
    minX+=1000;
    maxX+=1000;
    minY+=1000;
    maxY+=1000;
    //cout << minX << ' ' << maxX << ' ' << minY << ' ' << maxY << endl; 
    for(int i = minY; i <= maxY; i++)//每行
    {
        for(int j = minX; j <= maxX; j++)//每列
        {
            int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
            //上面
            for(int k = minY; k < i; k++)
            {
                if(Sky[k][j] == true)
                {
                    res1 = 1;
                    break;
                }
            }
            if(res1 == 1)
            {
                //下面
                for(int k = maxY; k > i; k--)
                {
                    if(Sky[k][j] == true)
                    {
                        res2 = 1;
                        break;
                    }
                }
            }
            if(res2 == 1)
            {
                //左面
                for(int k = minX; k < j; k++)
                {
                    if(Sky[i][k] == true)
                    {
                        res3 = 1;
                        break;
                    }
                }
            }
            if(res3 == 1)
            {
                //左面
                for(int k = maxY; k > j; k--)
                {
                    if(Sky[i][k] == true)
                    {
                        res4 = 1;
                        break;
                    }
                }
            }
            if(res4 == 1)
            {
                LuckCount++;
            }
        }
    }
    cout << LuckCount << endl;
    return 0;
}