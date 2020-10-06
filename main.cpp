#include "header.h"
#include "functions.cpp"

int main(int argc, char *argv[])
{
    int choice=0;
    string wordInput;
    string line = "";
    cout << "Jeigu norite suhashinti ivesta inputa - spauskite 1, jei skaityti is failo - 0"<<endl;
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
        cout << "Skaitymo laikas: "<< (double)std::chrono::duration_cast<std::chrono::milliseconds>(endRead - beginRead).count() / 1000<< "s" << endl;
    }
    else if (choice == 1)
    {
        cin>>wordInput;
        cout<<hashing(wordInput);
    }
    return 0;

}
