#include <iostream>
using namespace std;

void input(int scores[6][4]) {
    for (int i = 0; i < 6; i++) {
        cout << "Enter scores for Team " << i + 1 << ":\n";
        for (int j = 0; j < 4; j++) {
            cout << "  Round " << j + 1 << ": ";
            cin >> scores[i][j];
        }
    }
}

void calculateTotal(int scores[6][4], int total[6]) {
    for (int i = 0; i < 6; i++) {
        total[i] = 0;
        for (int j = 0; j < 4; j++) {
            total[i] += scores[i][j];
        }
    }
}

void TopTwo(int total[6], int topTwo[2]) {
    int first = 0;
    int second = 1;

    if (total[1] > total[0]) {
        first = 1;
        second = 0;
    }

    for (int i = 2; i < 6; i++) {
        if (total[i] > total[first]) {
            second = first;
            first = i;
        }
        else if (total[i] > total[second]) {
            second = i;
        }
    }

    topTwo[0] = first;
    topTwo[1] = second;
}

void FailingTeams(int scores[6][4], bool failed[6]) {
    for (int i = 0; i < 6; i++) {
        failed[i] = false;
        for (int j = 0; j < 4; j++) {
            if (scores[i][j] <= 10) {
                failed[i] = true;
                break;
            }
        }
    }
}

void display(int total[6], int topTwo[2], bool failed[6]) {
    cout << "\nTotal Scores:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Team " << i + 1 << ": " << total[i] << endl;
    }

    cout << "\nWinner     : Team " << topTwo[0] + 1 << " (Score: " << total[topTwo[0]] << ")\n";
    cout << "Runner-Up  : Team " << topTwo[1] + 1 << " (Score: " << total[topTwo[1]] << ")\n";

    cout << "\nTeams that scored 10 or less in any round:\n";
    bool anyFailed = false;
    for (int i = 0; i < 6; i++) {
        if (failed[i]) {
            cout << "Team " << i + 1 << endl;
            anyFailed = true;
        }
    }
    if (!anyFailed) {
        cout << "None\n";
    }
}

int main() {
    int scores[6][4];
    int total[6];
    int topTwo[2];
    bool failed[6];

    input(scores);
    calculateTotal(scores, total);
    TopTwo(total, topTwo);
    FailingTeams(scores, failed);
    display(total, topTwo, failed);

    return 0;
}
