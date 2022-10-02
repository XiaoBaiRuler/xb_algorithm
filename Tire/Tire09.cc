#include "../common/common.h"
class Tire{
public:
    int index = -1;
    array<Tire*, 26> next;
};
/**
 * @brief 820. 单词的压缩编码
 * https://leetcode.cn/problems/short-encoding-of-words/
 * 
 * 先排序 + 前缀树
 */
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string &b){
            int n = a.size(), m = b.size();
            if (n == m){
                return a <= b;
            }
            return n < m;
        });
        int n = words.size();
        Tire *root = new Tire(); 
        vector<bool> del(n, true);
        for (int i = 0; i < n; ++ i){
            Tire *now = root;
            for (int j = words[i].size() - 1; j > -1; -- j){
                int tmp = words[i][j] - 'a';
                if (now -> next[tmp] == nullptr){
                    now -> next[tmp] = new Tire();
                }
                now = now -> next[tmp];
                if (now -> index != -1){
                    del[now -> index] = false;
                }
            }
            if (now -> index != -1){
                del[now -> index] = false;
            }
            now -> index = i;
        }
        int res = 0;
        for (int i = 0; i < n; ++ i){
            if (del[i]){
                res += words[i].size() + 1;
            }
        }
        return res;
    }
};
int main(){
    vector<string> words = {"time", "me", "bell"};
    cout << Solution().minimumLengthEncoding(words) << endl;
    return EXIT_SUCCESS;
}
