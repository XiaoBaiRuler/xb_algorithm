#define PATH 1
#if PATH == 2
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 面试题 17.11. 单词距离
 * https://leetcode.cn/problems/find-closest-lcci/
 * 
 * 双指针查询
 * 
 * 当之前查询到word和现在一样，更新左指针索引
 * 当之前查询到word和现在不一样，当前指针和左指针的距离的最小值即为答案
 * 
 * 优化建议:
 * 有两次重复判断string是否相等，可以使用hash减少判断
 * 
 * @param words 
 * @param word1 
 * @param word2 
 * @return int 
 */
int findClosest(vector<string>& words, string word1, string word2);
int main(){
    vector<string> words = {"I","am","a","student","from","a","university","in","a","city"};
    string word1 = "I";
    string word2 = "a";
    cout << findClosest(words, word1, word2) << endl;
    return EXIT_SUCCESS;
}
int findClosest(vector<string>& words, string word1, string word2) {
    int n = words.size(), res = n, l = 0, flag = 0;
    for (int i = 0; i < n; ++ i){
        if (words[i] == word1){
            if (flag == 2 && res > i - l){
                res = i - l;
            }
            l = i;
            flag = 1;
        }
        else if (words[i] == word2){
            if (flag == 1 && res > i - l){
                res = i - l;
            }
            l = i;
            flag = 2;
        }
    }
    return res;
}