#include <string>
#include <iostream>

using namespace std;

long long get_result(string s, string t) {
    int n = s.length();
    int m = t.length();
    long long matches = 0;
    long long total = n;
    total *= n + 1;
    total /= 2;
    for(int i = 0; i < n-m+1; i++) {
        for(int l = m; l < n-i+1; l++) {
            bool jump = false;
            string sub_s = s.substr(i, l);
            for(int j = 0; j < l-m+1; j++) {
                if(t.compare(sub_s.substr(j, m)) == 0) {
                    matches += n-m-i-j+1;
                    jump = true;
                    break;
                }
            }
            if(jump) {
                break;
            }
        }
    }
    total -= matches;
    return total;
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