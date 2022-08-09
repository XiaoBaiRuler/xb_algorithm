#include "..//common//common.h"
/**
 * @brief 478. 在圆内随机生成点
 * https://leetcode.cn/problems/generate-random-point-in-a-circle/
 * 
 * 拒绝采样，面积随机
 * 在正方形中生成点时（正方形中心的坐标简记为原点），如果我们在 [-R, R)[−R,R) 的范围内生成随机数，
 * 那么是无法生成到横坐标或纵坐标恰好为 RR 的点，对应到圆上时，会有圆周上与正方形边相切的两个点无法随机到。
 * 我们可以在生成时稍微提高右边界（例如 2R + \epsilon2R+ϵ，
 * 其中 ϵ 是一个很小的常数，例如 10^{-7} 或者直接忽略这两个点，因为它们的勒贝格测度为零。
 */
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;

public:
    Solution(double radius, double x_center, double y_center): dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}

    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r) {
                return {xc + x, yc + y};
            }
        }
    }
};