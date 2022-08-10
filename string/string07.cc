#include "..//common//common.h"
/**
 * @brief 640. 求解方程
 * https://leetcode.cn/problems/solve-the-equation/
 * @param equation 
 * @return string 
 */
string solveEquation(string equation);
int main(){
    cout << solveEquation("x+5-3+x=6+x-2") << endl;
    return EXIT_SUCCESS;
}
string solveEquation(string equation) {
    // 怎么会有前导0
    int n = equation.size(), m = equation.find("=");
    int x = 0, k = 0, tmp = 0;
    bool f = equation[0] != '-', xf = true;
    for (int i = !f ? 1 : 0; i < m; ++ i){
        if (equation[i] >= '0' && equation[i] <= '9'){
            tmp = tmp * 10 + equation[i] - '0';
        }
        else if (equation[i] == '+' || equation[i] == '-'){
            if (xf && (i - 1 > -1 || equation[i - 1] != 'x')){
                k += f ? -tmp : tmp;
            }
            xf = true;
            tmp = 0;
            f = equation[i] == '+';
        }
        else{
            tmp = tmp == 0 && (i - 1 < 0 || equation[i - 1] != '0') ? 1 : tmp;
            x += f ? tmp : -tmp;
            tmp = 0;
            xf = false;
        }
    }
    k += f ? -tmp : tmp;
    tmp = 0;
    f = equation[m + 1] != '-';
    xf = true;
    for (int i = !f ? m + 2 : m + 1; i < n; ++ i){
        if (equation[i] >= '0' && equation[i] <= '9'){
            tmp = tmp * 10 + equation[i] - '0';
        }
        else if (equation[i] == '+' || equation[i] == '-'){
            if (xf && (i - 1 > -1 || equation[i - 1] != 'x')){
                k += f ? tmp : -tmp;
            }
            xf = true;
            tmp = 0;
            f = equation[i] == '+';
        }
        else{
            tmp = tmp == 0 && (i - 1 < 0 || equation[i - 1] != '0')  ? 1 : tmp;
            x += f ? -tmp : tmp;
            tmp = 0;
            xf = false;
        }
    }
    k += f ? tmp : -tmp;
    // cout << x << " " << k << endl;
    if (x == 0 && k == 0){
        return "Infinite solutions";
    }
    else if (x == 0){
        return "No solution";
    }
    return "x=" + to_string(k / x);
}