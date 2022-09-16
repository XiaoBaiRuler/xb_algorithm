#include "..//common//common.h"
class Trie{
public:
    bool flag = false;
    array<Trie*, 26> next;
};
/**
 * @brief 211. 添加与搜索单词 - 数据结构设计
 * https://leetcode.cn/problems/design-add-and-search-words-data-structure/
 * 
 * 使用前缀树
 */
class WordDictionary {
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *now = root;
        for (char c : word){
            int tmp = c - 'a';
            if (now -> next[tmp] == nullptr){
                now -> next[tmp] = new Trie();    
            }
            now = now -> next[tmp];
        }
        now -> flag = true;
    }
    
    bool search(string word) {
        return searchTrie(word, root);
    }
    bool searchTrie(string word, Trie* now){
        int n = word.size();
        if (n == 0){
            return now -> flag;   
        }
        for (int i = 0; i < n; ++ i){
            int tmp = word[i] - 'a';
            if (tmp != DOT){
                Trie *next = now -> next[tmp];
                if (next == nullptr){
                    return false;
                }
                now = next;
            }
            else{
                for (Trie *ne : now -> next){
                    if (ne != nullptr && searchTrie(word.substr(i + 1), ne)){
                        return true;
                    }
                }
                return false;
            }
        }
        return now -> flag;
    }
private:
    Trie *root;
    int DOT = '.' - 'a';
};
int main(){
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout 
    << wordDictionary.search("pad") << " " // 返回 False
    << wordDictionary.search("bad") << " " // 返回 True
    << wordDictionary.search(".ad") << " " // 返回 True
    << wordDictionary.search("b..") << " "; // 返回 True
    return EXIT_SUCCESS;
}