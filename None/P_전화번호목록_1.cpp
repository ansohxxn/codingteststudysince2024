#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    auto answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    auto prefix = ""s;
    for(auto phone : phone_book) {
        auto isContain = prefix != "" && phone.substr(0, prefix.size()) == prefix;
        if (isContain) {
            return false;
        }
        prefix = phone;
	}
    return true;
}

int main() {
	cout << solution({"119", "97674223", "1195524421"});	
}

// 서로서로 전부 검사 하는 O(n^2)를 피하려면 
// 1. 정렬을 먼저 함 (문자열 오름차순)
// 2. 앞부터 접두사 캐싱해두고 그 뒤에 검사 
// ㄴ 정렬을 해놨기 때문에, 포함되지 않으면 사실상 뒤에도 포함될 가능성 제로
// 그래서 O(n)에 가깝게 풀 수 있음 (+ 최대 20자니까 정확하게는 n * 20이 될 듯)

// ! 틀린 이유 (테스트케이스 13)
// 처음에 string.find 로 포함하는지를 검사 했던게 틀린 이유. '접두사'이기 때문에 처음부터 포함이 되어야 함.