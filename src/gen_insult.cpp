#include "gen_insult.h"
#include "globalfuncts.h"
#include <fstream>
using namespace std;

Insult::Insult()
{
}

string Insult::laydownheat() const
{
	string heatstring = "error: check code or insult data file";
	ifstream madfile;
	madfile.open("./settings/insults.dat");
	if (madfile.is_open())
	{
		string tmpName = "";
		auto chosenSeed = 0;
		chosenSeed = randomNumber(0, 12);						 //update this if you update thing list, starts at 0
		madfile.ignore(numeric_limits<streamsize>::max(), '\n'); //go down one line
		for (auto i = 0; i < chosenSeed; i++)
		{ //go over to the proper noun rolled based on seed
			madfile.ignore(numeric_limits<streamsize>::max(), ';');
		}
		getline(madfile, tmpName, ';');
		heatstring = tmpName;
		madfile.ignore(numeric_limits<streamsize>::max(), '\n'); //go down one line
		madfile.ignore(numeric_limits<streamsize>::max(), '\n'); //go down one line
		chosenSeed = randomNumber(0, 10);						 //update this if you update the adverb list, starts at 0
		for (auto i = 0; i < chosenSeed; i++)
		{ //go over to the proper adverb rolled based on seed
			madfile.ignore(numeric_limits<streamsize>::max(), ';');
		}
		getline(madfile, tmpName, ';');
		heatstring += tmpName;
	}
	if (madfile.is_open())
		madfile.close();
	return heatstring;
}
