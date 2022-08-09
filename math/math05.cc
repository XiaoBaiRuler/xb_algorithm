#include "..//common//common.h"
bool isBoomerang1(vector<vector<int>>& points);
bool isBoomerang2(vector<vector<int>>& points);
int main(){
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    cout << isBoomerang1(points) << endl;
    cout << isBoomerang2(points) << endl;
    return EXIT_SUCCESS;
}
/**
 * @brief   
 * https://leetcode.cn/problems/valid-boomerang/
 * 
 * 线性函数法
 * @param points 
 * @return true 
 * @return false 
 */
bool isBoomerang1(vector<vector<int>>& points) {
    if (points[1][0] == points[0][0]){
        return points[1][1] != points[0][1] 
            && points[2][0] != points[0][0];
    }
    long double a = (long double)(points[1][1] - points[0][1]) / (points[1][0] - points[0][0]);
    long double b = - points[0][0] * a + points[0][1];
    return abs(a * points[2][0] + b - points[2][1]) > 10e-5;
}
/**
 * @brief 
 * 向量法
 * @param points 
 * @return true 
 * @return false 
 */
bool isBoomerang2(vector<vector<int>>& points) {
    vector<int> v1 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
    vector<int> v2 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
    return v1[0] * v2[1] - v1[1] * v2[0] != 0;
}