
#include <iostream>
#include "Sequence.h"

using namespace std;

int main()
{
    Sequence dna;

    if (dna.readFasta("example.fasta"))
    {
        cout << "Counting DNA Nucleotides:" << endl;
        dna.countNucleotides();

        cout << endl;

        cout << "Transcribing DNA into RNA:" << endl;
        cout << dna.transcribeToRNA() << endl;
    }
    else
    {
        cout << "Error loading fasta file" << endl;
    }

    return 0;
}
