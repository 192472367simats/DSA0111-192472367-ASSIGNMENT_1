
#include <iostream>
#include <string>
using namespace std;

long long calculateFare(int zone, int hour) {
    if (zone < 1 || zone > 3)
        return -1;

    if (hour < 0 || hour > 23)
        return -1;

    int baseFare = zone * 1000;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        baseFare += baseFare * 20 / 100;

    return baseFare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}

int main() {
    struct Test {
        int zone;
        int hour;
        long long balance;
    };

    Test tests[] = {
        {1, 7, 10000},
        {2, 8, 10000},
        {3, 10, 10000},
        {1, 17, 10000},
        {2, 20, 10000},
        {3, 18, 10000},
        {1, 12, 6000},
        {4, 12, 10000}
    };

    cout << "METRO FARE TESTING\n";
    cout << "------------------\n";

    int count = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < count; i++) {
        long long f = calculateFare(
            tests[i].zone, tests[i].hour
        );

        cout << "Test " << i + 1 << ": ";

        if (f == -1) {
            cout << "Invalid input\n";
        } else if (canTravel(tests[i].balance, f)) {
            cout << "Fare = " << f
                 << " paise, Approved\n";
        } else {
            cout << "Fare = " << f
                 << " paise, Denied\n";
        }
    }

    return 0;
}
