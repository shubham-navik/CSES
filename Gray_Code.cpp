#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void generateGrayCode(int n, vector<string>& grayCodes) {
    if (n <= 0) return;

    // Start with a single bit
    grayCodes.push_back("0");
    grayCodes.push_back("1");

    // Generate gray codes for more bits
    for (int i = 2; i <= n; i++) {
        int currentSize = grayCodes.size();

        // Reflect the current codes
        for (int j = currentSize - 1; j >= 0; j--) {
            grayCodes.push_back(grayCodes[j]);
        }

        // Prefix '0' to the first half
        for (int j = 0; j < currentSize; j++) {
            grayCodes[j] = "0" + grayCodes[j];
        }

        // Prefix '1' to the second half
        for (int j = currentSize; j < grayCodes.size(); j++) {
            grayCodes[j] = "1" + grayCodes[j];
        }
    }
}

int main() {
    ll n;
    cin >> n;

    vector<string> grayCodes;
    generateGrayCode(n, grayCodes);

    for (const string& code : grayCodes) {
        cout << code << "\n";
    }

    return 0;
}
