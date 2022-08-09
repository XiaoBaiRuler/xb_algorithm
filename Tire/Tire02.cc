#include "..//common//common.h"
class Trie{
public:
    bool flag = false;
    array<Trie*, 26> next;
};
/**
 * @brief 676. 实现一个魔法字典
 * https://leetcode.cn/problems/implement-magic-dictionary/
 * 
 * 注意等长
 * 
 */
class MagicDictionary {
public:
    MagicDictionary() : root(new Trie()){}
    void buildDict(vector<string> dictionary) {
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
    }
    bool search(string searchWord) {
        Trie *now = root;
        if (now == nullptr){
            return false;
        }
        int n = searchWord.size();
        for (int i = 0; i < n && now != nullptr; ++ i){
            if (check(i + 1, searchWord, now)){
                return true;
            }
            now = now -> next[searchWord[i] - 'a'];
        }
        return false;
    }
    inline bool check(int i, const string& searchWord, Trie* now){
        int n = searchWord.size();
        Trie* un = now -> next[searchWord[i - 1] - 'a'];
        for (Trie* t : now -> next){
            if (t == nullptr){
                continue;
            }
            if (t == un){
                continue;
            }
            int j = i;
            for (; j < n && t -> next[searchWord[j] - 'a'] != nullptr; ++ j){
                t = t -> next[searchWord[j] - 'a'];
            }
            if (j == n && t != nullptr && t -> flag){
                return true;
            }
        }
        return false;
    }
private:
    Trie* root;
};
int main(){
    vector<string> words = {"hello", "leetcode"};
    vector<string> s = {"hello", "hhllo", "hell", "leetcoded"};
    MagicDictionary md;
    md.buildDict(words);
    int n = s.size();
    for (int i = 0; i < n; ++ i){
        cout << md.search(s[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}