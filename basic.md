# 1. 动态规划问题

## 1. 单串问题:dp\[i\]\[j\] 以 i, j 结尾

### 1. 873. 最长的斐波那契子序列的长度

> [dynamic01.cc](./dynamic/dynamic01.cc)

### 2. 1027. 最长等差数列

> [dynamic02.cc](./dynamic/dynamic01.cc)

## 2. 单串问题:动态规划和其他算法结合

### 1. 1055. 形成字符串的最短路径 

> [dynamic03.cc](./dynamic/dynamic03.cc)

### 2. 368. 最大整除子集

> [dynamic04.cc](./dynamic/dynamic04.cc)

## 3. 单串问题:未总结

### 1. 413. 等差数列划分

> [dynamic05](./dynamic/dynamic05.cc)

### 2. 91. 解码方法

> [dynamic06](./dynamic/dynamic06.cc)

### 3. 583. 两个字符串的删除操作

> [dynamic07](./dynamic/dynamic07.cc)

### 4. 32. 最长有效括号

> [dynamic08](./dynamic/dynamic08.cc)

### 5.801. 使序列递增的最小交换次数

> [dynamic09](./dynamic/dynamic09.cc)

### 6. 871. 最低加油次数

> [dynamic10](./dynamic/dynamic10.cc)

### 7. 132. 分割回文串 II

> [dynamic11](./dynamic/dynamic11.cc)

## 4. 带维度的单串问题

### 1. 813. 最大平均值和的分组

> [dynamic12](./dynamic/dynamic12.cc)
>
> `维度是分组的大小`

### 2. 256. 粉刷房子

> [dynamic13](./dynamic/dynamic13.cc)
>
> `维度是颜色种类`

### 3. 265. 粉刷房子 II

> [dynamic14](./dynamic/dynamic14.cc)
>
> `维度是颜色种类`

### 4. 975. 奇偶跳

> [dynamic15](./dynamic/dynamic15.cc)
>
> `维度是奇偶能不能到达终点`

### 5. 403. 青蛙过河

> [dynamic16](./dynamic/dynamic16.cc)
>
> `维度是青蛙跳到该位置的跳跃长度`

### 6. 1230. 抛掷硬币

> [dynamic17](./dynamic/dynamic17.cc)
>
> `维度是硬币正面的个数`

### 7. 410. 分割数组的最大值

> [dynamic18](./dynamic/dynamic18.cc)
>
> `维度是分组的份数`

### 8. 926. 将字符串翻转到单调递增

> [dynamic21](./dynamic/dynamic21.cc)
>
> `维度是1/0`

## 5. 单串股票系列: dp[i]\[k][state] i 是时间，k 是次数，state 是状态

### 1. 122. 买卖股票的最佳时机 II

> [dynamic19](./dynamic/dynamic19.cc)
>
> `i时间[i - n], state状态是否持有， 由于是求总利润，可以忽略k次数[0 - n]`

### 2. 121. 买卖股票的最佳时机

> [dynamic20](./dynamic/dynamic20.cc)
>
> `i时间[i - n], state状态是否持有 只能进行一次交易`

### 3. 123. 买卖股票的最佳时机 III

> [dynamic22](./dynamic/dynamic22.cc)
>
> `i时间[i - n], state状态是否持有 最多进行两次交易`

### 4. 188. 买卖股票的最佳时机 IV

> [dynamic23](./dynamic/dynamic23.cc)
>
> `i时间[i - n], state状态是否持有 最多进行k次交易` 

### 5. 309. 最佳买卖股票时机含冷冻期

> [dynamic24](./dynamic/dynamic24.cc)
>
> `i时间[i - n], state状态是否持有 注意买入的时机` 

# 2. 随机数问题

## 1. 水塘抽样

### 1. 398. 随机数索引

> [random01](./random/random01.cc)

# 3. 图类问题

## 1. 深度优先搜索

### 1. 417. 太平洋大西洋水流问题

> [map01](./map/map01.cc)

## 2. 宽度优先搜素

### 1. 433. 最小基因变化

> [map02](./map/map02.cc)

# 4. 树类问题

## 1. 四叉树

### 1. 427. 建立四叉树

> [tree01](./tree/tree01.cc)

### 2. 473. 火柴拼正方形

> [tree06](./tree/tree06.cc)

## 2. 树的遍历

### 1. 中序遍历

#### 1. 1305. 两棵二叉搜索树中的所有元素

> [tree02](./tree/tree02.cc)

### 2. 前序遍历

#### 1. 1022. 从根到叶的二进制数之和

> [tree05](./tree/tree05.cc)

### 3. 后续遍历

#### 1. 508. 出现次数最多的子树元素和

> [tree08](./tree/tree08.cc)

### 4. 层序遍历

### 1. 449. 序列化和反序列化二叉搜索树

> [tree03](./tree/tree03.cc)

## 3. 二叉搜索树

### 1. 面试题 04.06. 后继者

> [tree04](./tree/tree04.cc)

### 2. 450. 删除二叉搜索树中的节点

> [tree07](./tree/tree07.cc)

# 5. 数学类问题

## 1. 约瑟夫环——公式法（递推公式）

### 1. 1823. 找出游戏的获胜者

> [math01](./math/math01.cc)

## 2. 三角形面积公式

### 1.  812. 最大三角形面积

> **坐标求面积 -> 向量邻边构成三角形面积等于向量邻边构成平行四边形面积的一半**
>
> [math02](./math/math02.cc)

## 3. 中位数

### 1. 462. 最少移动次数使数组元素相等 II

> [math03](./math/math03.cc)

## 4. 随机类问题

### 1. 478. 在圆内随机生成点

> [math04](./math/math04.cc)

### 2. 497. 非重叠矩形中的随机点

> [math06](./math/math06.cc)

## 5. 点线关系问题

### 1. 1037. 有效的回旋镖

> [math05](./math/math05.cc)

# 6. 数组类问题

## 1. 双指针类问题

### 1. 713. 乘积小于 K 的子数组

> [array01.cc](./array/array01.cc)

# 7. 哈希类问题

## 1. 自身数组哈希问题

### 1. 442. 数组中重复的数据

> [hash01](./hash/hash01.cc)

# 8. 字符串类问题

## 1. 比对类逻辑题目

### 1. 面试题 01.05. 一次编辑

> [string01](./string/string01.cc)

### 2. 890. 查找和替换模式

> [string06](./string/string06.cc)

## 2. 子串类题目

### 1. 467. 环绕字符串中唯一的子字符串

> [string02](./string/string02.cc)
>
> `唯一的字串，可以通过求以某个字母结尾的最大长度之和`

## 3. 双指针比对问题

### 1. 面试题 17.11. 单词距离

> [string03](./string/string03.cc)

## 4. ()类字符串问题

### 1. 1021. 删除最外层的括号

> [string04](./string/string04.cc)
>
> `利用栈`

## 5. 遍历字符串问题

### 1. 468. 验证IP地址

> [string05](./string/string05.cc)
>
> `注意所有可能情况，覆盖性测试`

# 9. 二分法

## 1. 二分法猜数类型

### 1. 875. 爱吃香蕉的珂珂

> [divide_conquer01](./divide_conquer/divide_conquer01.cc)