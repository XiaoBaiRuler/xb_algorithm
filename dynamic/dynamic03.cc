#include "G:\algorithm\xb_algorithm\common\common.h"
/**
 * @brief 1055. 形成字符串的最短路径    
 * https://leetcode-cn.com/problems/shortest-way-to-form-string/
 * 
 * 贪心 + 动态规划
 * 
 * @param source 
 * @param target 
 * @return int 
 */
int shortestWay(string source, string target);
int main(){
    vector<string> source = {
        "abc", "abc", "xyz", "aaaaa"  
    };
    vector<string> target = {
        "abcbc", "acdbc", "xzyxz", "aaaaaaaaaaa"
    };
    int n = source.size();
    for (int i = 0; i < n; ++ i){
        cout << shortestWay(source[i], target[i]) << endl;
    }
    return EXIT_SUCCESS;
}
int shortestWay(string source, string target) {
    int n = target.size(), m = source.size(), res = 0;
    int i = 0, j = 0, pre = i;
    while (i < n){
        if (target[i] == source[j]){
            ++ i;
            ++ j;
        }
        else{
            ++ j;
        }
        if (j == m){
            if (pre == i){
                return -1;
            }
            j = 0;
            pre = i;
            ++ res;
        }
    }
    return pre == i ? res : res + 1;
}