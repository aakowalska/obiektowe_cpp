#pragma once
#include <string>

using namespace std;

class Sequence
{
private:
    string header;
    string sequence;

public:
    Sequence();

    string getHeader() const;
    string getSequence() const;

    bool readFasta(const string& filePath);
};
