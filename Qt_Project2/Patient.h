#pragma once
#include <iostream>
#include <QtCore/qstring.h>
#include <QtCore/qtextstream.h>
using namespace std;

enum specie { cat = 1, bird = 2, dog = 3 };

/// base class for Cat, Dog and Bird derived classes
class Patient
{

private:
	int identificationNumber;
	string name;
	specie sp;


public:

	///constructor with parameters for the Patient class
	Patient(int identifNr, string n, int specie_index);

	///destructor for theh Patient class
	virtual ~Patient();

	///setter for the identificationNumber attribute
	inline void setIdNr(int identifNr)
	{
		identificationNumber = identifNr;
	}

	///getter for the identificationNumber attribute
	inline int getIdNr()
	{
		return identificationNumber;
	}

	///setter for the name attribute
	inline void setName(string n)
	{
		name = n;
	}

	///getter for the name attribute
	inline string getName()
	{
		return name;
	}

	///getter for the specie attribute
	inline specie getSpecie()
	{
		return sp;
	}

	///setter for the specie attribute
	inline void setSpecie(specie s)
	{
		sp = s;
	}


	///method for displaying a Patient object
	virtual QString patientString();
};
