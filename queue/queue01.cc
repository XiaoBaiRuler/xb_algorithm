#include "..//common//common.h"
/**
 * @brief 622. 设计循环队列
 * https://leetcode.cn/problems/design-circular-queue/
 * 
 * 计数法
 */
class MyCircularQueue {
public:
    MyCircularQueue(int k) : n(k) {
        for (int i = 0; i < k; ++ i){
            res.push_back(0);
        }
    }
    
    bool enQueue(int value) {
        if (s == n){
            return false;
        }
        res[r % n] = value;
        ++ s;
        ++ r;
        return true;
    }
    
    bool deQueue() {
        if (s == 0){
            return false;
        }
        ++ l;
        -- s;
        return true;
    }
    
    int Front() {
        if (s == 0){
            return -1;
        }
        return res[l % n];
    }
    
    int Rear() {
        if (s == 0){
            return -1;
        }
        return res[(r - 1) % n];
    }
    
    bool isEmpty() {
        return s == 0;
    }
    
    bool isFull() {
        return s == n;
    }
private:
    int l = 0, r = 0, s = 0, n;
    vector<int> res;
};
int main(){
    MyCircularQueue mq(3);
    cout << mq.enQueue(1) << endl;
    cout << mq.enQueue(2) << endl;
    cout << mq.enQueue(3) << endl;
    cout << mq.enQueue(4) << endl;
    cout << mq.Rear() << endl;
    cout << mq.isFull() << endl;
    cout << mq.deQueue() << endl;
    cout << mq.enQueue(4) << endl;
    cout << mq.Rear() << endl;
    return EXIT_SUCCESS;
}