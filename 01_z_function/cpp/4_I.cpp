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

vector<int> get_z_left(string t, string p, int n, int m) {
    string s = p + "$" + t;
    vector<int> z = z_function(s);
    vector<int> a = {};
    for(int i = 0; i < n-m+1; i++) {
        a.push_back(z[m+1+i]);
    }
    return a;
}

vector<int> get_z_right(string t, string p, int n, int m) {
    string t_r = get_reversed(t);
    string p_r = get_reversed(p);
    string s = p_r + "$" + t_r;
    vector<int> z = z_function(s);
    vector<int> a = {};
    for(int i = 0; i < n-m+1; i++) {
        a.push_back(z[n+1-i]);
    }
    return a;
}

vector<int> get_indices(string t, string p, int k) {
    int n = t.length();
    int m = p.length();
    vector<int> z1 = get_z_left(t, p, n, m);
    vector<int> z2 = get_z_right(t, p, n, m);
    vector<int> indices = {};
    for(int i = 0; i < n-m+1; i++) {
        if(z1[i] + z2[i] + k >= m) {
            indices.push_back(i+1);
        }
    }
    return indices;
}

int main() {
    string t = "";
    string p = "";
    int k = 0;
    cin >> t >> p >> k;
    vector<int> indices = get_indices(t, p, k);
    int n = indices.size();
    cout << n << endl;
    for(int i = 0; i < n; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
    return 0;
}