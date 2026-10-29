
#include "Sequence.h"
#include <fstream>

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