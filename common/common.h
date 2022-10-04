#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <random>
#include <algorithm>
#include <climits>
#include <set>
#include <stdlib.h>
#include <random>
#include "mystruct.h"
using namespace std;

template<typename T>
ostream& operator <<(ostream& os, vector<T>& res){
    for (auto &t : res){
        cout << t << " ";
    }
    return cout;
}