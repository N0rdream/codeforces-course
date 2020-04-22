#include <string>
#include <iostream>

using namespace std;

bool is_palindrome(string s) {
    int n = s.length();
    for(int i = 0; i < n/2; i++) {
        if(s[i] != s[n-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    int t;
    cin >> t;
    int result;
    for(int i = 0; i < t; i++) {
        cin >> s;
        int n = s.length();
        for(int j = 1; j < n + 1; j++) {
            if(is_palindrome(s.substr(0, j))) {
                result = j;
            }
        }
        cout << result << endl;
    }
    return 0;
}
