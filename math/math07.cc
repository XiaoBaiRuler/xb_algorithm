#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 556. 下一个更大元素 III
 * https://leetcode.cn/problems/next-greater-element-iii/
 * 
 * 1. 倒序获取数字列表
 * 2. 从前往后找非增序的索引i
 * 3. 从前往后找到比i所在值大的索引j
 * 4. 交换i, j的值
 * 5. 并对i之前的数字进行增序排序
 * @param n 
 * @return int 
 */
int nextGreaterElement(int n);
int main(){
    cout << nextGreaterElement(2147483647) << endl;
    return EXIT_SUCCESS;
}
int nextGreaterElement(int n) {
    int m = n;
    vector<int> now;
    while (m != 0){
        now.push_back(m % 10);
        m /= 10;
    }
    m = now.size();
    if (m < 1){
        return -1; 
    }
    auto beg = now.begin(), end = beg + 1;
    int j = 1;
    for (; j < m; ++ j){
        if (now[j - 1] > now[j]){
            break;
        }
        ++ end;
    }
    if (j == m){
        return -1;
    }
    for (int i = 0, temp; i < j; ++ i){
        if (now[i] > now[j]){
            temp = now[i];
            now[i] = now[j];
            now[j] = temp;
            break;
        }
    }
    sort(beg, end, [](int x,int y){return x > y;});
    long long res = 0, t = 1;
    for (int i = 0; i < m; ++ i){
        res += t * now[i];
        t *= 10;
    }
    return res <= n || res > INT_MAX ? -1 : res;
}