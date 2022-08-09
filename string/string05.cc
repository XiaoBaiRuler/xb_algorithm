#include "..//common//common.h"
class Solution {
public:
    /**
     * @brief 468. 验证IP地址
     * 
     * https://leetcode.cn/problems/validate-ip-address/
     * 
     * 有点眼高手低了，错了好多次边界条件，要谋而后动。
     * 
     * IPV4: 
     *  1. 长度问题: [7, 15]
     *  2. 单个单元长度: [1, 3]
     *  3. 单个单元大小: [0, 255]
     *  4. 单个单元是否包含前导0问题
     *  5. 字符问题: [0-9/.]
     *  6. .数量问题，也即是单元数量问题: [3]
     *  7. 注意最后一个单元
     * 
     * IPV6:
     *  1. 长度问题: [15, 39]
     *  2. 单个单元长度: [1, 4]
     *  3. 字符问题: [0-9a-fA-F/:]
     *  4. :数量问题，也即是单元数量问题: [4]
     *  5. 注意最后一个单元
     * @param queryIP 
     * @return string 
     */
    string validIPAddress(string queryIP) {
        // IPV4: 不能前导0 xi[0-255] x1.x2.x3.x4
        // IPV6: 可以前导0 xi[a-fA-F0-9] xi.length[1, 4] x1:x2:x3:x4:x5:x6:x7:x8
        int n = queryIP.size();
        if (n < 7){
            return "Neither";
        }
        if (queryIP[3] == '.'){
            return checkIPV4(queryIP) ? "IPv4" : "Neither";
        }
        else{
            return checkIPV6(queryIP) ? "IPv6" : "Neither";
        }
    }
    bool checkIPV4(string& query){
        int now = 0, j = 0, n = query.size(), l = 0;
        if (n > 15 || n < 7){
            return false;
        }
        bool flag = true;
        for (int i = 0; i < n; ++ i){
            char c = query[i];
            if (isdigit(c)){
                if (!flag && now == 0){
                    return false;
                }
                flag = false;
                now = now * 10 + (c - '0'); 
            }
            else if (c == '.'){
                if (now > 255 || i - l == 0){
                    return false;
                }
                flag = true;
                now = 0;
                ++ j;
                l = i + 1;
            }
            else{
                return false;
            }
        }
        return j == 3 && now < 256 && n - l > 0;
    }
    bool checkIPV6(string& query){
        int l = 0, n= query.size(), j = 0;
        if (n > 39 || n < 15){
            return false;
        }
        for (int i = 0; i < n; ++ i){
            char c = tolower(query[i]);
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')){
                continue;
            }
            else if (c == ':'){
                if (i - l > 4 || i - l == 0){
                    return false;
                }
                l = i + 1;
                ++ j;
            }
            else{
                return false;
            }
        }
        return j == 7 && (n - l) < 5 && (n - l) > 0;
    }
};
int main(){
    vector<string> queryIP = {
        "2001:0db8:85a3:0:0:8A2E:0370:7334",
        "172.16.254.1",
        "256.256.256.256",
        "192.168.1.1",
        "192.168.1.0",
        "192.168.01.1",
        "192.168.1.00",
        "2001:db8:85a3:0:0:8A2E:0370:7334",
        "2001:0db8:85a3::8A2E:037j:7334",
        "02001:0db8:85a3:0000:0000:8a2e:0370:7334",
        "2001:0db8:85a3:0:0:8A2E:0370:7334:",
        "1.0.1.",
        "12..33.4",
        "2001:0db8:85a3:0:0:8A2E::",
        "0.0.0.256",
        "",
    };
    Solution s;
    int n = queryIP.size();
    for (int i = 0; i < n; ++ i){
        cout << s.validIPAddress(queryIP[i]) << " "; 
    }
    cout << endl;
    return EXIT_SUCCESS;
}