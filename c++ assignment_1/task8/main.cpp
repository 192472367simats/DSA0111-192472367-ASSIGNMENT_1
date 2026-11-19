
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

int main() {
    string passenger;
    int zone, hour;
    long long balance;

    cout << "METRO SMART CARD SYSTEM\n";

    cout << "Enter passenger name: ";
    getline(cin, passenger);

    cout << "Enter zone (1-3): ";

    while (!(cin >> zone) || zone < 1 || zone > 3) {
        cout << "Invalid zone. Enter 1, 2 or 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter hour (0-23): ";

    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter 0-23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter card balance in rupees: ";

    while (!(cin >> balance) || balance < 0) {
        cout << "Invalid balance. Enter again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int fare = zone * 1000;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += fare * 20 / 100;

    long long fareRupees = fare / 100;

    cout << "\n------ JOURNEY REPORT ------\n";
    cout << "Passenger: " << passenger << '\n';
    cout << "Zone: " << zone << '\n';
    cout << "Hour: " << hour << '\n';
    cout << "Peak hour: " << (peak ? "Yes" : "No") << '\n';

    cout << fixed << setprecision(2);
    cout << "Fare: Rs " << fare / 100.0 << '\n';

    if (balance * 100 - fare >= 5000) {
        balance -= fareRupees;
        cout << "Journey Status: Approved\n";
    } else {
        cout << "Journey Status: Denied\n";
    }

    cout << "Remaining balance: Rs " << balance << '\n';

    return 0;
}
