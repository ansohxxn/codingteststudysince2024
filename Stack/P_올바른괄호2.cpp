#include <string>
#include <stack>

using namespace std;

bool solution(string s) {
    auto bracketStack = stack<char>();
    for (auto bracket : s) {
        if (bracket == '(') {
            bracketStack.push(bracket);
        } else if (bracketStack.empty()) {  // 닫힌 괄호면.. 푸시된 열린 괄호를 뺄 수 있어야하는데 그게 안된다는건 짝이 안 맞다는 것!
            return false;
        } else {
            bracketStack.pop(); // 짝꿍 닫힐 괄호가 나타났으니 열린괄호 빼주기.
        }
    }

    return bracketStack.empty(); // 아무것도 남아있지 않으면 모든 열린괄호가 짝을 만나서 나갔다는 것.
}

// https://school.programmers.co.kr/learn/courses/30/lessons/12909