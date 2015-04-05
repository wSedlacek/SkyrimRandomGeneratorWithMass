#include "Character.h"
#include "RandomVals.h"
#include <random>
#include <fstream>
#include <iostream>


Character::Character(){
	this->RNRace = randomRace();
	this->RNGender = randomGender();
	//randomAge();

	printChar();
}

Character::~Character(){}

//RACE============================================
Race Character::randomRace(){
	int tRaces = totalRaces() - 1;

	random_device generator;
	uniform_int_distribution<int> distribution(0, tRaces);
	int RNGesus = distribution(generator);

	Race generatedRace;

	if (RNGesus < RALTMER) {
		generatedRace = ALTMER;
	} else if (RNGesus < RALTMER + RARGONIAN) {
		generatedRace = ARGONIAN;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER) {
		generatedRace = BOSMER;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER + RBRETON) {
		generatedRace = BRETON;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER + RBRETON + RDUNMER) {
		generatedRace = DUNMER;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER + RBRETON + RDUNMER + RIMPERIAL) {
		generatedRace = IMPERIAL;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER + RBRETON + RDUNMER + RIMPERIAL + RKHAJIIT) {
		generatedRace = KHAJIIT;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER + RBRETON + RDUNMER + RIMPERIAL + RKHAJIIT + RNORD) {
		generatedRace = NORD;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER + RBRETON + RDUNMER + RIMPERIAL + RKHAJIIT + RNORD + RORC) {
		generatedRace = ORC;
	} else if (RNGesus < RALTMER + RARGONIAN + RBOSMER + RBRETON + RDUNMER + RIMPERIAL + RKHAJIIT + RNORD + RORC + RREDGAURD) {
		generatedRace = REDGAURD;
	}

	return generatedRace;
}

int Character::totalRaces() {
	return RALTMER  + RARGONIAN +   RBOSMER + 
		   RBRETON  +   RDUNMER + RIMPERIAL + 
		   RKHAJIIT +     RNORD +      RORC + RREDGAURD;
}

//GENDER==========================================
Gender Character::randomGender() {
	int tGender = RMALE + RFEMALE -1;

	random_device generator;
	uniform_int_distribution<int> distribution(0, tGender);
	int RNGesus = distribution(generator);

	Gender generatedGender;

	if (RNGesus < RMALE)
		generatedGender = MALE;
	else if (RNGesus < RMALE + RFEMALE)
		generatedGender = FEMALE;

	return generatedGender;
}

void Character::printChar()
{
	ofstream outFile;
	outFile.open("random.txt");
	if (!outFile.fail()) {
		//RACE============================================
		switch (RNRace)
		{
		case ALTMER: outFile << "ALTMER";
			break;
		case ARGONIAN: outFile << "ARGONIAN";
			break;
		case BOSMER: outFile << "BOSMER";
			break;
		case BRETON: outFile << "BRETON";
			break;
		case DUNMER: outFile << "DUNMER";
			break;
		case IMPERIAL: outFile << "IMPERIAL";
			break;
		case KHAJIIT: outFile << "KHAJIIT";
			break;
		case NORD: outFile << "NORD";
			break;
		case ORC: outFile << "ORC";
			break;
		case REDGAURD: outFile << "REDGAURD";
			break;
		default: outFile << "ERROR";
			break;
		}

		outFile << endl;
		//GENDER==========================================
		switch (RNGender)
		{
		case MALE: outFile << "MALE";
			break;
		case FEMALE: outFile << "FEMALE";
			break;
		default: outFile << "ERROR";
			break;
		}

		outFile << endl;
	}
	else
		cout << "ERROR!";
	outFile.close();
}
