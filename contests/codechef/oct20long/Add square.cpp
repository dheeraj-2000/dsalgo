#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <bitset>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int mx = 100001;

int main() {
	int width, height, numVer, numHor;
	cin >> width >> height >> numVer >> numHor;
	// bitsets for vertical and horizontal lines
	// vertical[i] is set if there is a line y=i
	// horizontal[i] is set if there is a line x=i
	// revHorizontal[i] is set if there is a line x=height-i
	bitset<mx> vertical, horizontal, revHorizontal;

	// read in x-coordinates of vertical lines and store in bitset
	for (int i = 0; i < numVer; i++) {
		int verLine;
		cin >> verLine;
		vertical.set(verLine);
	}
	// read in y-coordinates of horizontal lines and store in bitset
	for (int i = 0; i < numHor; i++) {
		int horLine;
		cin >> horLine;
		horizontal.set(horLine);
		revHorizontal.set(height-horLine);
	}
	bitset<mx> verDiff, horDiff;

	// iterate over each of the vertical lines (x=i)
	for (int i = 0; i<= width; i++) if (vertical[i]) {
		// and for each line (at x=j) to the right of it set bit j-i of verDiff
		verDiff |= (vertical >> i);
	}
	// iterate over each of the horizontal lines (y=i)
	for (int i = 0; i<= width; i++) if (horizontal[i]) {
		// and for each line (at y=j) above it set bit j-i of horDiff
		horDiff |= (horizontal >> i);
	}

	int maxSquare = 0;
	// loop over all possible y-coordinates of the new line
	for (int c = 0; c <= height; c++) {
		// newHorDiff will store the newly formed distances, 
		bitset<mx> newHorDiff;
		// update the distances between the new line and those above it
		newHorDiff |= (horizontal >> c);
		// update the distances between the new line and those below it
		newHorDiff |= (revHorizontal >> (height-c));
		// calculate how many squares can be created
		// there is a square of a particular side-length if that side-length
		// is the distance between two horizontal lines, 
		// and the distance between two vertical lines
		int numSquare = (verDiff & (horDiff | newHorDiff)).count();
		maxSquare = max(maxSquare, numSquare);
	}

	// -1 to ignore a 0-area square.
	cout << maxSquare-1 << endl;

	return 0;
}
