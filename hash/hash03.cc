#include "../common/common.h"
string h = "abcdefghijklmnopqrstuvwxyz0123456789";
/**
 * @brief 535. TinyURL 的加密与解密
 * https://leetcode.cn/problems/encode-and-decode-tinyurl/
 * 
 * 索引hash
 */
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string res = get();
        while (map.find(res) != map.end()){
            res = get();
        }
        int n = longUrl.size() - 1;
        while (n > -1 && longUrl[n] != '/'){
            -- n;
        }
        res = longUrl.substr(0, n + 1) + res;
        map[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
    string get(){
        string res;
        for (int i = 0; i < 6; ++ i){
            res.push_back(h[rand() % 36]);
        }
        return res;
    }
private:
    unordered_map<string, string> map;
};
int main(){
    Solution s;
    string t = "https://leetcode.com/problems/design-tinyurl";
    string res1 = s.encode(t);
    cout << res1 << endl;
    string res2 = s.decode(res1);
    cout << res2 << endl;
    return EXIT_SUCCESS;
}