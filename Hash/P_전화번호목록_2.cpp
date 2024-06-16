#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    auto answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    auto phoneHashSet = unordered_set<string>();
    for(auto phone : phone_book) {
		phoneHashSet.insert(phone);
	}
    
    for(auto phone : phone_book) {
        auto phoneSubStr = ""s;
        for(auto phoneChar : phone) {
            phoneSubStr += phoneChar;
            
            if (phone == phoneSubStr) {
                break;
            }
            
            auto isContain = phoneHashSet.find(phoneSubStr) != phoneHashSet.end();
            if (isContain) {
                return false;
            } 
        }
	}
    return true;
}

int main() {
	cout << "Hello " << solution({"123","456","789"});	
}

// 해시 주제의 문제라 해시로 다시 풀어보기
// 전화번호목록 1 풀이와 반대로 나를 잘게 쪼개어 내게 어떠한 접두사가 있는지를 검사

// 1. 리스트를 HashSet 으로 변환
// 2. 리스트 문자열 차례로 검사하면서 substring 맨 앞부터 접두사를 만들어 나가며 해시셋에 포함되어있는지를 검사
// ㄴ 포함되어 있다면 그 단어는 나의 접두사

// 2 * n * 20 (해시셋 변환 + 돌면서 접두사 만들기 최대 20자)

// ! 틀린 이유
// if (phone == phoneSubStr) 조건을 빼먹어서 틀렸었다. 
// 이 조건을 거르지 못하면 무조건 return false 할 수 밖에 없음.
	