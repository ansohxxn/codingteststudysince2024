#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    auto prevNum = -1;
    for(auto num : arr) {
        auto isConsecutive = prevNum == num;
        if (isConsecutive) continue;
        
        prevNum = num;
        answer.push_back(num);
    }

    return answer;
}

// arr.erase(unique(arr.begin(), arr.end()),arr.end());
// https://sangwoo0727.github.io/c++/Cplus-unique/