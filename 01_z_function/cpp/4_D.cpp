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

string get_reversed(string s) {
    int n = s.length();
    string r = "";
    for(int i = n-1; i >= 0; i--) {
        r += s[i];
    }
    return r;
}

int get_max_palindrome_preff_len(string s) {
    string x = s + "$" + get_reversed(s);
    vector<int> z = z_function(x);
    int n = 2 * s.length() + 1;
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(z[i] + i == n and z[i] > m) {
            m = z[i];
        }
    }
    return m;
}

int main() {
    string s = "";
    cin >> s;
    cout << get_max_palindrome_preff_len(s) << endl;
    return 0;
}