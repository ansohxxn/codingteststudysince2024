# 코테 공부하며 알게된 C++ 문법

### auto string 인식하기

`auto phoneSubStr = ""s;`처럼 문자열 따옴표 뒤에 `s`를 붙이면 auto가 해당 문자열을 string으로 인식한다.

### max, min

`algorithm` 헤더에 있음

### 정렬 기준을 바꾸고 싶을 땐 정렬 함수 만들어 sort에 넘겨주기

```cpp
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
```
```cpp
sort(playList.begin(), playList.end(), ComparePlay);
```

### make_pair

pair 쉽게 만드는 api 

```cpp
auto genrePlayCountDict = map<string, int>();
genrePlayListDict[genreName].push_back(make_pair(id, playCount));
```

### 리스트가 비어있어도 그냥 바로 삽입할 수 있다.

```cpp
auto genrePlayListDict = map<string, vector<pair<int, int>>>();
genrePlayListDict[genreName].push_back(make_pair(id, playCount));
```
C# 관전에선 삽입할 때 genrePlayListDict[genreName] 의 pair 리스트가 null 이면 런타임에러가 나므로 new 생성해주고 삽입해야하는데 C++ 은 런타임 에러가 안남

### unique 함수

[참고한 블로그](https://sangwoo0727.github.io/c++/Cplus-unique/)

arr 이 만약에 1,2,2,3,3,3,4,5 라면..

```cpp
unique(arr.begin(), arr.end()
```

이 결과는 1,2,3,4,5,<u>3,4,5</u> 이다.
arr 에서 중복 제거한 결과를 앞에 두고 나머지 `arr.size() - 중복 제거 완료했을 때의 개수` 사이즈 만큼 빈 곳엔 원래 arr 원소들이 나오게 된다.

```cpp
arr.erase(unique(arr.begin(), arr.end()),arr.end());
```

그래서 뒤에 것도 없애고 딱 중복 제거한 것만 없애고 싶으면 위와 같이 쓴다. unique 함수의 리턴 iterator가 중복 제거를 완료한 곳인 것 같다. 즉 1,2,3,4,5,<u>3</u>,4,5 요기! 그래서 자연스럽게 3,4,5 가 제거되는 것 같다.
