#include "..//common//common.h"
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
/**
 * @brief 558. 四叉树交集
 * https://leetcode.cn/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/
 * 
 * 
 * 四叉树所代表的数组之间的或运算 + DFS
 * @param quadTree1 
 * @param quadTree2 
 * @return Node* 
 */
Node* intersect(Node* quadTree1, Node* quadTree2);
Node* build(Node* l, Node* r);
int main(){
    return EXIT_SUCCESS;
}
Node* intersect(Node* quadTree1, Node* quadTree2) {
    return build(quadTree1, quadTree2);
}
Node* build(Node* l, Node* r){
    // 当都为叶子节点时: 逻辑或
    if (l -> isLeaf && r -> isLeaf){
        return l -> val ? new Node(l -> val | r -> val, true, nullptr, nullptr, nullptr, nullptr) : r;
    }
    // 当l为叶子节点，如果为值为1 则以l为准，否则就是r
    else if (l -> isLeaf){
        return l -> val ? new Node(true, true, nullptr, nullptr, nullptr, nullptr) : r;
    }
    // 当r为叶子节点，如果为值为1 则以r为准，否则就是l
    else if (r -> isLeaf){
        return r -> val ? new Node(true, true, nullptr, nullptr, nullptr, nullptr) : l;
    }
    // 两个都不是叶子节点 - dfs
    // 1. 如果四方向都是1，且都为叶子节点: 那么父节点的也为叶子节点, 值为1
    // 2. 否则值为0
    else{
        Node* topLeft = build(l -> topLeft, r -> topLeft);
        Node* topRight = build(l -> topRight, r -> topRight);
        Node* bottomLeft = build(l -> bottomLeft, r -> bottomLeft);
        Node* bottomRight = build(l -> bottomRight, r -> bottomRight);
        if (topLeft -> val && topLeft -> isLeaf 
                && topRight -> val && topRight -> isLeaf 
                && bottomLeft -> val && bottomLeft -> isLeaf 
                && bottomRight -> val && bottomRight -> isLeaf){
            return new Node(true, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
}