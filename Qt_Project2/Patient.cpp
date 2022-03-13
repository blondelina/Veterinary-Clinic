#include <iomanip>
#include <iostream>
#include "Patient.h"
#include "Bird.h"
using namespace std;



Patient::Patient(int identifNr, string n, int specie_index)
{
	identificationNumber = identifNr;
	name = n;
	sp = specie(specie_index);
}

Patient::~Patient()
{

}


QString Patient::patientString()
{
	QString qstr = "Patient of id " ;
	qstr.append(QString::number(identificationNumber));
	qstr.append(" name ");
	qstr.append(QString::fromStdString(name));
	qstr.append(" specie ");
	qstr.append(QString::number(sp));
	qstr.append("\n");
	return qstr;
}


