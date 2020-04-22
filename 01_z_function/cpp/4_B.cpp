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

int get_shift(string s, string t) {
    int n = s.length();
    string new_s = t + "$" + s + s;
    vector<int> z = z_function(new_s);
    for(int i = n + 1; i < 3*n+1; i++) {
        if(z[i] == n) {
            return i-n-1;
        }
    }
    return -1;
}

int main() {
    int q = 1;
    cin >> q;
    string s = "";
    string t = "";
    for(int i = 0; i < q; i++) {
        cin >> s >> t;
        cout << get_shift(s, t) << endl;
    }
    return 0;
}