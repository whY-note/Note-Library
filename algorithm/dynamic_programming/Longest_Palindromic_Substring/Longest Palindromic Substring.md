# 最长回文子串

from：leetcode [最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)

归类：字符串、动态规划

## 题目描述

给你一个字符串 `s`，找到 `s` 中最长的 回文 子串。

**示例 1：**

```
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

**示例 2：**

```
输入：s = "cbbd"
输出："bb"
```



## 解答

### 方法一：暴力解法

思路：以下标`i`为子字符串的最左边元素，以下标`j`为子字符串的最右边元素，然后检查二者之间的元素是否符合“回文”特征。

若符合“回文”特征，且长度大于最大长度，则更新最大长度`max_len`以及这个回文子串的最左边下标`max_left`

```cpp
string longestPalindrome(string s) {
    int len_s =s.size();
    int max_len = 0;
    int max_left =0;

    for (int i=0; i<len_s; i++) {

        for(int j=len_s-1; j>=i;j--) {
            int left = i;
            int right = j;

            while(left<=right && s[left] == s[right]) {

                left++;
                right--;
            }

            if(left>right) {
                int nowlen = j-i+1;
                if (max_len<nowlen){
                    max_len = nowlen;
                    max_left = i;
                }
                break;
            }

        }
    }
    return s.substr(max_left,max_len);
}
```



### 方法二：中心扩散法

思路：从任意位置`i`开始，首先向左寻找与当前下标`i`相同的字符,直至遇到不相同的字符；然后同理，向右寻找与当前下标`i`相同的字符,直至遇到不相同的字符；接着同时向左、右两边扩散，直至左、右两边的字符不相同。

若长度大于最大长度，则更新最大长度`max_len`以及这个回文子串的最左边下标`max_left`

```cpp
string longestPalindrome(string s) {
    int max_len = 0;
    int max_left = 0;
    int len_s = s.size();
    for(int i=0; i<len_s; i++) {
        int left = i, right = i;

        while (left - 1 >= 0 && s[left - 1] == s[right]) {
            left -= 1;
        }
        while (right +1 < len_s && s[right + 1] == s[left]) {
            right += 1;
        }
        while (left-1 >= 0 && right+1 < len_s && s[left-1] == s[right+1]) {
            left-=1;
            right+=1;
        }
        int len = right -left + 1;
        if(len>max_len) {
            max_len = len;
            max_left = left;
        }
    }
    return s.substr(max_left,max_len);
}
```

### 方法三：动态规划

不难发现，上述方法一，方法二都进行了大量的重复计算。动态规划”以空间换时间“，利用数组来存储子字符串是否为回文子串。

#### 思路

利用`dp[i][j]`来表示下标`i`至`j`的字符串是否为回文子串
$$
dp[i][j]=
\begin{cases}
true, \quad if:下标i至j的字符串是否为回文子串 \\
false, \quad otherwise
\end{cases}
$$
如果$dp[i][j]=true$，那么必有$dp[i+1][j-1]=true 且 S_i=S_j$​

动态规划的状态转移方程即为：
$$
dp[i][j]=\left(dp[i+1][j-1] \and S_i=S_j \right)
$$


```cpp
string longestPalindrome(string s) {
    int max_len = 1;
    int max_left = 0;
    int len_s = s.size();
    vector<vector<bool>> dp(len_s,vector<bool>(len_s,false));
    for (int i=0; i<len_s; i++) {
        dp[i][i]=true;
    }
    for (int len = 2; len <= len_s; len++) {
        for (int left = 0; left < len_s; left++) {
            int right = left + len - 1;
            if (right >= len_s) {
                break;
            }
            if (s[left] != s[right]) {
                dp[left][right] = false;
            }
            else {// s[left] == s[right]
                if(right - left <= 2) {
                    dp[left][right] = true;
                }
                else {
                    dp[left][right] = dp[left+1][right-1];
                }
            }

            if (dp[left][right] == true && len > max_len) {
                max_len = len;
                max_left = left;
            }
        }
    }
    return s.substr(max_left,max_len);
}
```

