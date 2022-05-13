#define PATH 1
#if PATH == 2
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 面试题 01.05. 一次编辑
 * https://leetcode.cn/problems/one-away-lcci/
 * 
 * 逻辑题，分类讨论
 * - 长度相差大于1，false
 * - 长度相等, 判断不对应字符是否小于1
 * - 长度相差刚好1, 第一次找出不同时的点，再判断剩下的情况
 * 
 * @param first 
 * @param second 
 * @return true 
 * @return false 
 */
bool oneEditAway(string first, string second);
int main(){
    vector<string> first = {
        "pale", "pales"
    };
    vector<string> second = {
        "ple", "pal"
    };
    int n = first.size();
    for (int i = 0; i < n; ++ i){
        cout << oneEditAway(first[i], second[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
bool oneEditAway(string first, string second) {
    int n = first.size(), m = second.size();
    if (abs(m - n) > 1){
        return false;
    }
    int c = 0;
    if (m == n){
        for (int i = 0; i < n; ++ i){
            if (first[i] != second[i]){
                ++ c;
            }
        }
        return c < 2;
    }
    int i = 0, j = 0;
    while (i < n && j < m){
        if (first[i] != second[j]){
            break;
        }
        ++ i;
        ++ j;
    }
    if (n > m){
        ++ i;
    }
    else{
        ++ j;
    }
    while (i < n && j < m){
        if (first[i] != second[j]){
            return false;
        }
        ++ i;
        ++ j;
    }
    return true;
}