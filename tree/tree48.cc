#include "../common/common.h"
/**
 * @brief 1483. 树节点的第 K 个祖先
 * https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/
 * 
 * pre[i][j]: 表示 i向上2 ^ j个父节点
 * 
 * & != 0 位运算 进行二分查找
 */
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent){
        pre = vector<vector<int>>(n, vector<int>(16));
        for(int i = 0; i < n; ++i){
            pre[i][0] = parent[i];
        }
        for(int j = 1; j < 16; ++j){
            pre[0][j] = -1;
        }
        for(int j = 1; j < 16; ++j){
            for(int i = 0; i < n; ++i)
            {
                if(pre[i][j - 1] == -1){
                    pre[i][j] = -1;
                }
                else{
                    pre[i][j] = pre[pre[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 15; i > -1; --i)
        {
            if(k & (1 << i)){
                node = pre[node][i];
            }
            if(node == -1){
                return -1;
            }
        }
        return node;
    }
private:
    vector<vector<int>> pre;
};
int main(){
    vector<int> res = {-1, 0, 0, 1, 1, 2, 2};
    cout << TreeAncestor(7, res).getKthAncestor(5, 2) << endl;
    return EXIT_SUCCESS;
}