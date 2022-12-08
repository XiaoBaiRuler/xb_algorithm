#include "../common/common.h"
/**
 * @brief 365. 水壶问题
 * https://leetcode.cn/problems/water-and-jug-problem/submissions/
 * 1. bfs
 * 2. t % 辗转相除求最大公因数 == 0? 
 */
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        n = jug1Capacity, m = jug2Capacity, t = targetCapacity;
        if (t == 0){
            return true;
        }
        if (n + m < t){
            return false;
        }
        return bfs(0, 0);
    }
protected:
    bool bfs(int i, int j){
        deque<pair<int, int>> dq;
        dq.emplace_front(i, j);
        set<pair<int, int>> se = {};
        se.insert(make_pair(i, j));
        while (!dq.empty()){
            int k = dq.size();
            for (int a = 0; a < k; ++ a){
                i = dq.front().first;
                j = dq.front().second;
                dq.pop_front();
                if (i == t || j == t || i + j == t){
                    return true;
                }
                // 使A满
                pair<int, int> item = make_pair(n, j);
                if (i != n && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
                // 使B满
                item = make_pair(i, m);
                if (j != m && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
                // 使A空
                item = make_pair(0, j);
                if (i != 0 && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
                // 使B空
                item = make_pair(i, 0);
                if (j != 0 && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
                // A -> B 使B满
                item = make_pair(i - (m - j), m);
                if (i + j > m && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
                // A -> B 使A空
                item = make_pair(0, i + j);
                if (i + j < m && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
                // B -> A 使A满
                item = make_pair(n, j - (n - i));
                if (i + j > n && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
                // B -> A 使B空
                item = make_pair(i + j, 0);
                if (i + j < n && !se.count(item)){
                    dq.emplace_back(item);
                    se.insert(item);
                }
            }
        }
        return false;
    }
private:
    int n, m, t;
};
int main(){
    cout << Solution().canMeasureWater(3, 5, 4) << endl;
    return EXIT_SUCCESS;
}