#pragma once
#include "Patient.h"
class Dog : public Patient
{
public:
	///constructor with parameters for the Dog class
	Dog(int identifNr, string n, int sp);

	///destructor for the Dog class
	~Dog();

	///method for displaying a Dog object
	QString patientString() override;
};

