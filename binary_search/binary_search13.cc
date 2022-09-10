#include "../common/common.h"
/**
 * @brief 744. 寻找比目标字母大的最小字母
 * https://leetcode.cn/problems/find-smallest-letter-greater-than-target/
 * 
 * 注意超出最大值，取的是最小值
 * 
 * @param letters 
 * @param target 
 * @return char 
 */
char nextGreatestLetter(vector<char>& letters, char target);
int main(){
    vector<char> letters = {'c', 'f', 'j'};
    cout << nextGreatestLetter(letters, 'f') << endl;
    return EXIT_SUCCESS;
}
char nextGreatestLetter(vector<char>& letters, char target) {
    int n = letters.size() - 1;
    if (letters[n] <= target || letters[0] > target){
        return letters[0];
    }
    int l = 0, r = n;
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        if (letters[mid] > target && letters[mid - 1] <= target){
            return letters[mid];
        }
        else if (letters[mid] <= target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return letters[r];
}