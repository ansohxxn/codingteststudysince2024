#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    auto completionDict = unordered_map<string, int>(); // 완주한 사람들의 이름 Key 동명이인 카운트 Value
    for(auto runner : completion) {
		++completionDict[runner];
	}
	
	for(auto runner : participant) {
		// 1. 완주한 이름 목록에 아예 없음
		auto hasName = completionDict.find(runner) != completionDict.end();
		if (!hasName) {
			return runner;
		}
		
		// 2. 완주한 이름 목록에 있긴 한데 개수가 0 이면 완주한 사람의 동일한 이름 숫자만큼 체크를 다 했다는 뜻. 완주 리스트 내 동명이인들 체크 완료함
		auto checkSameNameCompletely = completionDict[runner] == 0;
		if (checkSameNameCompletely) {
			return runner;
		}
		
		--completionDict[runner];
	}
    
    return "";  // 여기 걸릴 일이 있나 ?.?
}

#include <iostream>
int main() {
	cout << solution({"marina"}, {});
}

// https://school.programmers.co.kr/learn/courses/30/lessons/42576
// 처음에 completion 이랑 participant 랑 반대로 해서 틀림 