#include "header.h"

string hashing(string text = "")
{
    unsigned int sum = 2;
    if (text == "")
    {
        text += std::to_string(sum);
    }
    for (auto i : text) //konvertuojama stringas i bitus V
    {
        unsigned int val = int(i);
        sum += val * val;
        sum +=  sum << 1;
        sum %= (sum & val) - (val + 13) * (val / 2);
    }
    stringstream streamas;
    streamas << hex << sum; //bitai hashinami
    string rez = (streamas.str());
    while (rez.length() != 16)
    {
        for (unsigned int ch : rez)
        {
            ch = (ch +~ rez.length()) * sum >> 2;
            streamas.str("");
            streamas << hex << ch;
            rez += streamas.str();
        }
        if (rez.length() > 16)
        {
            rez = rez.substr(0, 16); //jeigu hashas didesnis nei 16, ji substractina iki 16
        }
    }
    return rez;
}
