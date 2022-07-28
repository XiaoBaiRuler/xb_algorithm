#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1352. 最后 K 个数的乘积
 * https://leetcode.cn/problems/product-of-the-last-k-numbers/
 */
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        res.push_back(1);
    }
    
    void add(int num) {
        if (num == 0){
            zero = res.size();
            res.push_back(0);
            now = 1;
            return;
        }
        now *= num;
        res.push_back(now);
    }
    
    int getProduct(int k) {
        int r = res.size() - 1;
        int l = res.size() - k - 1;
        if (zero > l){
            return 0;
        }
        if (res[l] == 0){
            return res[r];
        }
        return res[r] / res[l];
    }
private:
    int now = 1, zero = -1;
    vector<int> res; 
};
int main(){
    ProductOfNumbers pn;
    pn.add(1);
    pn.add(0);
    pn.add(2);
    cout << pn.getProduct(1) << endl;
    cout << pn.getProduct(2) << endl;
    return EXIT_SUCCESS;
}