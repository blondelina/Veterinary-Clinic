#pragma once
#include "Patient.h"
class Cat : public Patient
{
public:
	///constructor with parameters for the Cat class
	Cat(int identifNr, string n, int sp);

	///destructor for the Cat class
	~Cat();

	///method for displaying a Cat object
	QString patientString() override;


};


