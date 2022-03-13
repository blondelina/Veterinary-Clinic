#include "Cat.h"
#include <iomanip>

Cat::Cat(int identifNr, string n, int sp) : Patient(identifNr, n, sp)
{

}

Cat::~Cat()
{
}

QString Cat::patientString()
{
	QString qstr = "Cat of id ";
	qstr.append(QString::number(getIdNr()));
	qstr.append(" ,name ");
	qstr.append(QString::fromStdString(getName()));
	qstr.append("\n");
	return qstr;
}

