#include <iostream>
using namespace std;

void inputDefects(float defects[3][7]) {
    cout << "Enter defect percentages for 3 shifts over 7 days:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Shift " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> defects[i][j];
        }
    }
}

void averagePerShift(float defects[3][7], float shiftAvg[3]) {
    for (int i = 0; i < 3; i++) {
        float sum = 0;
        for (int j = 0; j < 7; j++) {
            sum += defects[i][j];
        }
        shiftAvg[i] = sum / 7;
    }
}

void averagePerDay(float defects[3][7], float dayAvg[7]) {
    for (int j = 0; j < 7; j++) {
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += defects[i][j];
        }
        dayAvg[j] = sum / 3;
    }
}

void findCriticalShifts(float shiftAvg[3], bool critical[3]) {
    for (int i = 0; i < 3; i++) {
        critical[i] = (shiftAvg[i] > 10.0);
    }
}

void displayResults(float shiftAvg[3], float dayAvg[7], bool critical[3]) {
    cout << "\nAverage Defect Percentage per Shift:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Shift " << i + 1 << ": " << shiftAvg[i] << "%\n";
    }

    cout << "\nAverage Defect Percentage per Day:\n";
    for (int j = 0; j < 7; j++) {
        cout << "Day " << j + 1 << ": " << dayAvg[j] << "%\n";
    }

    cout << "\nCritical Shifts (avg > 10%):\n";
    bool any = false;
    for (int i = 0; i < 3; i++) {
        if (critical[i]) {
            cout << "Shift " << i + 1 << " (Average: " << shiftAvg[i] << "%)\n";
            any = true;
        }
    }
    if (!any) {
        cout << "None\n";
    }
}

int main() {
    float defects[3][7];
    float shiftAvg[3];
    float dayAvg[7];
    bool critical[3];

    inputDefects(defects);
    averagePerShift(defects, shiftAvg);
    averagePerDay(defects, dayAvg);
    findCriticalShifts(shiftAvg, critical);
    displayResults(shiftAvg, dayAvg, critical);

    return 0;
}
