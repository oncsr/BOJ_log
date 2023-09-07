#include <iostream>
using namespace std;

int main() {
	int T;
	for (cin >> T; T--;) {
		int R, C, r, c;
		cin >> R >> C >> r >> c;
		if (R == 1) {
			if (c != 1 && c != C) {
				cout << "IMPOSSIBLE\n";
				continue;
			}
			for (int i = 0; i < C - 1; i++)	cout << (c == 1 ? 'R' : 'L');
			cout << '\n';
			continue;
		}
		if (C == 1) {
			if (r != 1 && r != R) {
				cout << "IMPOSSIBLE\n";
				continue;
			}
			for (int i = 0; i < R - 1; i++)	cout << (r == 1 ? 'D' : 'U');
			cout << '\n';
			continue;
		}
		if ((C & 1) && (R & 1)) {
			if ((r ^ c) & 1) {
				cout << "IMPOSSIBLE\n";
				continue;
			}
		}

		if (r == 1) {

			if (((C - c) & 1) == 0) {
				for (int j = 1; j < R - 1; j++)	cout << 'D';
				if (C - c)	cout << 'R';
				for (int i = 0; i < (C - c) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					cout << 'R';
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					if (i != (C - c) / 2 - 1)	cout << 'R';
				}
				cout << 'D';
				for (int j = 1; j <= C - 1; j++)	cout << 'L';
				if (c > 1)	cout << 'U';
				for (int i = 0; i < (c - 1) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					cout << 'R';
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					if (i != (c - 1) / 2 - 1)	cout << 'R';
				}
				if ((c - 1) & 1) {
					if ((c - 1) / 2)	cout << 'R';
					for (int j = 1; j < R - 1; j++)	cout << 'U';
				}
			}

			else if (((c - 1) & 1) == 0) {
				for (int j = 1; j < R - 1; j++)	cout << 'D';
				if (c - 1)	cout << 'L';
				for (int i = 0; i < (c - 1) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					cout << 'L';
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					if (i != (c - 1) / 2 - 1)	cout << 'L';
				}
				cout << 'D';
				for (int j = 1; j <= C - 1; j++)	cout << 'R';
				if (c < C)	cout << 'U';
				for (int i = 0; i < (C - c) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					cout << 'L';
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					if (i != (C - c) / 2 - 1)	cout << 'L';
				}
				if ((C - c) & 1) {
					if ((C - c) / 2)	cout << 'L';
					for (int j = 1; j < R - 1; j++)	cout << 'U';
				}
			}
			else {
				for (int i = 0; i < R / 2; i++) {
					for (int j = 0; j < C - c; j++)	cout << 'R';
					cout << 'D';
					for (int j = 0; j < C - c; j++)	cout << 'L';
					if (i != R / 2 - 1)	cout << 'D';
				}
				cout << 'L';
				for (int i = 0; i < R / 2; i++) {
					for (int j = 0; j < c - 2; j++)	cout << 'L';
					cout << 'U';
					for (int j = 0; j < c - 2; j++)	cout << 'R';
					if (i != R / 2 - 1)	cout << 'U';
				}
			}
			cout << '\n';
			continue;

		}
		if (r == R) {

			if (((C - c) & 1) == 0) {
				for (int j = 1; j < R - 1; j++)	cout << 'U';
				if (C - c)	cout << 'R';
				for (int i = 0; i < (C - c) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					cout << 'R';
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					if (i != (C - c) / 2 - 1)	cout << 'R';
				}
				cout << 'U';
				for (int j = 1; j <= C - 1; j++)	cout << 'L';
				if (c > 1)	cout << 'D';
				for (int i = 0; i < (c - 1) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					cout << 'R';
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					if (i != (c - 1) / 2 - 1)	cout << 'R';
				}
				if ((c - 1) & 1) {
					if ((c - 1) / 2)	cout << 'R';
					for (int j = 1; j < R - 1; j++)	cout << 'D';
				}
			}
			else if (((c - 1) & 1) == 0) {
				for (int j = 1; j < R - 1; j++)	cout << 'U';
				if (c - 1)	cout << 'L';
				for (int i = 0; i < (c - 1) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					cout << 'L';
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					if (i != (c - 1) / 2 - 1)	cout << 'L';
				}
				cout << 'U';
				for (int j = 1; j <= C - 1; j++)	cout << 'R';
				if (c < C)	cout << 'D';
				for (int i = 0; i < (C - c) / 2; i++) {
					for (int j = 1; j < R - 1; j++)	cout << 'D';
					cout << 'L';
					for (int j = 1; j < R - 1; j++)	cout << 'U';
					if (i != (C - c) / 2 - 1)	cout << 'L';
				}
				if ((C - c) & 1) {
					if ((C - c) / 2)	cout << 'L';
					for (int j = 1; j < R - 1; j++)	cout << 'D';
				}
			}
			else {
				for (int i = 0; i < R / 2; i++) {
					for (int j = 0; j < C - c; j++)	cout << 'R';
					cout << 'U';
					for (int j = 0; j < C - c; j++)	cout << 'L';
					if (i != R / 2 - 1)	cout << 'U';
				}
				cout << 'L';
				for (int i = 0; i < R / 2; i++) {
					for (int j = 0; j < c - 2; j++)	cout << 'L';
					cout << 'D';
					for (int j = 0; j < c - 2; j++)	cout << 'R';
					if (i != R / 2 - 1)	cout << 'D';
				}
			}
			cout << '\n';
			continue;

		}
		
		if (((c - 1) & 1) && ((C - c) & 1)) {
			if ((R - r) & 1) {

				for (int i = 0; i < (R - r + 1) / 2; i++) {
					for (int j = 0; j < C - c; j++)	cout << 'R';
					cout << 'D';
					for (int j = 0; j < C - c; j++)	cout << 'L';
					if (i != (R - r + 1) / 2 - 1)	cout << 'D';
				}
				cout << 'L';
				for (int i = 0; i < R / 2; i++) {
					for (int j = 0; j < c - 2; j++)	cout << 'L';
					cout << 'U';
					for (int j = 0; j < c - 2; j++)	cout << 'R';
					if (i != R / 2 - 1)	cout << 'U';
				}
				cout << 'R';
				for (int i = 0; i < (r - 1) / 2; i++) {
					for (int j = 0; j < C - c; j++)	cout << 'R';
					cout << 'D';
					for (int j = 0; j < C - c; j++)	cout << 'L';
					if (i != (r - 1) / 2 - 1)	cout << 'D';
				}
				if ((r - 1) & 1) {
					cout << 'D';
					for (int j = 0; j < C - c; j++)	cout << 'R';
				}
				
			}
			else {

				for (int i = 0; i < r / 2; i++) {
					for (int j = 0; j < C - c; j++)	cout << 'R';
					cout << 'U';
					for (int j = 0; j < C - c; j++)	cout << 'L';
					if (i != r / 2 - 1)	cout << 'U';
				}
				cout << 'L';
				for (int i = 0; i < R / 2; i++) {
					for (int j = 0; j < c - 2; j++)	cout << 'L';
					cout << 'D';
					for (int j = 0; j < c - 2; j++)	cout << 'R';
					if (i != R / 2 - 1)	cout << 'D';
				}
				cout << 'R';
				for (int i = 0; i < (R - r) / 2; i++) {
					for (int j = 0; j < C - c; j++)	cout << 'R';
					cout << 'U';
					for (int j = 0; j < C - c; j++)	cout << 'L';
					if (i != (R - r) / 2 - 1)	cout << 'U';
				}
				if ((R - r) & 1) {
					cout << 'U';
					for (int j = 0; j < C - c; j++)	cout << 'R';
				}

			}
			cout << '\n';
			continue;
		}
		
		if ((((c - 1) & 1) == 0) && (((C - c) & 1) == 0)) {
			for (int i = 0; i < (c - 1) / 2; i++) {
				for (int j = 1; j < R - r; j++)	cout << 'D';
				cout << 'L';
				for (int j = 1; j < R - r; j++)	cout << 'U';
				cout << 'L';
			}
			for (int i = 0; i < R - r; i++)	cout << 'D';
			for (int i = 0; i < c; i++)	cout << 'R';

			if (R & 1) {
				for (int i = 0; i < (R - r) / 2; i++) {
					for (int j = 1; j < C - c; j++)	cout << 'R';
					cout << 'U';
					for (int j = 1; j < C - c; j++)	cout << 'L';
					cout << 'U';
				}
				for (int j = 1; j < C - c; j++)	cout << 'R';
				cout << 'U';
				for (int i = 0; i < (r - 1) / 2; i++) {
					for (int j = 1; j < C; j++)	cout << 'L';
					cout << 'U';
					for (int j = 1; j < C; j++)	cout << 'R';
					if (i != (r - 1) / 2 - 1)	cout << 'U';
				}
			}
			else {
				for (int i = 0; i < R / 2; i++) {
					for (int j = 1; j < C - c; j++)	cout << 'R';
					cout << 'U';
					for (int j = 1; j < C - c; j++)	cout << 'L';
					if (i != R / 2 - 1)	cout << 'U';
				}
				if (c > 1)	cout << 'L';
				for (int i = 0; i < (r - 1) / 2; i++) {
					for (int j = 1; j < c; j++)	cout << 'L';
					cout << 'D';
					for (int j = 1; j < c; j++)	cout << 'R';
					if (i != (r - 1) / 2 - 1)	cout << 'D';
				}
				if ((r - 1) & 1) {
					cout << 'D';
					for (int j = 1; j < c; j++)	cout << 'L';
				}
			}
			cout << '\n';
			continue;
		}

		if ((c - 1) & 1) {
			for (int i = 0; i < c / 2; i++) {
				for (int j = 0; j < R - r; j++)	cout << 'D';
				cout << 'L';
				for (int j = 0; j < R - r; j++)	cout << 'U';
				if (i != c / 2 - 1)	cout << 'L';
			}
			cout << 'U';
			for (int i = 0; i < C / 2; i++) {
				for (int j = 1; j < r - 1; j++)	cout << 'U';
				cout << 'R';
				for (int j = 1; j < r - 1; j++)	cout << 'D';
				if (i != C / 2 - 1)	cout << 'R';
			}
			cout << 'D';
			for (int i = 0; i < (C - c) / 2; i++) {
				for (int j = 0; j < R - r; j++)	cout << 'D';
				cout << 'L';
				for (int j = 0; j < R - r; j++)	cout << 'U';
				if (i != (C - c) / 2 - 1)	cout << 'L';
			}
		}
		else {
			for (int i = 0; i < (C - c + 1) / 2; i++) {
				for (int j = 0; j < R - r; j++)	cout << 'D';
				cout << 'R';
				for (int j = 0; j < R - r; j++)	cout << 'U';
				if (i != (C - c + 1) / 2 - 1)	cout << 'R';
			}
			cout << 'U';
			for (int i = 0; i < C / 2; i++) {
				for (int j = 1; j < r - 1; j++)	cout << 'U';
				cout << 'L';
				for (int j = 1; j < r - 1; j++)	cout << 'D';
				if (i != C / 2 - 1)	cout << 'L';
			}
			cout << 'D';
			for (int i = 0; i < c / 2; i++) {
				for (int j = 0; j < R - r; j++)	cout << 'D';
				cout << 'R';
				for (int j = 0; j < R - r; j++)	cout << 'U';
				if (i != c / 2 - 1)	cout << 'R';
			}
		}
		cout << '\n';
	}
}