#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1147. 段式回文
 * https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/
 * 
 * 双指针 + 贪心
 * 
 * 从两端找到最短相同的字符串
 * @param text 
 * @return int 
 */
int longestDecomposition(string text);
int main(){
    cout << longestDecomposition("ghiabcdefhelloadamhelloabcdefghi") << endl;
    return EXIT_SUCCESS;
}
int longestDecomposition(string text) {
    int n = text.size(), l = 0, r = n - 1, c = 0, len = 1;
    while (l < r && len <= r - l){
        if (text.substr(l, len) == text.substr(r - len + 1, len)){
            c += 2;
            l = l + len;
            r = r - len;
            len = 1;
        }
        else{
            len += 1;
        }
    }
    return l == r + 1 ? c : c + 1;   
}