#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    auto bodyTypeClothesCountDict = map<string, int>();
    for(auto clothesInfo : clothes) {
        auto bodyType = clothesInfo[1];
        ++bodyTypeClothesCountDict[bodyType];
    }
    
    auto answer = 1;
    for(auto info : bodyTypeClothesCountDict) {
        auto clothesCount = info.second;
        answer *= (clothesCount + 1);
    }
    
    answer = answer - 1;
    return answer;
}

// 곱하기로 빠르게 풀 수 있다는 것을 알았다..
// (옷의 개수 + 1)를 신체 부위 종류 개수만큼 곱하고 1을 빼면 된다.
	// (옷의 개수 + 1) 에서의 1은 이 옷을 안 입는 경우
	// 총 합에서 1 빼는건 아무 옷도 안 입은 경우.. 이 경우는 없다고 했으니 1 빼주기