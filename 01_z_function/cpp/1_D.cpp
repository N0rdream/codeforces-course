#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> get_indices(string s, string t, int n, int m) {
    vector<int> indices = {};
    for(int i = 0; i < n-m+1; i++) {
        bool flag = true;
        for(int j = 0; j < m; j++) {
            if(s[i+j] != t[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            indices.push_back(i);
        }
    }
    return indices;
}

long long get_result(string s, string t) {
    int n = s.length();
    int m = t.length();
    long long result = 0;
    vector<int> indices = get_indices(s, t, n, m);
    int x = indices.size();
    if(x == 0) {
        result += n;
        result *= n + 1;
        result /= 2;
        return result;
    }
    int l = 0;
    int r = 0;
    for(int i = 0; i < x + 1; i++) {
        if(i == 0) {
            l = 0;
            r = indices[i] + m - 2;
        }
        if(i == x) {
            l = indices[i-1] + 1;
            r = n - 1;
        }
        if(i > 0 and i < x) {
            l = indices[i-1] + 1;
            r = indices[i] + m - 2;
        }
        result += (r-l+1)*(r-l+2)/2;
    }
    result -= x*(m-2)*(m-1)/2;
    return result;
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