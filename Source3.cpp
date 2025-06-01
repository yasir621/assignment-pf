#include<iostream>
using namespace std;
void input(float array[5][5]);
void avrgrow(float array[5][5], float avg[]);
void extream(float array[5][5], float& maxval, int& maxrow, int& maxcol, float& minval, int& minrow, int& mincol);
void disply(float avg[], float maxval, int maxrow, int maxcol, float minval, int minrow, int mincol);
int main() {
	float temp[5][5];
	float avg[5];
	float maxval, minval;
	int maxrow, maxcol, minrow, mincol;

	input(temp);
	avrgrow(temp, avg);
	extream(temp, maxval, maxrow, maxcol, minval, minrow, mincol);
	disply(avg, maxval, maxrow, maxcol, minval, minrow, mincol);

	return 0;
}
void input(float array[5][5]) {
	cout << "Enter value of 5*5 grid :" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Row " << i + 1 << ":\n";
		for (int j = 0; j < 5; j++)
		{
			cout << "Loction " << j + 1 << ":";
			cin >> array[i][j];
		}
	}
}
void avrgrow(float array[5][5], float avg[]) {
	for (int i = 0; i < 5; i++)
	{
		float sum = 0;
		for (int j = 0; j < 5; j++)
		{
			sum += array[i][j];
		}
		avg[i] = sum / 5;
	}

}
void extream(float array[5][5], float& maxval, int& maxrow, int& maxcol, float& minval, int& minrow, int& mincol) {
	maxval = array[0][0];
	minval = array[0][0];
	maxrow = maxcol = minrow, mincol = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (array[i][j]>maxval)
			{
				maxval = array[i][j];
				maxrow = i;
				maxcol = j;
			}
			if (array[i][j]<minval)
			{
				minval = array[i][j];
				minrow = i;
				mincol = j;
			}
		}
	}

}
void disply(float avg[], float maxval, int maxrow, int maxcol, float minval, int minrow, int mincol) {
	cout << "Avrg temprature per row:\n";
	for (int i = 0; i < 5; i++)
	{
		cout << "Zone " << i + 1 << " average: " << avg[i] << endl;
	}
	cout << "\nExtream temprature :" << endl;
	cout << "Maximum: " << maxval << " at (" << maxrow + 1 << ", " << maxcol + 1 << ")\n";
	cout << "Minimum: " << minval << " at (" << minrow + 1 << ", " << mincol + 1 << ")\n";

}