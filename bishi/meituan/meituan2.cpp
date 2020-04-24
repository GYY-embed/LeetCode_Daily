#include <iostream>
#include <string>

using namespace std;

string data_process(string str)
{
    bool is_neg = false;
    bool is_point = false;
    //是否为负数
    if(str[0] == '-')
        is_neg = true;
    //是否为小数
    int n = str.find_first_of('.');
    if(n != string::npos)
    {
        //cout << "OK" << endl;
        is_point = true;
    }    
    string doler = "$";
    string neg_first = "(";
    string neg_last = ")";
    string point = ".";
    string first_str, second_str;
    //分割成整数部分和小数部分
    if(is_point == false)//整数
    {
        if(is_neg == true)//负整数
            first_str = str.substr(1);
        else//正整数
            first_str = str;
        second_str = "00"; 
    }
    else
    {
        if(is_neg == true)//负
            first_str = str.substr(1, n - 1);
        else//正
            first_str = str.substr(0, n);
        //cout << "first: " << first_str << endl;
        second_str = str.substr(n+1);
        //cout << second_str << endl;
        if(second_str.size() < 2)
        {
            second_str+="0";
        }
        else
        {
            second_str = second_str.substr(0, 2);
        }
        //cout << "second: " << second_str << endl;
    }
    //对整数部分加逗号
    if(first_str.size() > 3)
    {
        string temp = first_str;
        first_str.clear();
        while(temp.size() > 3)
        {
            first_str = ","+ temp.substr(temp.size() - 3) + first_str;
            temp = temp.substr(0, temp.size() - 3);
            // cout << "first: " << first_str << endl;
            // cout << "temp: " << temp << endl;
        }
        first_str = temp + first_str;
        //cout << "first: " << first_str << endl;
       // cout << "temp: " << temp << endl;
    }
    if(is_neg)//负数
    {
        return neg_first+doler+first_str+point+second_str+neg_last;
    }
    else
    {
        return doler+first_str+point+second_str;
    }

}

int main(int argc, char const *argv[])
{
    string input;
    while(cin >> input)
        cout << data_process(input) << endl;
    /* code */
    return 0;
}
