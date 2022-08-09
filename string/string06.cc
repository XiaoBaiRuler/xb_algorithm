#include "..//common//common.h"
/**
 * @brief 890. 查找和替换模式
 * https://leetcode.cn/problems/find-and-replace-pattern/
 * 
 * 类似模式，并且保持一一对应
 * 
 */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        vector<int> pre(26);
        for (const string& word : words){
            // 正面 反面都要对应
            if (check(word, pattern, pre) && check(pattern, word, pre)){
                res.push_back(word);
            }
        }
        return res;
    }
    bool check(const string& word, const string& pattern, vector<int>& pre){
        fill(pre.begin(), pre.end(), -1);
        int n = word.size();
        for (int i = 0; i < n; ++ i){
            int it = word[i] - 'a';
            if (pre[it] == -1){
                pre[it] = pattern[i] - 'a';
            }
            else if (pre[it] != pattern[i] - 'a'){
                return false;
            }
        }
        return true;
    }
};
int main(){
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    Solution t;
    vector<string> res = t.findAndReplacePattern(words, pattern); 
    for (const string &r : res){
        cout << r << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}