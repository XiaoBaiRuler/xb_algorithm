#include "..//common//common.h"
/**
 * @brief 926. 将字符串翻转到单调递增
 * https://leetcode.cn/problems/flip-string-to-monotone-increasing/
 * 
 * 当前状态是否发生改变
 * 
 * 1. 当为1时
 * 1.1 变0 -> 那么之前为[0] + 1
 * 1.2 不变 -> 那么之前可以[0]/[1]
 * 2. 当为0时
 * 2.1 变1 -> 那么之前为[0]/[1] + 1
 * 2.2 不变 -> 那么之前可以[0]
 * 
 * @param s 
 * @return int 
 */
int minFlipsMonoIncr(string s);
int main(){
    vector<string> s = {
        "00110",
        "010110",
        "00011000"   
    };
    int n = s.size();
    for (int i = 0; i < n; ++ i){
        cout << minFlipsMonoIncr(s[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int minFlipsMonoIncr(string s) {
    int n = s.size();
    int pre0 = s[0] == '0' ? 0 : 1, now0;
    int pre1 = s[0] == '1' ? 0 : 1, now1;
    for (int i = 1; i < n; ++ i){
        if (s[i] == '1'){
            // 变0
            now0 = pre0 + 1;
            // 不变
            now1 = min(pre1, pre0);
        }
        else{
            // 变1
            now1 = min(pre1 + 1, pre0 + 1);
            // 不变
            now0 = pre0;
        }
        pre0 = now0;
        pre1 = now1;
    }
    return min(pre0, pre1);
}