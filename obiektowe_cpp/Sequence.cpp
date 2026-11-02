#include "Sequence.h"
#include <fstream>
#include <iostream>

using namespace std;

Sequence::Sequence()
{
    header = "";
    sequence = "";
}

string Sequence::getHeader() const
{
    return header;
}

string Sequence::getSequence() const
{
    return sequence;
}

bool Sequence::readFasta(const string& filePath)
{
    ifstream file(filePath);

    if (!file.is_open())
    {
        return false;
    }

    string line;
    string newHeader;
    string newSequence;

    if (!getline(file, line) ||
        line.empty() || line[0] != '>')
    {
        return false;
    }

    newHeader = line.substr(1);

    while (getline(file, line))
    {
        if (!line.empty() && line[0] == '>')
        {
            return false;
        }

        newSequence += line;
    }

    if (file.bad())
    {
        return false;
    }

    header = newHeader;
    sequence = newSequence;

    return true;
}


void Sequence::countNucleotides() const
{
    int a = 0;
    int c = 0;
    int g = 0;
    int t = 0;

    for (char nucleotide : sequence)
    {
        switch (nucleotide)
        {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;
        }
    }

    cout << a << " " << c << " "
        << g << " " << t << endl;
}


string Sequence::transcribeToRNA() const
{
    string rna = sequence;

    for (char& nucleotide : rna)
    {
        if (nucleotide == 'T')
        {
            nucleotide = 'U';
        }
    }

    return rna;
}
