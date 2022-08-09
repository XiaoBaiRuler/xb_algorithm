#include "..//common//common.h"
/**
 * @brief 812. 最大三角形面积
 * https://leetcode.cn/problems/largest-triangle-area/
 * 
 * 向量邻边构成三角形面积等于向量邻边构成平行四边形面积的一半
 * 三角形面积公式: (x1, y1)(x2, y2)(x3,y3) => 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2)
 * 
 * @param points 
 * @return double 
 */
double largestTriangleArea(vector<vector<int>>& points);
int main(){
    vector<vector<int>> points = {
        {0,0},{0,1},{1,0},{0,2},{2,0}
    };
    cout << largestTriangleArea(points) << endl;
    return EXIT_SUCCESS;
}
double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();
    double ret = 0.0;
    for (int i = 0; i < n; i++) {
        int x1 = points[i][0], y1 = points[i][1];
        for (int j = i + 1; j < n; j++) {
            int x2 = points[j][0], y2 = points[j][1];
            for (int k = j + 1; k < n; k++) {
                int x3 = points[k][0], y3 = points[k][1];
                ret = max(ret, 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2));
            }
        }
    }
    return ret;
}