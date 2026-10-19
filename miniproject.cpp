#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

vector<int> naive(string text, string pattern) {
    vector<int> ans;
    int n = text.size(), m = pattern.size();

    if (m == 0 || m > n) return ans;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;

        if (j == m) ans.push_back(i);
    }
    return ans;
}
vector<int> rabinKarp(string text, string pattern) {
    vector<int> ans;
    int n = text.size(), m = pattern.size();

    if (m == 0 || m > n) return ans;

    const int d = 256, q = 101;
    long long p = 0, t = 0, h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + (unsigned char)pattern[i]) % q;
        t = (d * t + (unsigned char)text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            while (j < m && text[i + j] == pattern[j])
                j++;
            if (j == m) ans.push_back(i);
        }

        if (i < n - m) {
            t = (d * (t - (unsigned char)text[i] * h)
                 + (unsigned char)text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    return ans;
}

void display(string name, vector<int> ans, double time) {
    cout << name << "\n";

    if (ans.empty()) cout << "Pattern not found\n";
    else {
        cout << "Indices: ";
        for (int i : ans) cout << i << " ";
        cout << "\nOccurrences: " << ans.size() << "\n";
    }

    cout << "Time: " << time << " microseconds\n\n";
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    if (pattern.empty()) {
        cout << "Pattern must not be empty\n";
        return 0;
    }

    auto s1 = high_resolution_clock::now();
    vector<int> a = naive(text, pattern);
    auto e1 = high_resolution_clock::now();

    auto s2 = high_resolution_clock::now();
    vector<int> b = rabinKarp(text, pattern);
    auto e2 = high_resolution_clock::now();

    double t1 = duration<double, micro>(e1 - s1).count();
    double t2 = duration<double, micro>(e2 - s2).count();

    display("Naive String Matching:", a, t1);
    display("Rabin-Karp String Matching:", b, t2);

    return 0;
}
