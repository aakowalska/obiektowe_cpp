#include <iostream>
#include "Sequence.h"

using namespace std;

int main() {
	Sequence dna;

	if (dna.readFasta("example.fasta")) {
		cout << "Header: " << dna.getHeader() << endl;
		cout << "Sequence: " << dna.getSequence() << endl;
	}
	else {
		cout << "Failed to read FASTA file." << endl;
	}

	return 0;
}