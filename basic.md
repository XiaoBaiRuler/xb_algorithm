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

### 9. 剑指 Offer II 091. 粉刷房子

> [dynamic27](./dynamic/dynamic27.cc)
>
> `维度是红蓝绿`

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

### 6. 714. 买卖股票的最佳时机含手续费

> [dynamic25](./dynamic/dynamic25.cc)
>
> `i时间[i - n], state状态是否持有 注意卖出时收费` 

## 6. 双串类问题

### 1. 1143. 最长公共子序列

> [dynamic26](./dynamic/dynamic26.cc)
>
> `两个字符串分别作为一条串` 

### 2. 712. 两个字符串的最小ASCII删除和

> [dynamic28](./dynamic/dynamic28.cc)
>
> `两个字符串分别作为一条串` 
>
> `总和 - 最大公共部分之和(同1143. 最长公共子序列)`

### 3. 718. 最长重复子数组

> [dynamic29](./dynamic/dynamic29.cc)
>
> `两个数组分别作为一条串` 
>
> `子数组是要求连续的`

### 4. 72. 编辑距离

> [dynamic30](./dynamic/dynamic30.cc)
>
> `双串类型: i, j; 代表i之前字符串，需要j之前字符串操作最小次数能转换`

### 5. 44. 通配符匹配

> [dynamic31](./dynamic/dynamic31.cc)
>
> `双串系列(i, j): i之前的字符串，j之前的字符串经过正则变换之后，是否匹配`

### 6. 10. 正则表达式匹配

> [dynamic32](./dynamic/dynamic32.cc)
>
> `双串系列(i, j): i之前的字符串1，j之前的字符串2是否匹配`

### 7. 97. 交错字符串

> [dynamic33](./dynamic/dynamic33.cc)
>
> `双串系列(i, j): i之前的s1字符，j之前的s2字符，能否交错组成s3`

### 8. 115. 不同的子序列

> [dynamic34](./dynamic/dynamic34.cc)
>
> `双串系列(i, j): i之前的字符串1经过多少次变幻可以变成j之前的字符串2`

## 7. 带维度的双串系列

### 1. 87. 扰乱字符串

> [dynamic35](./dynamic/dynamic35.cc)
> `双串加维度系列(i, j, k): s1在i开始的k个字符是否经过扰动能和s2在j开始的k个字符相等`

## 8. 矩阵类问题

### 1. 120. 三角形最小路径和

> [dynamic36](./dynamic/dynamic36.cc)
>
> `当前的选择只以前面当前位置和上一个位置有关`

### 2. 64. 最小路径和

> [dynamic37](./dynamic/dynamic37.cc)
>
> `当前的位置，只与上面和左面一个位置有关`

### 3. 174. 地下城游戏

> [dynamic38](./dynamic/dynamic38.cc)
>
> `(i, j)的状态就是勇者从该位置开始所需的最低血量`

### 4. 221. 最大正方形

> [dynamic39](./dynamic/dynamic39.cc)
>
> `设以(i, j)为右下角可以构造的正方形的最大边长`

### 5. 931. 下降路径最小和

> [dynamic40](./dynamic/dynamic40.cc)
>
> `(i, j): 到达i, j位置的最小值 `

## 9. 矩阵带维度类问题

### 1.  85. 最大矩形

> [dynamic41](./dynamic/dynamic41.cc)
>
> `由最大正方形 + 前缀和 => 最大矩形`

### 2. 363. 矩形区域不超过 K 的最大数值和

> [dynamic42](./dynamic/dynamic42.cc)
>
> `前缀和 + 枚举上下边界 + set`

### 3. 面试题 17.24. 最大子矩阵

> [dynamic43](./dynamic/dynamic43.cc)
>
> `前序和 + 枚举两个端点 + 贪心剪枝`

## 10. 区间动态规划

### 1. 常数个小规模问题 -> 大规模问题

#### 1. 5. 最长回文子串

> [dynamic44](./dynamic/dynamic44.cc)
>
> `(l, r)表示l - r能不能构成回文串`

#### 2. 647. 回文子串

> [dynamic45](./dynamic/dynamic45.cc)
>
> `(l, r)表示l - r能不能构成回文串`

#### 3. 516. 最长回文子序列

> [dynamic46](./dynamic/dynamic46.cc)
>
> `(l, r)表示l - r所能达成的最大序列大小`

#### 4. 730. 统计不同回文子序列

> [dynamic47](./dynamic/dynamic47.cc)
>
> `730. 统计不同回文子序列`

### 2. O(n)个小规模问题 -> 大规模问题

#### 1. 664. 奇怪的打印机

> [dynamic47](./dynamic/dynamic47.cc)

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

### 1. 四叉树的创建

#### 1. 427. 建立四叉树

> [tree01](./tree/tree01.cc)

### 2. 四叉树的遍历

#### 1. 473. 火柴拼正方形

> [tree06](./tree/tree06.cc)

#### 2. 558. 四叉树交集

> [tree11](./tree/tree11.cc)

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

#### 2. 814. 二叉树剪枝

> [tree12](./tree/tree12.cc)
>
> `逐渐缩小问题规模 再收敛`

### 4. 层序遍历

#### 1. 449. 序列化和反序列化二叉搜索树

> [tree03](./tree/tree03.cc)

#### 2. 513. 找树左下角的值

> [tree09](./tree/tree09.cc)

#### 3. 515. 在每个树行中找最大值

> [tree10](./tree/tree10.cc)

#### 4. 919. 完全二叉树插入器

> [tree13](./tree/tree13.cc)

### 5. 1161. 最大层内元素和

> [tree14](./tree/tree14.cc)

### 6. 623. 在二叉树中增加一行

> [tree16](./tree/tree16.cc)

## 3. 二叉搜索树

### 1. 面试题 04.06. 后继者

> [tree04](./tree/tree04.cc)

### 2. 450. 删除二叉搜索树中的节点

> [tree07](./tree/tree07.cc)

### 3. 235. 二叉搜索树的最近公共祖先

> [tree15](./tree/tree15.cc)

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

## 6. 数字变换问题

### 1. 556. 下一个更大元素 III

> [math07](./math/math07.cc)

# 6. 数组类问题

## 1. 简单索引应用

### 1. 1252. 奇数值单元格的数目

> [array02](./array/array02.cc)

## 2. 双指针类问题

### 1. 713. 乘积小于 K 的子数组

> [array01](./array/array01.cc)

## 3. 模拟栈

### 1. 735. 行星碰撞

> [array03](./array/array03.cc)

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

# 10. 排序

## 1. 桶排序

### 1. 324. 摆动排序 II

> [sort01](./sort/sort01.cc)

# 11. 递推/递归

## 1. 递推

### 1. 241. 为运算表达式设计优先级

> [recursion01](./recursion/recursion01.cc)

# 12. 链表

## 1. 单链表

### 1. 24. 两两交换链表中的节点

> [list01](./list/list01.cc)

# 13. 前缀树

## 1. 前缀树构建和使用

### 1. 648. 单词替换

> [Tire01](./Tire/Tire01.cc)

### 2. 676. 实现一个魔法字典

> [Tire02](./Tire/Tire02.cc)

# 14. 前缀和/积/异或

## 1. 数组构造前缀和/积/异或

### 1. 304. 二维区域和检索 - 矩阵不可变

> [prefix_sum01](./prefix_sum/prefix_sum01.cc)
>
> `(row2, col2) + (row1 - 1, col1 - 1) - (row2, col1 - 1) - (row1 - 1)(col2)`

### 2. 238. 除自身以外数组的乘积

> [prefix_sum09](./prefix_sum/prefix_sum09.cc)
>
> `前缀和 +  后缀和`

### 3. 724. 寻找数组的中心下标

> [prefix_sum10](./prefix_sum/prefix_sum10.cc)
>
> `前缀和 +  后缀和`

### 4. 1074. 元素和为目标值的子矩阵数量

> [prefix_sum12](./prefix_sum/prefix_sum12.cc)
>
> `再利用Hash构造前缀和优化`

### 5. 1314. 矩阵区域和

> [prefix_sum13](./prefix_sum/prefix_sum13.cc)

### 6. 152. 乘积最大子数组

> [prefix_sum14](./prefix_sum/prefix_sum14.cc)

### 7. 1352. 最后 K 个数的乘积

> [prefix_sum15](./prefix_sum/prefix_sum15.cc)

### 8. 1310. 子数组异或查询

> [prefix_sum16](./prefix_sum/prefix_sum16.cc)

### 9. 1442. 形成两个异或相等数组的三元组数目

> [prefix_sum17](./prefix_sum/prefix_sum17.cc)

## 2. Hash构造前缀和/积/异或

### 1. 325. 和等于 k 的最长子数组长度

> [prefix_sum02](./prefix_sum/prefix_sum02.cc)

### 2. 525. 连续数组

> [prefix_sum03](./prefix_sum/prefix_sum03.cc)
>
> `把0变-1，那么就是求和为0的最长数组了`

### 3. 1371. 每个元音包含偶数次的最长子字符串

> [prefix_sum04](./prefix_sum/prefix_sum04.cc)
> 
> `状态压缩 + 前缀异或和`

### 4. 560. 和为 K 的子数组

> [prefix_sum05](./prefix_sum/prefix_sum05.cc)
> 
> `记录前缀和个数`

### 5. 1248. 统计「优美子数组」

> [prefix_sum06](./prefix_sum/prefix_sum06.cc)
> 
> `记录前面偶数个数 + 1`

### 6. 523. 连续的子数组和

> [prefix_sum07](./prefix_sum07.cc)

### 7. 974. 和可被 K 整除的子数组

> [prefix_sum08](./prefix_sum/prefix_sum08.cc)

### 8. 1477. 找两个和为目标值且不重叠的子数组

> [prefix_sum11](./prefix_sum/prefix_sum11.cc)

## 3. 差分问题

### 1. 370. 区间加法

> [prefix_sum18](./prefix_sum/prefix_sum18.cc)

# 15. 队列

## 1. 循环队列

### 1. 622. 设计循环队列

> [queue01](./queue/queue01.cc)
>
> `计数法`

# 16. 贪心

## 1. 1147. 段式回文

> [greedy01](./greedy/greedy01.cc)