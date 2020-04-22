#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0;
    int r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) {
            if(z[i-l] < r-i+1) {
                z[i] = z[i-l];
            } else {
                z[i] = r-i+1;
                while((z[i]+i < n) and (s[z[i]] == s[z[i]+i])) {
                    z[i]++;
                }
            }
        } else {
            while((z[i]+i < n) and (s[z[i]] == s[z[i]+i])) {
                z[i]++;
            }
        }
        if(r < i+z[i]-1) {
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

vector<int> get_k_plus_1_matches(string x, int n) {
    vector<int> z = z_function(x);
    vector<int> matches = {};
    for(int i = n+1; i < 2*n+1; i++) {
        if(z[i]+i-n-1 == n) {
            matches.push_back(z[i]);
        }
    }
    return matches;
}

int get_result(string s, string t) {
    int n = s.length();
    int m = t.length();
    if(n != m) {
        return -1;
    }
    if(n == 1) {
        if(s.compare(t) != 0) {
            return -1;
        } else {
            return 0;
        }
    }
    string x = t + "$" + s;
    vector<int> matches = get_k_plus_1_matches(x, n);
    int p = matches.size();
    for(int i = 0; i < p; i++) {
        bool flag = true;
        if((matches[i] == n) and (p == 1)) {
            return 0;
        }
        for(int j = 0; j < n-matches[i]; j++) {
            if(t[matches[i]+j] != s[n-matches[i]-j-1]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            return n-matches[i];
        }
    }
    return -1;
}

int main() {
    string s = "";
    string t = "";
    cin >> s >> t;
    int result = get_result(s, t);
    if(result != -1) {
        cout << "Yes" << endl << result << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}