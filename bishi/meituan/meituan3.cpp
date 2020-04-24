#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    int NumOfPerson;
    //vector<int> fail_vec;
    cin >> NumOfPerson;
    int num;
    vector<int> fail_vec;
    list<int> mylist;
    
    cin >> num;
    do{
        fail_vec.push_back(num);
        
    }while(cin.peek()!= '\n' && cin >> num);

    // for(auto i : fail_vec)
    //     cout << i << endl;
    
    for(int i = 1; i <= NumOfPerson; i++)
    {
        mylist.push_back(i);
    }

    // for(auto i : mylist)
    //     cout << i << endl;

    vector<int> out_vec(fail_vec.size(), 0);//淘汰编号
    while(fail_vec.size() > 0)
    {
        //cout << "OK" << endl;
        int out_num = fail_vec[0];
        int out_count = 0;
        //cout << out_num << ' ' << out_count << endl;
        auto ite = mylist.begin();
        while(out_count != out_num)
        {
            ++ite;
            //cout << *ite << endl;
            int k = *ite;
            if(ite == mylist.end())
                ite = mylist.begin();
            ++out_count;
        }
        //cout << *ite << " ";
        int k = (*ite) - 1;
        out_vec[k] = fail_vec.size();
        mylist.erase(ite);
        fail_vec.erase(fail_vec.begin());
    }
    //cout << endl;

    for(auto i : out_vec)
        cout << i << endl;

    
    /* code */
    return 0;
}
