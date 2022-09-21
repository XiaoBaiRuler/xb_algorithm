#include "../common/common.h"
class Tire{
public:
    int index = -1;
    array<Tire*, 26> next;
};
/**
 * @brief 336. 回文对
 * https://leetcode.cn/problems/palindrome-pairs/
 * 
 * 字典树
 * 1. 空字符
 * 2. (A + 回文串, A)
 * 3. (A, 回文串 + A)
 */
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        root = new Tire();
        int n = words.size();
        for (int i = 0; i < n; ++ i){
            Tire *now = root;
            for (char c : words[i]){
                int tmp = c - 'a';
                if (now -> next[tmp] == nullptr){
                    now -> next[tmp] = new Tire();
                }
                now = now -> next[tmp];
            }
            now -> index = i;
        }
        vector<vector<int>> res;
        for (int i = 0; i < n; ++ i){
            int m = words[i].size(), id;
            // 空字符
            if(checkOne(words[i], 0, m - 1) 
                && (id = root -> index) != -1 
                && id != i){
                vector<int> item = {i, id};
                res.emplace_back(item);
            }
            for (int j = 0; j < m; ++ j){
                // (A + 回文串, A)
                if(checkOne(words[i], j + 1, m - 1) 
                    && (id = checkTwo(words[i], -1, j)) != -1 
                    && id != i){
                    vector<int> item = {i, id};
                    res.emplace_back(item);
                }
                // (A, 回文串 + A)
                if (checkOne(words[i], 0, j)
                    && (id = checkTwo(words[i], j, m - 1)) != -1 
                    && id != i){
                        vector<int> item = {id, i};
                        res.emplace_back(item);
                }
            }
        }
        return res;
    }
    bool checkOne(string& s, int l, int r){
        while (l < r && s[l] == s[r]){
            ++ l;
            -- r;
        }
        return l >= r;
    }
    int checkTwo(string& s, int l, int r){
        Tire* now = root;
        for (int i = r; i > l; -- i){
            int tmp = s[i] - 'a';
            if (now -> next[tmp] == nullptr){
                return -1;
            }
            now = now -> next[tmp];
        }
        return now -> index;
    }

private:
    Tire *root;
};
int main(){
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    vector<vector<int>> res = Solution().palindromePairs(words);
    cout << res << endl; 
    return EXIT_SUCCESS;
}