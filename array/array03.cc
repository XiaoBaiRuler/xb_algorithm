

#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 735. 行星碰撞
 * https://leetcode.cn/problems/asteroid-collision/
 * 
 * 贪心 + 栈的特性
 * @param asteroids 
 * @return vector<int> 
 */
vector<int> asteroidCollision(vector<int>& asteroids);
int main(){
    vector<int> asteroids = {8, -8};
    vector<int> res = asteroidCollision(asteroids);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> now;
    for (int i : asteroids){
        if (i > 0){
            now.push_back(i);
        }
        else{
            i = - i;
            while (!now.empty() && now.back() > 0 && now.back() < i){
                now.pop_back();
            }
            if (!now.empty() && now.back() == i){
                now.pop_back();
            }
            else if (now.empty() || now.back() < 0){
                now.push_back(-i);
            }
        }
    }
    return now;
}