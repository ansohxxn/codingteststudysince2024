#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> workingDaysToNeedQueue;
    auto workCount = progresses.size();

    // 1. 큐에 필요한 작업 시간들 차례로 넣는다.
    for (auto i = 0; i < workCount; i++) {
        auto remainProgress = 100 - progresses[i];
        auto workingDaysToNeed = remainProgress / speeds[i];
        if (remainProgress % speeds[i] > 0) workingDaysToNeed++;

        workingDaysToNeedQueue.push(workingDaysToNeed);
    }

    // 2. 큐에서 차례로 빼면서 검사
    auto releaseCount = 0;
    auto releaseDay = workingDaysToNeedQueue.front();
    while (!workingDaysToNeedQueue.empty()) {
        auto workingDaysToNeed = workingDaysToNeedQueue.front();
        workingDaysToNeedQueue.pop();

        // 가장 최근에 업뎃 된 (= 이전에 업뎃된 이라고 표현하면 좀 그런가) 
        // releaseDay 에 몇개가 출시될 수 있는지 알 수 있는 순간.
        // releaseDay >= workingDaysToNeed 일 때만 releaseDay 에 포함해서 출시가 가능한 작업인 것이다.
        if (releaseDay < workingDaysToNeed) {
            answer.push_back(releaseCount);

            releaseCount = 0;
            releaseDay = workingDaysToNeed;
        }

        ++releaseCount;
    }

    // 필연적으로 제일 마지막으로 업데이트 되었던 releaseDay 에 몇개나 출시할 수 있는지는 answer 에 삽입 되지 못한다.
    // releaseDay 를 초기화한 시점에는 그 뒤에 더 적은 작업 시간이 걸려서 최신의 releaseDay 에 출시될 때까지 기다려야하는 원소들을 알 수가 없기 떄문이다.
    // 그래서 모든 큐를 다 비운 이후에 마지막 releaseDay 에 출시할 수 있는 개수를 answer에 푸시해준다.
    answer.push_back(releaseCount);
    return answer;
}

// https://school0.programmers.co.kr/learn/courses/30/lessons/42586

// 예시) 입출력 예시 1번은 큐에 (7, 3, 9) 가 들어가게 됨
// releaseDay = 7
// 7 pop ----> 7 >= 7 이므로 7일에 출시가 가능. releaseCount = 1
// 3 pop ----> 7 >= 3 이므로 7일에 출시가 가능. releaseCount = 2
// 9 pop ----> 7 < 9 이므로 7일에 출시가 불가능. 
    // 7일에 출시 가능한건 뒤에 더 이상 없음 기존의 releaseCount = 2를 푸시하고 초기화함. 이제 9일에 배포 가능한지를 기준으로 봐야 함. releaseDay = 9
    // 9 >= 9 이므로 9일에 출시가 가능. releaseCount = 1
// 큐 원소들 검사 완료
// 가장 최근에 업뎃한 releaseCount 는 9일에 출시 가능한 개수가 되는 것이므로 answer 에 푸시해준다.

