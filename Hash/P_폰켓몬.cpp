#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums){
    auto hashSet = unordered_set<int>();
    
    for(auto num : nums) {
		hashSet.insert(num);
	}
    
    auto typeCount = hashSet.size();
    return min(typeCount, nums.size() / 2);
}

// https://school.programmers.co.kr/learn/courses/30/lessons/1845
// 해시의 카운트로 종류 개수 알아내기
// min 써서 nums.size() / 2 를 못 넘게 하기