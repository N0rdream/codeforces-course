#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> z_function(vector<int> s) {
    int n = s.size();
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

// vector<int> get_reversed_array(vector<int> v) {
//     int n = v.size();
//     vector<int> r(n);
//     for(int i = n-1; i >= 0; i--) {
//         r.push_back(v[i]);
//     }
//     return r;
// }

vector<int> get_cubes_num(vector<int> v) {
    vector<int> cubes = {};
    int n = v.size();
    vector<int> x = v;
    x.push_back(-1);
    for(int i = n-1; i >= 0; i--) {
        x.push_back(v[i]);
    }
    vector<int> z = z_function(x);
    for(int i = 0; i < n; i++) {
        if(z[n+1+i] + i == n and z[n+1+i] > 1 and z[n+1+i] % 2 == 0) {
            cubes.push_back(n - z[n+1+i]/2);
        }
    }
    cubes.push_back(n);
    return cubes;
}

int main() {
    int n = 1;
    int m = 1;
    int c = 1;

    cin >> n >> m;
    vector<int> v = {};
    
    for(int i = 0; i < n; i++) {
        cin >> c;
        v.push_back(c);
    }
    vector<int> cubes = get_cubes_num(v);
    int l = cubes.size();
    for(int i = 0; i < l; i++) {
        cout << cubes[i] << " ";
    }
    cout << endl;
    return 0;
}