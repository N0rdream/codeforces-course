#include <iostream>
#include <cmath>

using namespace std;

int get_value(int k, int j) {
    if(j == 0) {
        return 0;
    }
    for(int i = k-1; i >= 0; i--) {
        int n = pow(2, i);
        if(j < n) {
            continue;
        }
        if(j % n == 0) {
            return n-1;
        }
    }
}

int main() {
    int t = 1;
    int k = 1;
    int j = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> k >> j;
        cout << get_value(k, j) << endl;
    }
    return 0;
}