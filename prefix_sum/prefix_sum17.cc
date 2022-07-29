#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1442. 形成两个异或相等数组的三元组数目
 * https://leetcode.cn/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
 * 
 * a ^ b = 0
 * @param arr 
 * @return int 
 */
int countTriplets(vector<int>& arr);
int main(){
    vector<int> arr = {2, 3, 1, 6, 7};
    cout << countTriplets(arr) << endl;
    return EXIT_SUCCESS;
}
int countTriplets(vector<int>& arr) {
    int n = arr.size(), res = 0;
    for (int i = 0; i < n - 1; ++ i){
        for (int k = i + 1, pre = arr[i]; k < n; ++ k){
            pre ^= arr[k];
            if (pre == 0){
                res += (k - i);
            }
        }
    }
    return res;
}