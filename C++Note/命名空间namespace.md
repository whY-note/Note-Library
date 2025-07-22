# 命名空间namespace

## 作用：

**避免命名冲突**

多个不同库或模块可以使用相同的名字而不会发生冲突。

在命名空间块内声明的符号被放入一个具名的作用域中， 避免这些符号被误认为其他作用域中的同名符号

”符号“包括：变量、函数、类……



## 语法：

### 定义命名空间

```cpp
namespace myNamespace{
    int size=10;
    void print()
    {
        std::cout<<"print()"<<std::endl;
    }
}
```



### 访问命名空间中的成员

> [!IMPORTANT]
>
> 使用 `::`***作用域解析运算符***  

```cpp
int main()
{
    std::cout<<myNamespace::size<<std::endl;
    myNamespace::print();
    return 0;
}
```



### 嵌套命名空间

示例

```cpp
namespace outer{
    void print(){
            std::cout<<"print from outer"<<std::endl;
        }
    namespace inner{
        void print(){
            std::cout<<"print from inner"<<std::endl;
        }
    }
}
```



访问嵌套命名空间中的成员

逐层使用 `::`***作用域解析运算符***  

```cpp
outer::print();
outer::inner::print();
```



### 命名空间起别名

```cpp
namespace MNS=myNamespace;
```

可以用别名来访问成员，也可以用原名访问成员

```cpp
MNS::print();//用别名来访问成员
myNamespace::print();//用原名访问成员
```



### **使用 `using` 声明**

> [!IMPORTANT]
>
> 使用 `using` 关键字来引入命名空间，这样就不需要每次都使用 `::` 来限定。

#### 声明 命名空间

***`using namespace 命名空间名`***

例如：声明标准命名空间 `std`

```cpp
using namespace std;
```

原本需要写 `std::cout`，则现在只需要写`cout`



#### 声明 命名空间中的某一个具体成员

***`using 命名空间名::成员名`***

例如：声明上方`myNamespace`中的`print`函数

```cpp
using myNamespace::print
```



示例代码：

```cpp
#include<iostream>

namespace myNamespace{
    int size=10;
    void print()
    {
        std::cout<<"print()"<<std::endl;
    }
}

//声明std
using namespace std;

//声明myNamespace中的print
using myNamespace::print;

int main()
{
    cout<<"Hello World"<<endl;
    print();//由于myNamespace中的print已经声明了，所以可以直接访问
    myNamespace::print();//也可以用 :: 访问
    cout<<myNamespace::size<<endl;//myNamespace中的size没有声明，所以不能直接访问，必须用 :: 访问
    return 0;
}
```



### 全局变量的限定名

```cpp
::globeA  
```



## **同名的命名空间**的处理：

C++允许在**不同地方**定义 **同名的命名空间**，

还可以在**不同的源文件**中定义同名的命名空间

所有**同名**命名空间块的内容会被**合并**到同一命名空间

示例代码

```cpp
// File1.cpp
namespace MyNamespace {
    void function1() {
        std::cout << "Function 1" << std::endl;
    }
}

// File2.cpp
namespace MyNamespace {
    void function2() {
        std::cout << "Function 2" << std::endl;
    }
}
```

在这种情况下，`MyNamespace` 在两个不同的源文件中被扩展，它们的成员会被合并，最终你可以访问 `function1` 和 `function2`，这两个函数都属于 `MyNamespace`这个命名空间。



# 例题

1.下面的程序，输入2后，输出是什么？

```c++
#include<iostream>
using namespace std; 
int main(){
	int cout;
	cin>>cout;
	std::cout<<(cout<<cout);
}
```



```bash
8
```

> [!NOTE]
>
> 输入的2存放在cout里面
>
> `std::cout<<(cout<<cout);`这行
>
> 首先执行括号内的 `(cout<<cout)`，也就是 `(2<<2)`,得到8
>
> 然后执行 `std::cout<<8`
>
> 所以最后输出 8



2.下面的程序，输出是什么？

```cpp
#include<iostream>

using namespace std;

namespace Utils {
    int version = 1;
}

using Utils::version;

int main() {
    version = 2;
    Utils::version = 3;
    cout << version << endl;
    cout << Utils::version << endl;

    return 0;
}
```



```bash
3
3
```

> [!NOTE]
>
> 因为有 `using Utils::version;`声明
>
> 所以 `version = 2;`，`Utils::version = 3;`都是针对 `Utils::version`进行操作的。

