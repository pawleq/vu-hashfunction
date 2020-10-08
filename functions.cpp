#include "header.h"

string hashing(string text = "")
{
    unsigned int hasha = 8;
    int zz = 69;
    for (int i = 0; i < zz; i++) //judinami/keitienjami bitai
    {
        unsigned int hashb = int(i);
        hasha += (hashb>>7) * (hashb<<2);
        hasha +=  hasha << 5;
        hasha %= (hasha & hashb)-(hasha>>5)+(hashb<<12);
    }
    stringstream streamas;
    streamas << hex << hasha; //bitai hashinami
    string hashOut = (streamas.str());
    while (hashOut.length() != 16)
    {
        for (unsigned int i : hashOut) //vel keitinejami bitai
        {
            i = (i + hashOut.length()) * hasha >> 4;
            streamas.str("");
            streamas << hex << i;
            hashOut += streamas.str();
        }
        if (hashOut.length() > 16)
        {
            hashOut = hashOut.substr(0, 16); //substractina iki 16 ilgio hasho
        }
    }
    return hashOut;
}
std::string alphaNumericStrings(const int length)   //stack overflow funkcija random alpha-numeric stringam generuoti
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string result("", length);
    for (int i = 0; i < length; ++i)
    {
        result[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return result;
}

void test4RandomWords()   //
{
    int coll = 0;
    std::cout << "Testing....." << "\n";
    for (int i = 0; i < RANDOM_COUNT; i++)
    {
        std::string wordA = alphaNumericStrings(RANDOM_LENGTH);
        std::string wordB = alphaNumericStrings(RANDOM_LENGTH);
        if (hashing(wordA) == hashing(wordB))
        {
            coll++;
        }
    }
    std::cout << "Rasta collision'u : " << coll << "\n";
    if (coll == 0)
        std::cout<<"Hash funkcija ganetinai saugi."<<std::endl;
}
