#define PATH 1
#if PATH == 2
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 467. 环绕字符串中唯一的子字符串
 * https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
 * 
 * 统计以某个字母开头的最大长度之和
 * 
 * @param p 
 * @return int 
 */
int findSubstringInWraproundString(string p);
int main(){
    vector<string> p = {"a", "cac", "zab"};
    int n = p.size();
    for (int i = 0; i < n; ++ i){
        cout << findSubstringInWraproundString(p[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int findSubstringInWraproundString(string p) {
    int n = p.size();
    int pre = p[0], l = 0, temp;
    array<int, 26> hash = {0};
    for (int i = 1; i < n; ++ i){
        if (pre == 'z' && p[i] == 'a'){
            pre = p[i];
        }
        else if (pre + 1 == p[i]){
            pre = p[i];
        }
        else{
            for (int j = l; j < i; ++ j){
                temp = p[j] - 'a';
                if (hash[temp] < i - j){
                    hash[temp] = i - j;
                }
            }
            pre = p[i];
            l = i;
        }
    }
    for (int j = l; j < n; ++ j){
        temp = p[j] - 'a';
        if (hash[temp] < n - j){
            hash[temp] = n - j;
        }
    }
    int res = 0;
    for (int i = 0; i < 26; ++ i){
        res += hash[i];
    }
    return res;
}