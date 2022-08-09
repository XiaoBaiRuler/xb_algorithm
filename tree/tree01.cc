#include "..//common//common.h"
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
void create(vector<vector<int>>& grid, int l, int r, int t, int b, Node* root);
/**
 * @brief 427. 建立四叉树
 * https://leetcode-cn.com/problems/construct-quad-tree/
 * 
 * 所在区域全是一样，就是根节点，否则四分
 * 
 * @param grid 
 * @return Node* 
 */
Node* construct(vector<vector<int>>& grid);

int main(){
    vector<vector<vector<int>>> grids = {
        {
            {1, 0},
            {0, 1}
        },
        {
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0}
        }
    };
    int n = grids.size();
    for (int i = 0; i < n; ++ i){
        construct(grids[i]);
    }
    return EXIT_SUCCESS;
}
Node* construct(vector<vector<int>>& grid) {
    Node* root = new Node();
    int n = grid.size();
    create(grid, 0, n, 0, n, root);
    return root;
}
void create(vector<vector<int>>& grid, int l, int r, int t, int b, Node* root){
    bool f = false;
    for (int i = l; i < r; ++ i){
        for (int j = t; j < b; ++ j){
            if (grid[l][t] != grid[i][j]){
                f = true;
                i = r;
                break;
            }
        }
    }
    if (!f){
        root -> isLeaf = true;
        root -> val = grid[l][t] == 1;
        return;
    }
    root -> val = true;
    int w = (r - l) / 2;
    root -> topLeft = new Node();
    create(grid, l, l + w, t, t + w, root -> topLeft);
    root -> topRight = new Node();
    create(grid, l, l + w, t + w, b, root -> topRight);
    root -> bottomLeft = new Node();
    create(grid, l + w, r, t, t + w, root -> bottomLeft);
    root -> bottomRight = new Node();
    create(grid, l + w, r, t + w, b, root -> bottomRight);
}