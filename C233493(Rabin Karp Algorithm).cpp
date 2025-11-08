#include <iostream>
#include <string>
using namespace std;

#define d 256

void rabinKarpSearch(string pattern, string text, int q) {
    int m = pattern.size();
    int n = text.size();
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0;i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index : " << i << endl;
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    int q = 101;
    rabinKarpSearch(pattern, text, q);
    return 0;
}
