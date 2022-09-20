#include "../common/common.h"
class Trie{
public: 
    array<Trie*, 26> next;
};
vector<vector<int>> DIR = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
/**
 * @brief 212. 单词搜索 II
 * https://leetcode.cn/problems/word-search-ii/
 * 
 * 前缀树 + dfs
 * 注意，可以使用更新值再复原来防止重复遍历同一个位置的字符
 */
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                dfsAdd(board, root, i, j, 0);
            }
        }
        vector<string> res;
        for (string& s : words){
            if (findWord(root, s)){
                res.push_back(s);
            }
        }
        return res;
    }
    void dfsAdd(vector<vector<char>>& board, Trie* now, int i, int j, int size){
        if (size == 10){
            return;
        }
        ++ size;
        char c = board[i][j];
        int tmp = c - 'a';
        if (now -> next[tmp] == nullptr){
            now -> next[tmp] = new Trie();
        }
        now = now -> next[tmp];
        board[i][j] = '#';
        for (auto& d : DIR){
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] == '#'){
                continue;
            }
            dfsAdd(board, now, x, y, size);
        }
        board[i][j] = c;
    }
    bool findWord(Trie* now, string word){
        for (char c : word){
            int tmp = c - 'a';
            if (now -> next[tmp] == nullptr){
                return false;
            }
            now = now -> next[tmp];
        }
        return true;
    }
private:
    int n, m;
};
int main(){
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'},
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> res = Solution().findWords(board, words);
    cout << res << endl;
}