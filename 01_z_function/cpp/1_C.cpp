#include <string>
#include <iostream>

using namespace std;

int get_result(string t, string p) {

    int n = t.length();
    int m = p.length();
    int count = 0;
    string indices = "";

    if(m <= n) {
        for(int i = 0; i < n-m+1; i++) {
            bool flag = true;
            for(int j = 0; j < m; j++) {
                if(p[j] == '?') {
                    continue;
                }
                if(t[i+j] != p[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                count += 1;
                indices += to_string(i) + " ";
            }
        } 
    }
    cout << count << endl << indices << endl;
    return 0;
}

int main() {
    int q;
    string t, p;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> t >> p;
        get_result(t, p);
    }
    return 0;
}