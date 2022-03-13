#pragma once
#include "Patient.h"
class Bird : public Patient
{
private:
	bool can_fly;
public:
	///constructor with parameters for the Bird class
	Bird(int identifNr, string n, int sp, bool f);

	///destructor for the Bird class
	~Bird();

	///method for displaying a Bird object
	QString patientString() override;

	///setter for the can_fly attribute
	inline void setFlyAbility(bool f)
	{
		can_fly = f;
	}

	///getter for the can_fly attribute
	inline bool getFlyAbility()
	{
		return can_fly;
	}

};
