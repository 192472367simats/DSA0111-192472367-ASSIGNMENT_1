
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    const int farePaise = 3000;
    const double fareRupees = 30.00;

    long long journeyCounts[] = {
        20000, 500000, 3000000
    };

    cout << fixed << setprecision(2);
    cout << "METRO COLLECTION COMPARISON\n";
    cout << "---------------------------\n";

    for (long long journeys : journeyCounts) {
        long long paiseTotal =
            journeys * farePaise;

        double doubleTotal =
            journeys * fareRupees;

        cout << "\nJourneys: " << journeys << '\n';

        cout << "Integer paise total: "
             << paiseTotal << '\n';

        cout << "Integer rupees total: "
             << paiseTotal / 100.0 << '\n';

        cout << "Double rupees total: "
             << doubleTotal << '\n';

        if (paiseTotal > INT_MAX)
            cout << "Integer range: Overflow risk\n";
        else
            cout << "Integer range: Safe\n";
    }

    cout << "\nINT_MAX: " << INT_MAX << '\n';
    cout << "Long long is used for large totals.\n";

    return 0;
}
