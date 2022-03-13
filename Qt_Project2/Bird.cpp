#include "Bird.h"
#include <iomanip>

Bird::Bird(int identifNr, string n, int sp, bool f) : Patient(identifNr, n, sp)
{
	can_fly = f;
}

Bird::~Bird()
{
}

QString Bird::patientString()
{
	QString qstr = "Bird of id ";
	qstr.append(QString::number(getIdNr()));
	qstr.append(" ,name ");
	qstr.append(QString::fromStdString(getName()));
	if (can_fly == true)
		qstr.append(" ,with the ability to fly");
	else
		qstr.append(" ,without the ability to fly");
	
	qstr.append("\n");
	return qstr;
}

