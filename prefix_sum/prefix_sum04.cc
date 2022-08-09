#include "..//common//common.h"
/**
 * @brief 1371. 每个元音包含偶数次的最长子字符串
 * https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 * 
 * 状态压缩 + 前缀异或和
 * 
 * 1. 状态压缩 aeiou 压缩为一个数字(用数字的位来区分字母)
 * 2. 前缀异或和 只要前面有当前异或和相同的值，就构成连续符合条件的字符串
 * @param s 
 * @return int 
 */
int findTheLongestSubstring(string s);
int main(){
    string s = "eleetminicoworoep";
    cout << findTheLongestSubstring(s) << endl;
    return EXIT_SUCCESS;
}
int findTheLongestSubstring(string s) {
    unordered_map<int, int> pre;
    pre[0] = -1;
    unordered_map<char, int> map;
    map['a'] = 1;
    map['e'] = 2;
    map['i'] = 4;
    map['o'] = 8;
    map['u'] = 16;
    int n = s.size(), temp = 0, res = 0;
    for (int i = 0; i < n; ++ i){
        temp ^= map.find(s[i]) == map.end() ? 0 : map[s[i]];
        if (pre.find(temp) != pre.end()){
            res = max(res, i - pre[temp]);
        }
        else{
            pre[temp] = i;
        }
    }
    return res;
}