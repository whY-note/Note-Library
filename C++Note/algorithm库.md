# algorithm库

```c++
#include<algorithm>
```



## 排序 sort

对一个范围内的元素进行排序，默认是**升序**。

将迭代器`it1`、`it2`之间的元素按 `func`（可无，默认升序）指定的方式排序。

```c++
std::sort(it1, it2, func); 
```

例如：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n = 5;
	vector<int> vec;
	for(int i = 0; i < n ; i ++){
		vec.push_back(i+1);
	}
	auto it1 = vec.begin() + 2;
	auto it2 = vec.begin() + 3;
	sort(vec.begin(),vec.end(),[](int a, int b){return a > b;});
    /*
    	vec.begin():迭代器 指向vector vec的首元素
    	vec.end()：迭代器 指向vector vec的最后一个元素的下一个
    	[](int a, int b){return a > b;} ：匿名函数（lambda）
    	
    	作用：按照降序排序
    	
    */
  	cout << *(it1) << " " << *(it2) << endl;// 3 2
	sort(it1,it2);
    /*
    	it1: 迭代器
    	it2：迭代器
    	默认是升序
    	
    	作用：按照升序将[it1,it2)之间的元素排序
    	
    */
    
	cout << *(it1) << " " << *(it2) << endl;// 3 2
}
```



## **查找 **find

- ```
  std::find
  ```

  ：在指定范围内查找元素。

  ```c++
  auto it = std::find(arr, arr + n, value);
  ```

比如：

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v = {5, 3, 8, 1, 2};

    // 排序
    std::sort(v.begin(), v.end());
    
    // 输出排序后的结果
    for (int num : v) {
        std::cout << num << " ";
    }

    // 查找元素
    auto it = std::find(v.begin(), v.end(), 3);
    if (it != v.end()) {
        std::cout << "\n找到 3，索引位置为: " << std::distance(v.begin(), it) << "\n";
    }

    return 0;
}
```



## **反转**：

- ```
  std::reverse
  ```

  ：反转一个范围内的元素顺序。

  ```c++
  std::reverse(arr, arr + n);
  ```

## **最大值/最小值**：

- ```
  std::max
  ```

  ：返回两个值中的较大者。

  ```c++
  int maximum = std::max(a, b);
  ```

## **计数**：

- ```
  std::count
  ```

  ：统计某个值在范围内出现的次数。

  ```c++
  int count = std::count(arr, arr + n, value);
  ```

## **转换**：

- ```
  std::transform
  ```

  ：对范围内的元素应用一个函数。

  ```c++
  std::transform(arr, arr + n, arr, [](int x) { return x * 2; });
  ```



## 累计计算 accumulate

作用：对容器中的元素进行累计计算。

语法：

```cpp
accumulate(first, last, init, op)
```

其中：

- `first, last`：范围
- `init`：初始值
- `op`：累计计算操作（比如： lambda 表达式）

> [!CAUTION]
>
> 注意：`init`初始值 是作为 **第一次累计计算**操作 的 **第一个参数**

比如：

例1

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
#include <numeric>
using namespace std;

int main(){
	int n=3;
	vector<int> vec;
	for(int i = 0; i < n ; i ++){
		vec.push_back(i+1);
	}
	auto res = accumulate(vec.begin(),vec.end(),1,[](int i,int j){return pow(i,j);});
    /*
    	step 1: i=1, j=1 => pow(1,1)=1
        step 2: i=1, j=2 => pow(1,2)=1
        step 3: i=1, j=3 => pow(1,3)=1
    */
	cout << res << " ";// 1
	sort(vec.begin(),vec.end(),[](int a, int b){return a > b;});
	auto res2 = accumulate(vec.begin(),vec.end(),1,[](int i,int j){return pow(i,j);});
    /*
    	step 1: i=1, j=3 => pow(1,3)=1
        step 2: i=1, j=2 => pow(1,2)=1
        step 3: i=1, j=1 => pow(1,1)=1
    */
	cout << res2;// 1
}
```

例2

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
#include <numeric>
using namespace std;

int main(){
	int n=3;
	vector<int> a;
	for(int i = 0; i < n ; i ++){
		a.push_back(i+1);
	}
	auto res = accumulate(a.begin(),a.end(),1,[](int i,int j){return pow(j,i);});
    /*
    	第一次：i=1, j=1 → pow(1,1) = 1
        第二次：i=1, j=2 → pow(2,1) = 2
        第三次：i=2, j=3 → pow(3,2) = 9
    */
	cout << res << " ";
	sort(a.begin(),a.end(),[](int a, int b){return a > b;});
	auto res2 = accumulate(a.begin(),a.end(),1,[](int i,int j){return pow(j,i);});
    /*
    	第一次：i=1, j=3 → pow(3,1) = 3
        第二次：i=3, j=2 → pow(2,3) = 8
        第三次：i=8, j=1 → pow(1,8) = 1
    */
	cout << res2;
}
```

例3

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
	int n=5;
	vector<int> a;
	for(int i = 0; i < n ; i ++){
		a.push_back(i+1);
	}
	int min{3};
	
	auto sum = accumulate(a.begin(), a.end(), 0, [min] (int sum, int v){
	    if(v < min)
	        return sum;
	    return sum + v;
	});
    /*
        [min] (int sum, int v){
            if(v < min)
                return sum;
            return sum + v;
         }
         
        lambda函数：
         形参min
         当 v<min时，不相加，直接返回sum；
         否则，		相加，再返回。
    */
    
	cout<<sum<<endl;
}
```



## 下界 lower_bound



比如：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n=5;
	vector<int> a;
	for(int i = 0; i < n ; i ++){
		a.push_back((i+1)*2);
	}
	auto r1=lower_bound(a.begin(),a.end(),7,[](int i,int j){return i<j;});
	cout<<*r1<<" ";
	auto r2=lower_bound(a.begin(),a.end(),7,[](int i,int j){return i>j;});
	cout<<*r2;
}
```

##### 解释：

######  **第一次 `lower_bound`**

```cpp
auto r1 = lower_bound(a.begin(), a.end(), 7, [](int i, int j){ return i < j; });
```

- 这里的 `lower_bound` 用的 **自定义比较函数**，意思是：
  - 如果 `comp(x, value)` 返回 true，就继续往后找。
  - 这里的比较函数 `[](int i, int j){ return i < j; }` 等价于默认的 `less<int>`。

所以这次的 `lower_bound` 逻辑是 **正常升序查找**（即大于等于 7 的第一个数）。

在 `[2,4,6,8,10]` 中，第一个大于等于 7 的数是 `8`。

所以：

```cpp
*r1 = 8
```

------



###### **第二次 `lower_bound`**

```cpp
auto r2 = lower_bound(a.begin(), a.end(), 7, [](int i, int j){ return i > j; });
```

这次的比较函数是：

```cpp
[](int i, int j){ return i > j; }
```

这个比较逻辑是：**按照降序排列的情况下，查找“第一个小于等于 7 的元素”。**

但是——问题来了：

- `a` 实际是升序排列 `[2,4,6,8,10]`。
- 但是 `lower_bound` 是基于我们给的比较函数去 **二分查找** 的。如果数据没有按比较函数的“顺序”排好，结果是**未定义的行为（UB）**。
- 但在这段代码里，它依然执行了查找，虽然结果并不可靠。

**理论上**：

- `lower_bound` 二分查找需要容器按照比较函数的“升序”排列。
- 这里 `a` 是升序，但比较函数是降序。
- 因此结果是**不确定**的，但很多实现上会返回第一个元素 `2`，因为它是“最左边的候选值”。

大多数实际编译器里（比如 GCC），在 `lower_bound` 这类二分查找算法中，如果数据没有按照比较函数排序，结果就不可预测——但很可能是第一个元素。





## 取差集 set_difference

函数原型：

```cpp
template <class InputIterator1, class InputIterator2, class OutputIterator>
OutputIterator set_difference(
  InputIterator1 first1, InputIterator1 last1,
  InputIterator2 first2, InputIterator2 last2,
  OutputIterator result);

```

- 结果写入到 `result` 指向的位置。
- 返回值是“写入到结果序列的最后一个元素的下一个位置”。

比如：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n=5;
	vector<int> a;
	for(int i = 0; i < n ; i ++){
		a.push_back((i+1)*2);
	}
	vector<int> b;
	for(int i = 0; i < n ; i ++){
		b.push_back((i+1)*3);
	}
	vector<int> c(n);
	auto r1 = set_difference(a.begin(),a.end(),b.begin(),b.end(),c.begin());

	c.resize(r1-c.begin());
	for(auto i=c.begin();i!=c.end();i++){
		cout<<*i<<" ";
	}
	return 0;
}
```



### 



