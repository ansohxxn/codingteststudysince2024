#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool CompareGenre(const pair<string, int>& a, const pair<string, int>& b) {
	auto a_playCount = a.second;
	auto b_playCOunt = b.second;
	return a_playCount > b_playCOunt;   // 내림차순
}

bool ComparePlay(const pair<int, int>& a, const pair<int, int>& b) {
	auto a_playCount = a.second;
	auto b_playCount = b.second;
	if (a_playCount != b_playCount) {
		return a_playCount > b_playCount;   // 내림차순
	}

	auto a_id = a.first;
	auto b_id = b.first;
	return a_id < b_id; // 오름차순
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    auto genrePlayCountDict = map<string, int>();   // 장르 별로 플레이 횟수 합산해서 저장
    auto genrePlayListDict = map<string, vector<pair<int, int>>>(); // 장르 별로 속해 있는 플레이 리스트 저장 (고유 번호와 카운트 pair로 함께 저장)
    
    for (auto id = 0; id < genres.size(); id++) {
		auto genreName = genres[id];
		auto playCount = plays[id];
		genrePlayCountDict[genreName] += playCount;
		genrePlayListDict[genreName].push_back(make_pair(id, playCount)); // 런타임 에러 나나?
	}
	
	// 1. 플레이 횟수에 의한 장르 정렬
	auto genreList = vector<pair<string, int>>(genrePlayCountDict.begin(), genrePlayCountDict.end());
	sort(genreList.begin(), genreList.end(), CompareGenre);
	
	// 2. 장르 내에서 가장 많이 재생된 노래 2곡씩 수록 (1곡밖에 없다면 1곡)
	for(auto genre : genreList) {
		auto genreName = genre.first;
		auto playList = genrePlayListDict[genreName];
		sort(playList.begin(), playList.end(), ComparePlay);
		
		answer.push_back(playList[0].first);
		if (playList.size() >= 2) answer.push_back(playList[1].first);
	}
        
    return answer;
}

// C++ 알게 된 점 정리 (정렬 함수, make_pair, 런타임 에러 안났음;)

// C# Linq 써서 풀어보는건 어떨지