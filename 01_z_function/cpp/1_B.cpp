#include <string>
#include <iostream>

using namespace std;

string* get_suffs(string s) {
    int n = s.length();
    string* suffs = new string[n];
    for(int i = 0; i < n; i++) {
        suffs[i] = s.substr(i, n-i);
    }
    return suffs;
}

string* get_preffs(string s) {
    int n = s.length();
    string* preffs = new string[n];
    for(int i = 0; i < n; i++) {
        preffs[i] = s.substr(0, i+1);
    }
    return preffs;
}

string* get_subs(string s) {
    int n = s.length();
    string* subs = new string[n*(n+1)/2];
    for(int i = 0; i < n; i++) {
        for(int l = 1; l < n-i+1; l++) {
            int j = n*(i+1) - i*(i+1)/2 - 1 - n + i + l;
            subs[j] = s.substr(i, l);
        }
    }
    return subs;
}

int get_result(string s) {

    int n = s.length();

    string* suffs = get_suffs(s);
    string* preffs = get_preffs(s);
    string* subs = get_subs(s);

    bool flag = false;
    int result = 0;

    for(int i = 0; i < n*(n+1)/2; i++) {
        for(int j = 0; j < n; j++) {
            if(subs[i] == suffs[j]) {
                flag = true;
                break;
            }
        }
        for(int j = 0; j < n; j++) {
            if(subs[i] == preffs[j]) {
                flag = !flag;
                break;
            }
        }
        if(flag) {
            result += 1;
        }
        flag = false;
    }
    return result;
}

int main() {
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> s;
        int r = get_result(s);
        cout << r << endl;
    }

    return 0;
}