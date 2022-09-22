#include "../common/common.h"
class Tire{
public:
    vector<int> index;
    array<Tire*, 26> next;
};
/**
 * @brief 425. 单词方块
 * https://leetcode.cn/problems/word-squares/
 * 
 * 前缀树 + 记录路径的索引
 */
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        root = new Tire();
        int n = words.size();
        for (int i = 0; i < n; ++ i){
            Tire* now = root;
            for (char c : words[i]){
                int tmp = c - 'a';
                if (now -> next[tmp] == nullptr){
                    now -> next[tmp] = new Tire();
                } 
                now = now -> next[tmp];
                now -> index.push_back(i);
            }
        }
        int size = words[0].size();
        vector<vector<string>> res;
        for (int i = 0; i < n; ++ i){
            int c = size;
            if (c == 1){
                vector<string> item = {
                    words[i]
                };
                res.push_back(item);
                continue;
            }
            c = size - 1;
            Tire *now = root;
            string tmpStr = "";
            tmpStr.push_back(words[i][1]);
            Tire* second = getAll(tmpStr);
            if (second == nullptr){
                continue;
            }
            for (int j : second -> index){
                if (c == 1){
                    vector<string> item = {
                        words[i],
                        words[j]
                    };
                    res.push_back(item);
                    continue;
                }
                c = size - 2;
                tmpStr = "";
                tmpStr.push_back(words[i][2]);
                tmpStr.push_back(words[j][2]);
                Tire* third = getAll(tmpStr);
                if (third == nullptr){
                    continue;
                }
                for (int k : third -> index){
                    if (c == 1){
                        vector<string> item = {
                            words[i],
                            words[j],
                            words[k]
                        };
                        res.push_back(item);
                        continue;
                    }
                    tmpStr = "";
                    tmpStr.push_back(words[i][3]);
                    tmpStr.push_back(words[j][3]);
                    tmpStr.push_back(words[k][3]);
                    Tire* four = getAll(tmpStr);
                    if (four == nullptr){
                        continue;
                    }
                    for (int l : four -> index){
                        vector<string> item = {
                            words[i],
                            words[j],
                            words[k],
                            words[l]
                        };
                        res.push_back(item);
                    }
                }
            }
        }
        return res;
    }
    Tire* getAll(string& s){
        Tire* now = root;
        for (char c : s){
            int tmp = c - 'a';
            if (now -> next[tmp] == nullptr){
                return nullptr;
            }
            now = now -> next[tmp];
        }
        return now;
    }
private:
    Tire* root;
};
int main(){
    vector<string> words = {"area","lead","wall","lady","ball"};
    vector<vector<string>> res = Solution().wordSquares(words);
    cout << res << endl;
    return EXIT_SUCCESS;
}