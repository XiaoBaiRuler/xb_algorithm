#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
class Solution {
public:
    /**
     * @brief 241. 为运算表达式设计优先级
     * https://leetcode.cn/problems/different-ways-to-add-parentheses/
     * 
     * 
     * 递推方法
     * 
     * 把 A ? B 作为一个基本单元，那么按照运算符进行分割，逐渐递推下次。最后收敛到(0, m)
     * 
     * @param expression 
     * @return vector<int> 
     */
    vector<int> diffWaysToCompute(string expression) {
        int pre = 0, add = 1, n = expression.length();
        vector<int> number;
        vector<char> chs;
        for (int i = 0; i < n; ++ i){
            char c = expression[i];
            if (c >= '0' && c <= '9'){
                pre = pre * add + (c - '0');
                add *= 10;
            }
            else{
                chs.push_back(c);
                number.push_back(pre);
                pre = 0;
                add = 1;
            }
        }
        number.push_back(pre);
        return circle(number, chs, 0, chs.size());
    }
    vector<int> circle(vector<int>& number, vector<char>& chs, int l, int r){
        vector<int> res;
        if (l == r){
            res.push_back(number[l]);
            return res;
        }
        for (int j = l; j < r; ++ j){
            char c = chs[j];
            vector<int> res1 = circle(number, chs, l, j);
            vector<int> res2 = circle(number, chs, j + 1, r);
            for (int now1 : res1){
                for (int now2 : res2){
                    if (c == '+'){
                        res.push_back(now1 + now2);
                    }
                    else if (c == '-'){
                        res.push_back(now1 - now2);
                    }
                    else{
                        res.push_back(now1 * now2);
                    }
                }
            }
        }
        return res;
    }
};
int main(){
    string s = "2*3-4*5";
    Solution st;
    vector<int> res = st.diffWaysToCompute(s); 
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}