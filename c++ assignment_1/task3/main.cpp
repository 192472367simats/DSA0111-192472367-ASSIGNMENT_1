
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int farePaise = 3000;
    long long balancePaise = 100000;
    bool peakHour = true;
    char zoneCode = 'O';
    double fareInRupees = 30.0;

    long long journeys = 3000000;
    long long totalCollection =
        static_cast<long long>(farePaise) * journeys;

    cout << "Fare in paise: " << farePaise << '\n';
    cout << "Balance in paise: " << balancePaise << '\n';
    cout << "Peak hour: " << peakHour << '\n';
    cout << "Zone code: " << zoneCode << '\n';
    cout << "Fare in rupees: " << fareInRupees << '\n';

    cout << "\nData type sizes:\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";
    cout << "bool: " << sizeof(bool) << " bytes\n";
    cout << "char: " << sizeof(char) << " byte\n";

    cout << "\nINT_MAX: " << INT_MAX << '\n';
    cout << "Daily collection in paise: "
         << totalCollection << '\n';

    cout << "Daily collection in rupees: "
         << totalCollection / 100 << '\n';

    return 0;
}
