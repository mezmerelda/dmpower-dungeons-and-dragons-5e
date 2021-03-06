#include "gen_name.h"
#include <fstream>

using namespace std;

string CharacterName::grabRandomName()
{
    ifstream fileOfNames;
    string tmpName;
    fileOfNames.open("./settings/names.dat");

    if (fileOfNames.is_open())
    {
        int number_of_lines = 0; //count the number of lines
        string line;
        while (getline(fileOfNames, line))
            ++number_of_lines;
        fileOfNames.clear();                 //clear end of file status so seekg will work
        fileOfNames.seekg(0, ios_base::beg); //return to beginning position

        //pick one name randomly
        auto chosenSeed = randomNumber(1, number_of_lines);
        for (auto i = 1; i < chosenSeed; i++)
        {
            fileOfNames.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        getline(fileOfNames, tmpName, '\n');
    }
    else
    {
        tmpName = "error with name file - check code";
    }
    return tmpName;
}
