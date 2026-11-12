#include <iostream>
using namespace std;
int main() {
    int d, sumTime;
    cin >> d >> sumTime;

    int mn[30], mx[30], schedule[30];
    int total = 0;

    for (int i = 0; i < d; i++) {
        cin >> mn[i] >> mx[i];
        schedule[i] = mn[i];
        total += mn[i];
    }

    if (total > sumTime) {
        cout << "NO";
        return 0;
    }

    int remaining = sumTime - total;

    for (int i = 0; i < d; i++) {
        int extra = mx[i] - mn[i];

        if (extra > remaining)
            extra = remaining;

        schedule[i] += extra;
        remaining -= extra;
    }

    if (remaining > 0) {
        cout << "NO";
    } else {
        cout << "YES\n";

        for (int i = 0; i < d; i++) {
            cout << schedule[i] << " ";
        }
    }

    return 0;
}
