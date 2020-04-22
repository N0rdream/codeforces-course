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

int get_result(string s) {
    int n = s.length();
    string s_inf = s + s;
    vector<int> z = z_function(s_inf);
    int before = 0;
    for(int i = 1; i < n; i++) {
        if(z[i] == 0 and s[0] > s_inf[i]) {
            before++;
        }
        if(z[i] > 0 and z[i] < n and s[z[i]] > s_inf[z[i]+i]) {
            before++;
        }
    }
    return before + 1;
}

int main() {
    string s = "";
    cin >> s;
    int ind = get_result(s);
    cout << ind << endl;
    return 0;
}