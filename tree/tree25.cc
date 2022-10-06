#include "../common/common.h"
/**
 * @brief 331. 验证二叉树的前序序列化
 * https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/
 * 
 * 1. 一颗树的结点的总入度 = 总出度
 * 
 * 2. 一个null节点提供一个入度
 * 3. 一个非null节点提供一个入度两个出度
 * 
 * 4. 在还没遍历完之前出度是大于入度的，在停止时才会相等
 * @param preorder 
 * @return true 
 * @return false 
 */
bool isValidSerialization1(string preorder);
/**
 * @brief 
 * 
 * - 把叶子节点(1, null, null) 当成 null
 * - 使用类似先入后出的栈结构
 * @param preorder 
 * @return true 
 * @return false 
 */
bool isValidSerialization2(string preorder);
int main(){
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << isValidSerialization1(preorder) << endl;
    cout << isValidSerialization2(preorder) << endl;
    return EXIT_SUCCESS;
}
bool isValidSerialization1(string preorder) {
    int i = 0, n = preorder.size(), diff = 1, f = 0;
    while (i < n){
        if (preorder[i] == ','){
            ++ i;
            continue;
        }
        else if (preorder[i] == '#'){
            ++ i;
            diff -= 1;
        }
        else {
            while (i < n && preorder[i ++] != ','){}
            diff -= 1;
            diff += 2;
        }
        if (diff < 0){
            return false;
        }
        else if (diff == 0){
            ++ f;
        }
    }
    return f == 1 && diff == 0;
}
bool isValidSerialization2(string preorder) {
    int i = 0, n = preorder.size(), m;
    // true 为非空 false 为空
    vector<bool> st;
    while (i < n){
        if (preorder[i] == ','){
            ++ i;
        }
        else if (preorder[i] == '#'){
            st.push_back(false);
            while ((m = st.size() - 1) > 1 && !st[m] && !st[m - 1] && st[m - 2]){
                st.erase(st.end() - 3, st.end());
                st.push_back(false);
            } 
            ++ i;
        }
        else {
            while (i < n && preorder[i ++] != ','){}
            st.push_back(true);
        }
    }
    return st.size() == 1 && !st[0];
}