#include <algorithm>
#include <string>

using namespace std;

// 核心思路
// 找最后一个 word；即逆序遍历：1）找到第一个不为' ' 2）继续找到第一个' '
// 两个字符的距离就是最后一个 word 长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }

        auto begin = std::find_if(s.rbegin(), s.rend(), [](char ch) {return ch != ' ';});
        auto end = std::find(begin, s.rend(), ' ');
        return std::distance(begin, end);
    }
};
