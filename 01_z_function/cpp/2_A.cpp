#include <string>
#include <iostream>

using namespace std;


string get_result(string s) {
    string z = "0 ";
    int n = s.length();
    for(int i = 1; i < n; i++) {
        string suff = s.substr(i, n-i);
        int m = 0;
        for(int j = 0; j < n-i; j++) {
            if(suff[j] != s[j]) {
                break;
            } else {
                m++;
            }
        }
        z += to_string(m) + " ";
    }
    return z;
}

int main() {
    string s = "";
    cin >> s;
    cout << get_result(s) << endl;
    return 0;
}