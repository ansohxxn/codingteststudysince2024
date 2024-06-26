using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
	public int solution(int[] priorities, int location) {
		var answer = 0;

		// Key : priority
		// Value : 해당 우선순위의 location들 (=priorities 배열 내에서의 인덱스)
		var locationDict = new SortedDictionary<int, List<int>>(); // 우선순위 오름차순 정렬
		for(var index = 0; index < priorities.Length; ++index) {
			var priority = priorities[index];
			if (locationDict.ContainsKey(priority)) {
				locationDict[priority].Add(index);
            } else {
				locationDict.Add(priority, new List<int> { index });
			}
        }

		// 우선순위 큰 것부터 차례로 검사한다.
		var prevLastLocation = 0; // 이전에 검사한 Priority 의 location (=인덱스)
		foreach (var locationPair in locationDict.Reverse()) {	// 우선순위 내림차순 정렬
			var priority = locationPair.Key;
			var locationList = locationPair.Value;

			// 1) 큐 성격을 띄고 있기 때문에 이전에 검사한 Priority (= 즉 내림차순으로 정렬중일 때 이전 Priority) 보다 오른쪽인 location를 시작점으로 검사 돌기 시작해야 한다.
			var startIndex = locationList.FindIndex(loc => prevLastLocation <= loc);
			if (startIndex < 0) startIndex = 0; // 못 찾았을 때. (FindIndex가 -1를 리턴함. 오른쪽에 하나도 없고 다 왼쪽에 있는 경우다.)

			var count = 0;
			var maxCount = locationList.Count;
			var index = startIndex;	// locationList 의 인덱스. 즉.. priorities 배열의 인덱스(=location)들을 담아놓은 배열의 인덱스

			// 2) maxCount번 만큼 검사를 했다면 현재의 Priority 검사는 다 한 것.
			while(true) {
				++count;
				prevLastLocation = locationList[index];

				// 문제에서 주어진 목표 location 을 찾았다면...
				if (location == locationList[index]) {
					answer += count;
					return answer;
                }
					 
				if (count == maxCount) {
					break;
                }

				// 오른쪽으로 순회를 돌되 끝에 도달하면 맨 앞으로 옴
				index = (index == maxCount - 1) ? 0 : index + 1;
			}

			answer += count;
		}

		return answer;
	}
}

// https://school.programmers.co.kr/learn/courses/30/lessons/42587
// 스택, 큐 문제라 스택이나 큐로 다시 풀어보는게 좋을 것 같다.. 어떻게 푸는 것일지 고민 중
	// 다른 분들 풀이보니 문제에서 말하는 것 그대로 큐로 풀어도 시간 초과가 안나는 것 같다.
		// -> 시간 초과 날 것 같다고 생각했는데 왜 안 날까??? -> 길이가 최대가 100이라.. 뺑뺑 돌면서 세도 100^2 안넘을 것 같구.. max값 찾는데 O(100)이니까 안 넘을 것 같기도 하다. 

// 이 풀이의 아이디어 정리.. (너무 우아하지 못한 방법으로 푼 것 같다)
// 예시) 9 9 4 5 5 4 4 (-> location 차례로 0,1,2,3,4,5,6) location = 2는 몇번째로 실행될까
// 1.
	// locationDict 내용 (SortedDictionary 라서 키(=Priority) 별로 오름차순 정렬)
		// 9 : [0,1]
		// 5 : [3,4]
		// 4 : [2,5,6]
// 2.
	// 9(1) 9(2) 4(7) 5(3) 5(4) 4(5) 4(6) -> location = 2 였던 4는 7번째 순서로 실행됨.
	// 오른쪽 방향으로 차례로 순회하면서 뺑뺑 돌기 때문에 3개의 4 중에서 첫번째 4인 location = 5가 5번째로 실행되게 된다.
		// 4보다 큰 바로 앞전 우선순위인 5의 location이 4였기 때문에 location=2인 4가 아닌 location=5인 4부터 검사를 하게 되는 것이다.
	// 그렇기 때문에.. 우선순위 큰 것부터 내림차순 정렬해놓고 검사하면서
	// 뺑뺑 순회해서 돌면서 문제에서 주어진 목표 location과 일치한 location을 가진 우선순위를 만날 때까지 카운트를 세면 그게 바로 답

// ! ! ! 뺑뺑 순회 + 이전에 검사한 것의 오른쪽에서부터 검사 -> 우아하게 쓰는 다른 방법... (다른 분 풀이 참고 : C++ 좋아요 2번째로 많이 받은 풀이)
	// while(true) 안에서 for (int i = 0; i < priorities.size(); ++i) 돌면 그게 바로 뺑뺑 순회 + 차례로 오른쪽으로 계속 검사하는 방법..
	// 이 반복문 안에서 max 값을 찾고, max값을 찾았다면 그건 다음에 max값이 되지 못하도록 0 으로 할당하게끔 하는 것도 좋은 아이디어라 느꼈다. (굳이 리스트에서 삭제 연산할 필요 없음.)
