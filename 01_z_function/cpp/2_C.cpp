#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            if(s[i+j] != s[j]) {
                break;
            } else {
                z[i] += 1;
            }
        }
    }
    return z;
}

char get_letter(int i) {
    int S = 97;
    int B = 65;
    if(i < 26) {
        return char(S + i);
    } else {
        return char(B + i - 26);
    }
}

string construct_string(vector<int> z_func) {
    int n = z_func.size();
    int letter = 0;
    string s = "";
    int cursor = 1;
    for(int i = 0; i < n; i++) {
        int value = z_func[i];
        if(i == 0) {
            if(value > 0) {
                return "!";
            } else {
                s += get_letter(letter);
                letter += 1;
                continue;
            }
        }
        if(value > n - i) {
            return "!";
        }
        if(i == cursor) {
            if(value == 0) {
                s += get_letter(letter);
                letter += 1;
                cursor += 1;
                continue;                
            }
            if(value >= 1) {
                for(int j = 0; j < value; j++) {
                    s += s[j];
                }
                cursor = i + value;
            }
            continue;
        }
        if(cursor > i) {
            if(value <= cursor-i) {
                if(value == 0) {
                    if(s[i] == s[0]) {
                        return "!";
                    }
                }
                if(value > 0) {
                    for(int j = 0; j < value; j++) {
                        if(s[i+j] != s[j]) {
                            return "!";
                        }
                    }
                }
            }
            if(value > cursor-i) {
                for(int j = 0; j < cursor-i; j++) {
                    if(s[i+j] != s[j]) {
                        return "!";
                    }
                }
                for(int j = 0; j < i+value-cursor; j++) {
                    s += s[cursor-i+j];
                }
                cursor = i + value;
            }
        }
    }
    return s;
}

string check(vector<int> z_func) {
    string s_constructed = construct_string(z_func);
    if(s_constructed == "!") {
        return "!";
    }
    vector<int> z_constructed = z_function(s_constructed);
    if(z_constructed != z_func) {
        return "!";
    }
    return s_constructed;
}

int main() {
    int t = 1;
    int n = 1;
    int z = 0;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        vector<int> z_func = {};
        for(int j = 0; j < n; j++) {
            cin >> z;
            z_func.push_back(z);
        }
        cout << check(z_func) << endl;
    }
    return 0;
}