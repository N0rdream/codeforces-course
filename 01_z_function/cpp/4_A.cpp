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

string get_min_period(string s) {
    int n = s.length();
    vector<int> z = z_function(s);
    for(int i = 0; i < n; i++) {
        if(i+z[i] == n) {
            return s.substr(0, n-z[i]);
        }
    }
    return s;
}

int main() {
    int t = 1;
    cin >> t;
    string s = "";
    for(int i = 0; i < t; i++) {
        cin >> s;
        cout << get_min_period(s) << endl;
    }
    return 0;
}
