#include <iostream>
using namespace std;
bool a[15][15];
int N, ans;
bool check(int row, int col) {
	int x, y;
	x = row - 1;
	y = col;
	while(x >= 0) {
		if (a[x][y]) return false;
		x--;
	}
	x = row - 1;
	y = col - 1;
	while (x >= 0 && y >= 0) {
		if (a[x][y]) return false;
		x--; y--;
	}
	x = row - 1;
	y = col + 1;
	while (x >=0  && y < N) {
		if (a[x][y]) return false;
		x--; y++;
	}
	return true;
}

void queen(int row) {
	if (row == N) {
		ans += 1;
	}

	for (int col = 0; col < N; col++) {
		a[row][col] = true;
		if (check(row, col))
			queen(row + 1);
		a[row][col] = false;
	}
}

int main() {
	cin >> N;
	queen(0);
	cout << ans << endl;
}