#include "..//common//common.h"
/**
 * @brief 1021. 删除最外层的括号
 * https://leetcode.cn/problems/remove-outermost-parentheses/
 * 
 * 删除每个单元的最外层括号
 * => 除开堆栈模拟中堆栈为空的字符
 * 
 * @param s 
 * @return string 
 */
string removeOuterParentheses(string s);
int main(){
    vector<string> ss = {
        "(()())(())",
        "(()())(())(()(()))",
        "()()"
    };
    int n = ss.size();
    for (int i = 0; i < n; ++ i){
        cout << removeOuterParentheses(ss[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
string removeOuterParentheses(string s) {
    string res = "";
    int n = s.size();
    stack<char> mystack;
    for (char c : s){
        if (c == ')'){
            mystack.pop();
        }
        if (!mystack.empty()){
            res.push_back(c);
        }
        if (c == '('){
            mystack.push('(');
        }
    }
    return res;
}