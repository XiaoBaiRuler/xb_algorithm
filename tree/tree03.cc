#include "..//common//common.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @brief 449. 序列化和反序列化二叉搜索树
 * https://leetcode.cn/problems/serialize-and-deserialize-bst/
 * 
 * - 序列化: 层序遍历 - 以空格为间隔(NULL 为 -1)
 * - 反序列化: BFS - 借助队列解析
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if (root == NULL){
            return "-1";
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* now = q.front();
            q.pop();
            if (now != NULL){
                res += to_string(now -> val) + " ";
                q.push(now -> left);
                q.push(now -> right);
            }
            else{
                res += "-1 ";
            }
        }
        return res.substr(0, res.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string delimiter = " ";
        size_t pos = data.find(delimiter);
        string token = data.substr(0, pos);
        int now = stoi(token);
        if (now == -1){
            return NULL;
        }
        TreeNode* res = new TreeNode(now);
        data.erase(0, pos + delimiter.length());
        queue<TreeNode *> tmp;
        tmp.push(res);
        vector<int> da;
        while ((pos = data.find(delimiter)) != string::npos) {
            token = data.substr(0, pos);
            now = stoi(token);
            da.push_back(now);
            data.erase(0, pos + delimiter.length());
        }
        now = stoi(data);
        da.push_back(now);
        int i = 0;
        while (!tmp.empty()){
            TreeNode* t = tmp.front();
            tmp.pop();
            if (da[i] != -1){
                t -> left = new TreeNode(da[i]);
                tmp.push(t -> left);
            }
            if (da[i + 1] != -1){
                t -> right = new TreeNode(da[i + 1]);
                tmp.push(t -> right);
            }
            i += 2;
        }
        return res;
    }

};

int main(){
    Codec c;
    string s = "1 2 3 -1 -1 -1 -1";

    cout << c.serialize(c.deserialize(s)) << endl;
    return EXIT_SUCCESS;
}