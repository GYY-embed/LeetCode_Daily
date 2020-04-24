#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int NumOfData;
    cin >> NumOfData;
    int num;
    vector<int> vec;
    
    // cin.clear();
    // clearerr(stdin);
    cin >> num;
    do{
        vec.push_back(num);
        
    }while(cin.peek()!= '\n' && cin >> num);

    // for(int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << ' ';
    // }
    //cout << endl;
    // cout << "OK" << endl;
    vector<int> res_vec(vec.size(), 0);
    for(int i = 0; i < vec.size(); i++)
    {
        int res = 0;
        for(int j = 0; j < vec.size(); j++)
        {
            if(i == j)
                continue;
            //cout << (vec[i] & vec[j]) << endl;
            if((vec[i] & vec[j]) == 0)
            {
                res = 1;
                break;
            }   
        }
        if(res != 1)
            res = -1;
        res_vec[i] = res;
    }
    for(int i = 0; i < res_vec.size(); i++)
    {
        cout << res_vec[i] << ' ';
    }
    cout << endl;
    /* code */
    return 0;
}
