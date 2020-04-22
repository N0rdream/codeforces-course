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

vector<int> get_preffs_matches(string s) {
    int x_max = 0;
    int n = s.length();

    vector<int> result(n, 1);
    vector<int> counter(n, 0);
    vector<int> z = z_function(s);

    for(int i = 0; i < n; i++) {
        if(z[i] > 0) {
            if(z[i] > x_max) {
                x_max = z[i];
            }
            counter[z[i]]++;
        }
    }
    for(int i = x_max; i > 0; i--) {
        result[i-1] = result[i] + counter[i];
    }
    return result;
}

int main() {
    int q = 1;
    cin >> q;
    string s = "";
    for(int i = 0; i < q; i++) {
        cin >> s;
        vector<int> matches = get_preffs_matches(s);
        int n = matches.size();
        for(int j = 0; j < n; j++) {
            cout << matches[j] << " ";
        }
        cout << endl;
    }
    return 0;
}