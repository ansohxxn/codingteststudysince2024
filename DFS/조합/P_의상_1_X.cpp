#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> BodyTypeClothesCountDict = unordered_map<string, int>();
vector<string> BodyTypeList = vector<string>(); // 조합은 같은 뿌리에서 갈라져나온 것 중에 중복으로 포함한게 있으면 안된다. 

void CombinateInternal(vector<bool>& checkedList, int& combiSum, int& pickCount, int count, int startIndex, int answer) {
	if (count == pickCount) {
		combiSum += answer;
		return;
	}
	
	for (auto i = startIndex; i < BodyTypeList.size(); ++i) {
		auto isAlreadyChecked = checkedList[i];
		if (isAlreadyChecked) continue;
		
		auto bodyType = BodyTypeList[i];
		auto answerUntilNow = answer * BodyTypeClothesCountDict[bodyType];
		
		checkedList[i] = true;  // bodyType 을 중복으로 체크하는 것 방지. 이 뒤에부터 뻗어 나가 뽑게 될땐 bodyType 을 제외시켜 주어야 하기 때문
		CombinateInternal(checkedList, combiSum, pickCount, ++count, i, answerUntilNow);
		checkedList[i] = false; // 현재 BodyTypeList[startIndex] 을 시작점으로 하는 모든 조합을 구했기 때문에 bodyType 다음 시작점부터는 재방문 가능하므로 체크 해제
	}
}

// 신체 부위 총 개수에서 pickCount 만큼 뽑는 조합에서 옷 조합 개수 합을 리턴하는 함수
int Combinate(int pickCount) {
	auto checkedList = vector<bool>(BodyTypeList.size());
	auto combiSum = 0;
	
	CombinateInternal(checkedList, combiSum, pickCount, 0, 0, 1);
	return combiSum;
}

int solution(vector<vector<string>> clothes) {
    
    for(auto clothesInfo : clothes) {
        auto bodyType = clothesInfo[1];
        if (BodyTypeClothesCountDict.find(bodyType) == BodyTypeClothesCountDict.end()) {
            BodyTypeList.push_back(bodyType);
        }
        ++BodyTypeClothesCountDict[bodyType];
    }
    
    auto answer = 0;
    for (auto pickCount = 1; pickCount <= BodyTypeClothesCountDict.size(); pickCount++) {
		answer += Combinate(pickCount);
	}

    return answer;
}

#include <iostream>
using namespace std;
int main() {
	cout << solution({{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}});
}

// 이 문제는 정답은 구할 수 있으나 시간 초과 걸리는 풀이다 ! !

// 테스트케이스 1번 틀림 (시간초과)
	// 찾아보니 원래 조합으로 풀면 1번 틀린다고 한다.. 조합으로 풀면 어쨋든 틀리는 듯
	// 조합을 코드로 구현하려니 좀 어려웠는데 1번 하나 틀려서 짜즁 ㅋ 알고보니 더 쉽고 빠른 풀이가 있었다.

// 옷을 걸치는 신체 부위를 종류로 해서 이 신체 부위에서 몇 곳을 선택할 것인가 -> 신체 조합 총 개수에서 n 개 뽑는 조합
// 신체 부위 n 개 뽑는 조합이 완성된다면 뽑힌 각각의 신체 부위의 옷 종류 개수를 곱해주면 된다.
	// ex) 신체부위 a - 옷 종류 4개 / b - 옷 종류 1개 / c - 옷 종류 2개 / d - 옷 종류 1개 
		// 라면 이 중 신체 부위 3개에 옷 걸친다면.. 4C3 가 되고 이 중 신체 부위 조합을 acd 로 뽑았다면 4 * 2 * 1 = 8개 이 신체 부위 조합으로 입을 수 있는 옷의 총 합은 8개가 되는 것이다.
		// 옷 종류 개수는 1개의 신체 부위 조합 내에서 순열로 구하고(곱하기), 각각의 조합마다 총 옷의 조합 개수를 더하면 된다.(더하기)

// DFS로 곱하며 깊게 들어가며 옷의 개수를 곱하다 보면, 끝 depth에 도달했을 때 (= pickCount 만큼 신체 부위 개수 뽑았을 때) 이 신체 부위 조합의 총 옷의 개수가 구해진다.
// 이 총 옷의 개수를 모두 더해야 하기 때문에 combiSum 에 이를 합산해 저장했다.