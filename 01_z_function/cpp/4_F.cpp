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

string get_merged_string(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    string x = s1 + "$" + s2;
    vector<int> z = z_function(x);
    for(int i = 0; i < n2; i++) {
        if(z[n1+1+i] == n1) {
            return s2;
        }
        if(z[n1+1+i] < n1) {
            if(z[n1+1+i] + i == n2) {
                return s2.substr(0, n2-z[n1+1+i]) + s1;
            }
        }
    }
    return s1 + s2;
}

string get_result(string s, string t) {
    string m1 = get_merged_string(s, t);
    string m2 = get_merged_string(t, s);
    
    if(m1.length() > m2.length()) {
        return m2;
    } else {
        return m1;
    }
}

int main() {
    int q = 1;
    string s = "";
    string t = "";
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> s >> t;
        cout << get_result(s, t) << endl;
    }
    return 0;
}