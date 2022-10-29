#include "../common/common.h"
/**
 * @brief 1257. 最小公共区域
 * https://leetcode.cn/problems/smallest-common-region/
 */
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        for (auto& re : regions){
            int n = re.size();
            for (int i = 1; i < n; ++ i){
                pre[re[i]] = re[0];
            }
        }
        unordered_set<string> pv;
        while (pre.find(region1) != pre.end()){
            pv.insert(region1);
            region1 = pre[region1];
        }
        pv.insert(region1);
        while (!pv.count(region2)){
            region2 = pre[region2];
        }
        return region2;
    }
private:
    unordered_map<string, string> pre;
};
int main(){
    vector<vector<string>> regions = {
        {"Earth","North America","South America"},
        {"North America","United States","Canada"},
        {"United States","New York","Boston"},
        {"Canada","Ontario","Quebec"},
        {"South America","Brazil"}
    };
    string region1 = "Quebec", region2 = "New York";
    cout << Solution().findSmallestRegion(regions, region1, region2);
    return EXIT_SUCCESS;
}