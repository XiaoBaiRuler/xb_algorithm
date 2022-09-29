#include "../common/common.h"
/**
 * @brief 443. 压缩字符串
 * https://leetcode.cn/problems/string-compression/
 * 
 * 双指针
 * @param chars 
 * @return int 
 */
int compress(vector<char>& chars);
int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int n = compress(chars);
    for (int i = 0; i < n; ++ i){
        cout << chars[i] << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int compress(vector<char>& chars) {
    char tmp = chars[0];
    int n = chars.size(), now = 1,  j = 0;
    for (int i = 1; i < n; ++ i){
        if (chars[i] != tmp){
            chars[j ++] = tmp;
            if (now > 1){
                string it = to_string(now);
                for (char c : it){
                    chars[j ++] = c;
                }
            }
            now = 1;
            tmp = chars[i];
        }
        else{
            ++ now;
        }
    }
    chars[j ++] = tmp;
    if (now > 1){
        string it = to_string(now);
        for (char c : it){
            chars[j ++] = c;
        }
    }
    return j;
}