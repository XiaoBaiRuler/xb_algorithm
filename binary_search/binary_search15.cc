#include "../common/common.h"
/**
 * @brief 349. 两个数组的交集
 * https://leetcode.cn/problems/intersection-of-two-arrays/
 * 
 * 
 * 时间复杂度: n * log(m) + m * log(m)
 * 空间复杂度: 取决于重复的字段(hash)
 * 
 * 如果仅仅使用hash，那么可以时间复杂度O(m + n)
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), r;
        m = nums2.size() - 1;
        // n * log(m) + m * log(m)
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        for (int t : nums1){
            if (!set.count(t) && (r = findT(nums2, t)) != -1){
                res.push_back(r);
                set.insert(r);
            }
        }
        return res;
    }
    int findT(vector<int>& nums, int t){
        int l = 0, r = m;
        while (l <= r){
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == t){
                return nums[mid];
            }
            else if (nums[mid] > t){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
private:
    int m;
    unordered_set<int> set;

};
int main(){
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution s;
    vector<int> res = s.intersection(nums1, nums2) ;
    cout << res << endl;
    return EXIT_SUCCESS;
}