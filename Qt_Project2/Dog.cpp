#include "Dog.h"
#include <iomanip>

Dog::Dog(int identifNr, string n, int sp) : Patient(identifNr, n, sp)
{
}

Dog::~Dog()
{
}

QString Dog::patientString()
{
	QString qstr = "Dog of id ";
	qstr.append(QString::number(getIdNr()));
	qstr.append(" ,name ");
	qstr.append(QString::fromStdString(getName()));
	qstr.append("\n");
	return qstr;
}

