#include "../common/common.h"
class Trie{
public:
    bool flag = false;
    unordered_set<int> res;
    array<Trie*, 27> next = {nullptr};
};
/**
 * @brief 642. 设计搜索自动补全系统
 * https://leetcode.cn/problems/design-search-autocomplete-system/
 * 
 * 前缀树 + hash
 */
class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) : set(sentences), tim(times), 
        n(sentences.size()), root(new Trie()){
        for (int i = 0; i < n; ++ i){
            map[sentences[i]] = i;
            trieAddString(sentences[i], i);
        }
        run = root;
    }
    void trieAddString(string &s, int in){
        int all = s.size();
        Trie *now = root;
        for (int i = 0; i < all; ++ i){
            int j = s[i] == ' ' ? 26 : s[i] - 'a';
            if (now -> next[j] == nullptr){
                now -> next[j] = new Trie();
            }
            now = now -> next[j];
            now -> res.insert(in);
        }
        now -> flag = true;
    }

    vector<string> input(char c) {
        if (c == '#'){
            if (map.find(tmpStr) != map.end()){
                int j = map[tmpStr];
                tim[j] ++;
            }
            else{
                map[tmpStr] = n;
                tim.push_back(1);
                set.push_back(tmpStr);
                trieAddString(tmpStr, n);
                ++ n;
            }
            run = root;
            tmpStr = "";
            wrongFlag = false;
            return vector<string>();
        }
        tmpStr.push_back(c);
        if (wrongFlag){
            return vector<string>();
        }
        int j = c == ' ' ? 26 : c - 'a';
        if (run -> next[j] == nullptr){
            wrongFlag = true;
            return vector<string>();
        }
        run = run -> next[j];
        return getResult();
    }
    vector<string> getResult(){
        int f = -1, s = -1, t = -1;
        int fi = 0, si = 0, ti = 0;
        for (int i : run -> res){
            if (tim[i] > t || (tim[i] == t && set[i] < set[ti])){
                t = tim[i];
                ti = i;
            }
        }
        for (int i : run -> res){
            if (ti == i){
                continue;
            }
            if (tim[i] > s || (tim[i] == s && set[i] < set[si])){
                s = tim[i];
                si = i;
            }
        }
        for (int i : run -> res){
            if (ti == i || si == i){
                continue;
            }
            if (tim[i] > f || (tim[i] == f && set[i] < set[fi])){
                f = tim[i];
                fi = i;
            }
        }
        vector<string> res;
        if (t != -1){
            res.push_back(set[ti]);
        }
        if (s != -1){
            res.push_back(set[si]);
        }
        if (f != -1){
            res.push_back(set[fi]);
        }
        return res;
    }
private:
    vector<string> set;
    vector<int> tim;
    unordered_map<string, int> map;
    int n;
    Trie *root, *run;
    string tmpStr;
    bool wrongFlag = false;
};
int main(){
    vector<string> sentence = {"i love you", "island", "iroman", "i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem as(sentence, times);
    vector<string> res;
    res = as.input('i');
    cout << res << endl;
    res = as.input(' ');
    cout << res << endl;
    res = as.input('a');
    cout << res << endl;
    res = as.input('#');
    cout << res << endl;
    return EXIT_SUCCESS;
}
