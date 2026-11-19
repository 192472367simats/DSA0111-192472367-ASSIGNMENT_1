
#include <iostream>
using namespace std;

constexpr int INNER_FARE = 1000;
constexpr int MIDDLE_FARE = 2000;
constexpr int OUTER_FARE = 3000;
constexpr int PEAK_SURCHARGE = 20;
constexpr int MIN_BALANCE = 5000;

enum class Zone {
    Inner, Middle, Outer
};

int main() {
    Zone selectedZone = Zone::Outer;
    int fare = 0;

    switch (selectedZone) {
        case Zone::Inner:
            fare = INNER_FARE;
            break;

        case Zone::Middle:
            fare = MIDDLE_FARE;
            break;

        case Zone::Outer:
            fare = OUTER_FARE;
            break;
    }

    fare += fare * PEAK_SURCHARGE / 100;

    cout << "Base fare: " << OUTER_FARE << " paise\n";
    cout << "Peak fare: " << fare << " paise\n";
    cout << "Minimum balance: " << MIN_BALANCE << " paise\n";

    return 0;
}
