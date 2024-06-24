#include<string>

using namespace std;

bool solution(string s) {
    auto answer = true;

    auto openBracketCount = 0;
    auto closeBracketCount = 0;
    for (auto bracket : s) {
        if (bracket == '(') {
            ++openBracketCount;
        } else {
            ++closeBracketCount;
        }

        // 조건 1. 실시간으루,, 닫힌 괄호 개수가 열린 괄호 개수를 넘어선다면 그건 이 문자열 전체 자체가 올바르지 않은 괄호. (앞으로도 올바를 수 없음 닫힌 괄호가 먼저 나온거라)
        // 열린 괄호 개수가 닫힌 괄호 개수보다 많은건 상관 없음. 앞으로 닫힌 괄호들 나와서 다 닫힐 수도 있으므로 이건 문제되는 상황이 아님
        if (openBracketCount < closeBracketCount) {
            return false;
        }
    }
    
    // 조건 2. 입출력 예시 4번 "(()(" 처럼 열린 괄호 개수를 닫힌 괄호 개수가 넘어서는 경우는 쭉 없었지만.. 애초에 짝이 안맞으므로 올바르지 않은 괄호
    if (openBracketCount != closeBracketCount) return false;
    return answer;
}

// https://programmers.co.kr/learn/courses/30/lessons/12909

// 처음에 조건2를 생각하지 못해서 입출력 예 4번을 틀렸었음
// stack 으로도 풀어보기
