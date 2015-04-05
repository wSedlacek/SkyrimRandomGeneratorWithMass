#include"Props.h"
using namespace std;

class Character
{
public:
	Character();
	~Character();

	Race randomRace();
	int totalRaces();

	Gender randomGender();

	void printChar();

private:
	Race RNRace;
	Gender RNGender;
};