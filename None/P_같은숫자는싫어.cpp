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
// unique 함수 쓰면 쉽게 풀 수 있다고 한다..
// unique 가 중복 원소들 제거해주는 함수.
// 근데 erase 가 붙는 이유는 아래 링크 참고 
// https://sangwoo0727.github.io/c++/Cplus-unique/