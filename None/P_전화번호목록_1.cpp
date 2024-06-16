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
        auto isContain = prefix != "" && phone.find(prefix) != string::npos;
        if (isContain) {
            return true;
        }
        prefix = phone;
	}
    return false;
}

int main() {
	cout << solution({"119", "97674223", "1195524421"});	
}
