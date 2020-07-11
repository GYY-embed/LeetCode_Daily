# 字符串处理及string类相关

## 字符串初始化

- string test1;    //空串
- string test2 = "内容"; //使用=
- string test3("内容");   //使用引用字符数组作为参数传给构造函数
- string test4(test2); //用一个string初始化另一而string
- string test5(test2,pos,num); //从test2中的第pos个位置开始，拷贝个数为num个字符
- string test6 = test2 + "内容" + test3 //混合初始化
- string test7 = test2.substr(pos,num); //从test2中的第- pos个位置开始，拷贝个数为num个字符
- string test8 = test2.substr(); //参数列表为空则会拷贝- test2的整个对象（复制test2的简便方法）
- string test9(num,ch); //拷贝num个字符型ch到test9

## 字符串类型转换

string转换为其他类型
- stoi(int)、stof(float)、stod(double)

别的类型转string
- to_string(参数)

## 字符串分割

substr方法

substr函数的形式为s.substr(pos, n)

需要两个参数，第一个是开始位置，第二个是获取子串的长度。

函数可以从一个字符串中获取子串，返回一个string，包含s中从pos开始的n个字符的拷贝（pos的默认值是0，n的默认值是s.size() - pos，即不加参数会默认拷贝整个s），可以作为一种构造string的方法。

若pos的值超过了string的大小，则substr函数会抛出一个out_of_range异常；

若pos+n的值超过了string的大小，则substr会调整n的值，只拷贝到string的末尾。
