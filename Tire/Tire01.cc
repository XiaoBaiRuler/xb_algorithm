#define PATH 1
#if PATH == 2
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
class Trie{
public:
    bool flag = false;
    array<Trie*, 26> next;
};
class Solution {
public:
    /**
     * @brief 648. 单词替换
     * https://leetcode.cn/problems/replace-words/
     * 
     * 构建前缀树，可以再用hash优化
     * @param dictionary 
     * @param sentence 
     * @return string 
     */
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for (string &s : dictionary){
            Trie *now = root;
            for (char c : s){
                if (now -> next[c - 'a'] == nullptr){
                    now -> next[c - 'a'] = new Trie();
                }
                now = now -> next[c - 'a'];
            }
            now -> flag = true;
        }
        int i = 0, pre = 0, n = sentence.size();
        string res = "";
        while ((i = sentence.find(' ', pre)) != string::npos){
            string it = sentence.substr(pre, i - pre);
            res += get_sample(root, it) + " ";
            pre = i + 1;
        }
        string it = sentence.substr(pre, n - pre);
        res += get_sample(root, it);
        return res;
    }
    string get_sample(Trie* root, string& it){
        string res = "";
        for (char c : it){
            if (root -> flag){
                return res;
            }
            if (root -> next[c - 'a'] == nullptr){
                return it;
            }
            else{
                res.push_back(c);
                root = root -> next[c - 'a'];
            }
        }
        return res;
    }
};
int main(){
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    Solution t;
    cout << t.replaceWords(dictionary, sentence) << endl;
    return EXIT_SUCCESS;
}