#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 636. 函数的独占时间
 * https://leetcode.cn/problems/exclusive-time-of-functions/submissions/
 * 
 * 栈的使用
 * @param n 
 * @param logs 
 * @return vector<int> 
 */
vector<int> exclusiveTime(int n, vector<string>& logs);
int main(){
    vector<string> logs = {"0:start:0","1:start:2","1:end:5","0:end:6"};
    vector<int> res = exclusiveTime(2, logs);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> exclusiveTime(int n, vector<string>& logs) {
    vector<int> res(n, 0);
    stack<pair<int, int>*> st;
    for (string &s : logs){
        int m = s.size(), t = 0, i = 0;
        bool f = false;
        for (int j = 0; j < m; ++ j){
            char c = s[j];
            if (c <= '9' && c >= '0'){
                t = t * 10 + c - '0';
            }
            else{
                f = s[j + 1] == 's';
                j += f ? 6 : 4;
                i = t;
                t = 0;
            }
        }
        if (f){
            st.push(new pair<int, int>(i, t));
        }
        else{
            pair<int, int> *tmp = st.top();
            res[tmp -> first] += t - tmp -> second + 1;
            st.pop();
            if (!st.empty()) {
                res[st.top() -> first] -= (t - tmp -> second + 1); 
            }
        }
    }
    return res;
}