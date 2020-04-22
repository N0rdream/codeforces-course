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

int get_max(vector<int> v) {
    int n = v.size();
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] > m) {
            m = v[i];
        }
    }
    return m;
}

long long get_subs_sum_lengths(string s) {
    long long result = 0;
    int n = s.length();
    string suff = "";
    for(int i = n-1; i >= 0; i--) {
        suff = s[i] + suff;
        vector<int> z = z_function(suff);
        int m = get_max(z);
        result += (n-i)*(n-i+1)/2 - m*(m+1)/2;
    }
    return result;
}

int main() {
    string s = "";
    cin >> s;
    long long result = get_subs_sum_lengths(s);
    cout << result << endl;
    return 0;
}