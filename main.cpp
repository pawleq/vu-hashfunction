#include "header.h"
#include "functions.cpp"

int main(int argc, char *argv[])
{
    int choice=0;
    string wordInput;
    string line = "";
    cout << "Jeigu norite suhashinti ivesta inputa - spauskite 1, jei skaityti is failo - 0, 2 - vykdyti testa su random zodziais, 3 - vykdyti testa su stringu porom"<<endl;
    cin >> choice;
    if (choice == 0)
    {
        auto beginRead = std::chrono::system_clock::now();
        for (int i = 1; i < argc; i++)
        {
            ifstream infile(argv[i]);
            ofstream outFile("results.txt");
            if (infile.is_open() && infile.good())
            {
                while (getline(infile, line))
                {
                    outFile <<hashing(line);
                    outFile<<endl;
                }
            }
        }
        auto endRead = std::chrono::system_clock::now();
        cout << "Vykdymo laikas: "<< (double)std::chrono::duration_cast<std::chrono::milliseconds>(endRead - beginRead).count() / 1000<< "s" << endl;
    }
    else if (choice == 1)
    {
        cin>>wordInput;
        cout<<hashing(wordInput);
    }
    else if (choice == 2)
    {
        auto beginReadRand = std::chrono::system_clock::now();
        test4RandomWords();
        auto endReadRand = std::chrono::system_clock::now();
        cout << "Vykdymo laikas: "<< (double)std::chrono::duration_cast<std::chrono::milliseconds>(endReadRand - beginReadRand).count() / 1000<< "s" << endl;
    }
    else if (choice == 3)
    {
        auto beginReadRand = std::chrono::system_clock::now();
        testSimilar();
        auto endReadRand = std::chrono::system_clock::now();
        cout << "Vykdymo laikas: "<< (double)std::chrono::duration_cast<std::chrono::milliseconds>(endReadRand - beginReadRand).count() / 1000<< "s" << endl;
    }
    return 0;

}
