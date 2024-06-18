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