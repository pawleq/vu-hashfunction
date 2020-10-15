#include "header.h"

int coll = 0;
double minDif = 1.0;
double totalDif = 0;
double maxDif = 0;

string hashing(string text = "") //mixuojame stringo ascii values su ivairiom operacijomis, apkeitinejam bitus
{
    int hasha = 8;
    for (auto i : text)
    {
        int hashb = int(i);
        hasha += hashb * hashb;
        hasha -= (hashb % hasha);
        hasha +=  hasha << 5;
        hasha -= (hasha & hashb) - (hashb + 14) * (hashb / 4);
    }
    hasha = hasha >> 2;
    stringstream streamas;
    streamas << hex << hasha;
    string hashOut = (streamas.str());
    while (hashOut.length() != 64)
    {
        for (int i : hashOut)
        {
            i = (i*i) * (hasha*hasha);
            streamas.str("");
            streamas << hex << i;
            hashOut += streamas.str();
        }
        if (hashOut.length() > 64)
        {
            hashOut = hashOut.substr(0, 64); //substractina iki 16 ilgio hasho
        }
    }
    return hashOut;
}

string alphaNumericStrings(int length)   //stack overflow funkcija random alpha-numeric stringam generuoti
{
    static const char alphanum[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    string randomString("", length);
    for (int i = 0; i < length; i++)
    {
        randomString[i] = alphanum[rand() % (sizeof(alphanum) - 1)]; //random stringo generavimas, naudojant musu char "alphanum" simbolius
    }
    return randomString;
}

void test4RandomWords()   //
{
    cout << "Testing....." << "\n";
    for (int i = 0; i < RCOUNT; i++)
    {
        string wordA = alphaNumericStrings(RLENGTH);
        string wordB = alphaNumericStrings(RLENGTH);
        if (hashing(wordA) == hashing(wordB))
        {
            coll++;
        }
    }
    cout << "Rasta collision'u : " << coll << "\n";
    if (coll == 0) //labai reikalinga salyga
        cout<<"Hash funkcija ganetinai saugi."<<endl;
}

string binary(string word)   //funkcija stringo kiekviena simboli keiciantis i binary
{
    string binary = "";
    for (char& _char : word )
    {
        binary += bitset<8>(_char).to_string();
    }
    return binary; //returnina binary stringo reiksme
}

double compareInput (string inputA, string inputB)   //comparina identical inputo poras
{
    int identical = 0;
    double perc;
    int length = min(inputA.length(), inputB.length());
    for (int i = 0; i < length; i++)
    {
        if (inputA[i] == inputB[i])
        {
            identical++;
        }
    }
    perc = (1.0 - ((double)identical / length));
    return perc;
}

void testSimilar()
{
    cout << "Similar words collision test" << "\n";

    for (int i = 0; i < RCOUNT; i++)   //i cikla deti skaiciu, kuris parodo kiek pory tikrinsim
    {
        string wordA=alphaNumericStrings(RLENGTH);
        string wordB;

        do   //pakeiciame random stringe viena simboli i toki, kad vienas simbolis poroje skirtusi toje pacioje pozicijoje
        {
            //int whichSymbol = rand() % RLENGTH; //randomaizinam kuri simboli keisti nuo 1 iki 5 ( 5 yra similar length kuris gali but keiciamas), arba galim naudot tiesiog skaiciu, bet tiketina kad gali su daugiau poru atsirasti collisiniosas
            string changedSymbol = alphaNumericStrings(1);
            wordB = wordA;
            wordB[3/*whichSymbol*/] = changedSymbol[0];
            //cout <<wordA<<" "<<wordB<<endl;
        }
        while (wordA == wordB);

        string hasha = hashing(wordA);
        string hashb = hashing(wordB);

        if (hasha == hashb)
            coll++;

        string binary1 = binary(hasha);
        string binary2 = binary(hashb);

        double difference = compareInput(binary1, binary2);
        totalDif = totalDif + difference;
        if (difference < minDif)
        {
            minDif = difference;
        }
        else if (difference > maxDif)
        {
            maxDif = difference;
        }
    }
    cout << "Collision'ai: " << coll <<endl;
    cout << "Min diff: " << minDif * 100 << endl;
    cout << "Max diff: " << maxDif * 100 << endl;
    cout << "Average diff: " << (totalDif / RCOUNT) * 100 << endl;
}
