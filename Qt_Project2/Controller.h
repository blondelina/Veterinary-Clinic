#pragma once
#include <vector>
#include "PatientRepository.h"

/// controller class for PatientRepository
class Controller
{
private:
	PatientRepository repo;
public:

	Controller();
	~Controller();
	void addPatient(Patient* p);
	void deletePatient(int nr);
	void load();
	void save();
	void remember();
	void undo();
	void redo();
	QString filter_by_specie(int n);
	QString filter_birds(int n);
	QString displayed_repo();



};
