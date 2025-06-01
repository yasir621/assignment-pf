#include <iostream>
using namespace std;

void inputRatings(int ratings[5][10]) {
    for (int i = 0; i < 5; i++) {
        cout << "Enter ratings (1–5) for Product " << i + 1 << " by 10 users:\n";
        for (int j = 0; j < 10; j++) {
            cout << "  User " << j + 1 << ": ";
            cin >> ratings[i][j];
        }
    }
}

void calculateAverages(int ratings[5][10], float avg[5]) {
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += ratings[i][j];
        }
        avg[i] = sum / 10.0;
    }
}

void countPerfectRatings(int ratings[5][10], int perfect[5]) {
    for (int i = 0; i < 5; i++) {
        perfect[i] = 0;
        for (int j = 0; j < 10; j++) {
            if (ratings[i][j] == 5) {
                perfect[i]++;
            }
        }
    }
}

void findWorstProducts(float avg[5], bool worst[5]) {
    float minAvg = avg[0];
    for (int i = 1; i < 5; i++) {
        if (avg[i] < minAvg) {
            minAvg = avg[i];
        }
    }
    for (int i = 0; i < 5; i++) {
        worst[i] = (avg[i] == minAvg);
    }
}

void displayResults(float avg[5], int perfect[5], bool worst[5]) {
    cout << "\nProduct Summary:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << ": Average = " << avg[i]
            << ", Perfect Ratings = " << perfect[i] << endl;
    }

    cout << "\nProduct(s) with Worst Average:\n";
    for (int i = 0; i < 5; i++) {
        if (worst[i]) {
            cout << "Product " << i + 1 << " (Average: " << avg[i] << ")\n";
        }
    }
}

int main() {
    int ratings[5][10];
    float avg[5];
    int perfect[5];
    bool worst[5];

    inputRatings(ratings);
    calculateAverages(ratings, avg);
    countPerfectRatings(ratings, perfect);
    findWorstProducts(avg, worst);
    displayResults(avg, perfect, worst);

    return 0;
}
