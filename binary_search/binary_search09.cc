#include "../common/common.h"
int getBig(vector<int>& arr, int x);
/**
 * @brief 658. 找到 K 个最接近的元素
 * https://leetcode.cn/problems/find-k-closest-elements/
 * 
 * 1. 先找出刚好大于x的位置(二分法)
 * 2. 然后根据距离x最近左右扩展到k个
 * @param arr 
 * @param k 
 * @param x 
 * @return vector<int> 
 */
vector<int> findClosestElements(vector<int>& arr, int k, int x);
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> res = findClosestElements(arr, 4, -1);
    cout << res << endl;
    return EXIT_SUCCESS;
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    if (n <= k){
        return arr;
    }
    int r = getBig(arr, x), l = r - 1;
    for (; k != 0; -- k){
        if (l < 0) {
            r ++;
        } 
        else if (r >= n) {
            l --;
        } 
        else if (x - arr[l] <= arr[r] - x) {
            l --;
        } 
        else {
            r ++;
        }
    }
    return vector<int>(arr.begin() + l + 1, arr.begin() + r);
}
int getBig(vector<int>& arr, int x){
    if (arr[0] > x){
        return 0;
    }
    int l = 0, r = arr.size() - 1;
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        if (arr[mid] > x && arr[mid - 1] <= x){
            return mid;
        }
        else if (arr[mid] <= x){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return r;
}