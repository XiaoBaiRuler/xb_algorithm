#include "../common/common.h"
class Trie{
public:
    Trie *z = nullptr;
    Trie *o = nullptr;
};
/**
 * @brief 421. 数组中两个数的最大异或值
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/
 * 
 * 满长度31的前缀树
 * 
 */
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        for (int n : nums){
            Trie *now = root;
            for (int k = 30; k > -1; -- k){
                if ((1 << k) & n){
                    if (now -> o == nullptr){
                        now -> o = new Trie();
                    }
                    now = now -> o;
                }
                else{
                    if (now -> z == nullptr){
                        now -> z = new Trie();
                    }
                    now = now -> z;
                }
            }
        }
        int res = 0;
        for (int n : nums){
            Trie *now = root;
            int ans = 0;
            for (int k = 30; k > -1; -- k){
                // 1
                if ((1 << k) & n){
                    if (now -> z != nullptr){
                        ans = (ans << 1) + 1;
                        now = now -> z;
                    }
                    else{
                        ans <<= 1;
                        now = now -> o;
                    }
                }
                else{
                    if (now -> o != nullptr){
                        ans = (ans << 1) + 1;
                        now = now -> o;
                    }
                    else{
                        ans <<= 1;
                        now = now -> z;
                    }
                }
            }
            res = max(res, ans);
        }
        return res;
    }
};
int main(){
    vector<int> nums = {14,70,53,83,49,91,36,80,92,51,66,70};
    cout << Solution().findMaximumXOR(nums) << endl;
    return EXIT_SUCCESS;
}