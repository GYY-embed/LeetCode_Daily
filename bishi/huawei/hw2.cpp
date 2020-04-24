#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;


int main(int argc, char const *argv[])
{
    int data_num;
    vector<int> data_buf;
    //数据读入
    while((cin.peek()!= '\n') && cin >> hex >> data_num)
    {
        data_buf.push_back(data_num);
    }
    //数据处理
    //1、首先根据5a将数据分成若干个数据帧
    vector<vector<int> > process_buf;
    vector<int> process_sub_buf;
    int start = 0;

    for(auto i : data_buf)
    {
        //开始帧
        if(i == 0x5a && start == 0)
        {
            process_sub_buf.clear();
            process_sub_buf.push_back(i);
            start = 1;
        }
        //结尾帧
        else if(i == 0x5a && start == 1)
        {
            process_sub_buf.push_back(i);//压入结尾帧
            process_buf.push_back(process_sub_buf);//将整帧加入到帧组
            //前一帧处理结束，该5a还作为后一帧的帧头
            process_sub_buf.clear();
            process_sub_buf.push_back(i);
        }
        //数据帧和计数帧
        else
            process_sub_buf.push_back(i);
    }
    //2、逐帧分析
    int res[process_buf.size()];
    for(int i = 0; i < process_buf.size(); i++)
    {
        int len = process_buf[i][process_buf[i].size() - 2];
        bool is_right = 1;
        int count = 0;
        for(int k = 1; k < process_buf[i].size() - 2; k++)
        {
            if(process_buf[i][k] == 0x5b)
            {
                k++;
                if(process_buf[i][k] == 0xbb || process_buf[i][k] == 0xba)
                    count++;
                else
                    is_right = 0;
            }
            else
                count++;
            
        }
        if(count != len)
            is_right = 0;
        res[i] = is_right;
    }
    //3、输出有效帧
    int first = 1;
    for(int i = 0; i < process_buf.size(); i++)
    {
        if(res[i] == 0)
            continue;
        if(first == 1)
        {
            for(auto j : process_buf[i])
                cout << hex << setfill('0') << setw(2) << j << ' ';
            first = 0;
        }
        else
        {
            for(int j = 1; j < process_buf[i].size(); j++)
            {
                if(i == process_buf.size() - 1 && j == process_buf[i].size() - 1)
                    cout << hex << setfill('0') << setw(2) << process_buf[i][j] << endl;
                else
                     cout << hex << setfill('0') << setw(2) << process_buf[i][j] << ' ';
            }
                
        }
    }
    return 0;
}
