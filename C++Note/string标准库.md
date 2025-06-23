# 标准库类型string

导入标准库

```cpp
#include<string>
```



## 定义和初始化string对象

1. 默认初始化
2. 拷贝初始化   用=
3. 直接初始化   用( )

```cpp
string s1;        //默认初始化，创建一个空字符串

string s2 = "ABC";//用"ABC"来初始化，拷贝初始化
string s3("ABC"); //用"ABC"来初始化，直接初始化

string s4 = s3;   //s3的副本，拷贝初始化
string s5(s3);    //s3的副本，直接初始化


string s6(5, 'x');//初始化为5个'x'

string s7 = string("DEF");//用"DEF"来初始化
string s8 = string(5, 'a');//初始化为5个'a'
```



> [!CAUTION]
>
> 错误的方式：
>
> ```c++
> string s1 = 'a';
> cout << s1;
> ```
>
> 错因： 无法从“`char`”转换为“`std::basic_string<char,std::char_traits<char>,std::allocator<char>>`”



## 读取

1. `cin>>s` 遇到空白（即：空格符、换行符、制表符等）就结束

2. `getline(cin,line)`读取一整行，只有遇到**换行符**才结束。遇到空格符、制表符则会继续

3. 读取未知数量的`string` 对象。

   ```cpp
   while(cin>>s)
   ```

4. 读取未知数量的行

   ```cpp
   while(getline(cin,line))
   ```

   

## 查找、替换：

find(string|char*|char s [,int pos=0]) 寻找首个等于给定字符序列的子串。

 搜索始于 pos， 返回类型 size_t 的位置。 rfind 从右边开始搜索

当找不到时：

返回：`std::string::npos`



replace(int pos, int count, string|char*|char s) 替换指定范围内容



## 增、删操作

append(string)  后附 string str

append(int count, char ch)   后附count 个字符 ch

> [!WARNING]
>
> 注意：不能append(char ch)
>
> 比如：
>
> ```cpp
> s.append('a');//错
> 
> s.append("a");//对
> ```
>
> 



insert(int index, int count, char ch)  在index 位置插入 count 个 ch

insert(int index, string s)   在index 位置插入**`string`对象**s

insert(int index, char* s)   在index 位置插入 **C风格字符串** s

```cpp
ss.insert(2, 5, 'x');  //对
ss.insert(2, 2, "hao");//错
ss.insert(2, 'a');     //错
ss.insert(2, "hao");   //对
```



erase(int index, int count)    删除 从index 开始的 count 个字符

```cpp
string ss = "ABCDEF";
ss.erase(2, 3);
cout << ss << endl;
```



clear() 清空

```cpp
s7.clear(); 
cout << s7 << endl;
cout << s7.length() << endl;  //0
cout << s7.size() << endl;    //0
cout << s7.capacity() << endl;// 保持不变
```

解释：

`clear()` 方法会移除字符串或容器中的所有元素，导致其 `size()` 变为 0，但它并不会改变容器的容量 (`capacity()`)，即已分配的内存空间大小。因此，`capacity()` 的值会保持不变。



## 子串、比较、拷贝、交换：

substr(int pos, int count)  返回子串对象



compare(string|char* str)  与str比较，返回 1， 0， -1之一



compare(int pos, int count, string|char* str) 字串与str比较， 返回1， 0， -1之一



copy(string|char* dest, int pos, int count) 将子串复制到目标对象



swap(string other) 与 other 交换内容



## 遍历每个字符

### 法一：

```cpp
for (char c : s7)
{
    cout << c << endl;
}
```

### 法二：

```cpp
for(int i=0;i<s7.length();i++)
{
	cout << c << endl;
}
```





将`std::string`转换为C风格字符串：`c_str()`

