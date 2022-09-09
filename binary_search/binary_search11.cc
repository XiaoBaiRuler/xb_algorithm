#include "../common/common.h"
class ArrayReader {
public:
    int get(int index){
        return index < this -> vec.size() ? this -> vec[index] : INT_MAX;
    }
private:
    vector<int> vec = {-1,0,3,5,9,12};
};
/**
 * @brief 702. 搜索长度未知的有序数组
 * https://leetcode.cn/problems/search-in-a-sorted-array-of-unknown-size/
 * 
 * 题目限定最大为1e4, 如果不确定，可以通过*10不断确定最大范围
 * 
 * @param reader 
 * @param target 
 * @return int 
 */
int search(ArrayReader& reader, int target);
int main(){
    ArrayReader ar;
    cout << search(ar, 9) << endl;
    return EXIT_SUCCESS;
}

int search(ArrayReader& reader, int target) {
    int l = 0, r = 10000;
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        int tmp = reader.get(mid);
        if (tmp == target){
            return mid;
        }
        else if (tmp > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}