#include "PatientRepository.h"
#include "Bird.h"
#include"Cat.h"
#include"Dog.h"
#include <fstream>
#include <iomanip>

/// Constructor for the PatientRepository class
PatientRepository::PatientRepository()
{

}

/// Destructor for the PatientRepository class
PatientRepository::~PatientRepository()
{
	for (int i = 0; i < repo.size(); i++)
		delete repo[i];

}

/// method used for adding a Patient( Cat, Dog or Bird ) in the repo vector
void PatientRepository::add(Patient* p)
{	/// throws an exception if the id is already in the repository
	for (int i = 0; i < repo.size(); i++)
		if (repo[i]->getIdNr() == p->getIdNr())
			throw exception();

	if (p->getSpecie() == 2)
	{
		
		Bird* bird = new Bird(p->getIdNr(), p->getName(), p->getSpecie(), dynamic_cast<Bird*>(p)->getFlyAbility());
		repo.push_back(bird);

	}
	else if (p->getSpecie() == 1)
	{
		Cat* cat = new Cat(p->getIdNr(), p->getName(), p->getSpecie());
		repo.push_back(cat);

	}
	else if (p->getSpecie() == 3)
	{
		Dog* dog = new Dog(p->getIdNr(), p->getName(), p->getSpecie());
		repo.push_back(dog);

	}

}


/// method used for removing a patient from the repo vector by id
int PatientRepository::remove(int nr)
{	/// throws an exception if the repo vector is empty
	if (repo.size() == 0)
		throw exception();
	for (int i = 0; i < repo.size(); i++)
		if (repo[i]->getIdNr() == nr)
		{
			repo.erase(repo.begin() + i);
			return i;
		}

	return -1;
}


/// method that returns a patient by index 
Patient* PatientRepository::getPatientAtIndex(int index)
{
	for (int i = 0; i < repo.size(); i++)
		if (i == index)
			return repo[i];
}


/// method used for loading the data from the .csv file
void PatientRepository::loadData()
{
	ifstream fin("rep.csv");
	int id;
	string name;
	int sp;
	char comma;
	bool fly;
	while (fin >> id)
	{

		fin >> comma;
		fin >> sp;
		fin >> comma;

		if (sp == 2)
		{
			fin >> fly;
			fin >> comma;
			fin >> name;

			Bird* b = new Bird(id, name, sp, fly);
			repo.push_back(b);
		}
		else if (sp == 1)
		{
			fin >> name;
			Cat* c = new Cat(id, name, sp);
			repo.push_back(c);
		}
		else if (sp == 3)
		{
			fin >> name;
			Dog* d = new Dog(id, name, sp);
			repo.push_back(d);
		}
		else {
			fin >> name;
			Patient* p = new Patient(id, name, sp);
			repo.push_back(p);
		}

	}

	fin.close();

}

/// method used for saving the data into the .csv file
void PatientRepository::saveData()
{
	ofstream fout("rep.csv");
	for (int i = 0; i < repo.size(); i++)
	{
		fout << repo[i]->getIdNr();
		fout << ",";
		fout << repo[i]->getSpecie();
		

		if (repo[i]->getSpecie() == 2)
		{
			fout << ",";
			fout << dynamic_cast<Bird*>(repo[i])->getFlyAbility();
		}

		fout << ",";
		fout << repo[i]->getName();
		fout << "\n";
	}
	fout.close();


}


/// method used for keeping the previous repository in repo_copy before a change happens so the undo() can be done 
void PatientRepository::remember()
{/// called before add() or remove() in the UI module

	repo_copy.clear();
	for (int i = 0; i < repo.size(); i++)
		repo_copy.push_back(repo[i]);

}

/// method for reversing a change in the repository
void PatientRepository::undo()
{	/// throws an exception if the vector used to remember the repository before the previous operation(repo_copy) is empty
	/// (no operation has been done)
	if (repo_copy.empty())
		throw exception();
	if (repo_copy == repo)
		throw exception();
	
	repo.clear();
	for (int i = 0; i < repo_copy.size(); i++)
		repo.push_back(repo_copy[i]);

	
}

/// method used for keeping the previous repository in repo_redo before undo() is done so that the redo() can be done
void PatientRepository::remember_redo()
{/// called before undo() in the Controller module

	/// throws an exception if the vector used to remember the repository before the previous operation(repo_copy) is empty
	/// (no operation has been done)
	if (repo_copy.empty())
		throw exception();
	if (repo_copy == repo)
		throw exception();
		
	repo_redo.clear();
	for (int i = 0; i < repo.size(); i++)
		repo_redo.push_back(repo[i]);
	

}

/// method for reversing an undo() operation in the repository
void PatientRepository::redo()
{
	/// throws an exception if repo_redo is empty (no undo has been done)
	if (repo_redo.empty())
		throw exception();
	repo.clear();
	for (int i = 0; i < repo_redo.size(); i++)
		repo.push_back(repo_redo[i]);

	repo_redo.clear();
}


/// method for displaying the repository
QString PatientRepository::display_repo(vector<Patient*>r)
{
	QString s="";
	for (int i = 0; i < r.size(); i++)
		s.append(r[i]->patientString());
	return s;
}

/// method that returns a filtered vector of objects having a given specie
vector<Patient*> PatientRepository::filtering_by_specie(int n)
{	///throws an exception if the given specie is not one of the three available
	if (n != 1 && n != 2 && n != 3)
		throw exception();
	vector<Patient*> fltr;
	for (int j = 0; j < repo.size(); j++)
		fltr.push_back(repo[j]);

	/// uses the lambda expression
	fltr.erase(remove_if(fltr.begin(), fltr.end(),
		[n](Patient* p) { return (p->getSpecie() != n); }), fltr.end());

	return fltr;
}

/// method that returns a filtered vector of birds with or without the ability to fly
vector<Patient*> PatientRepository::filtering_birds(bool n)
{
	int ok = 0;
	vector<Patient*> fltr;
	for (int j = 0; j < repo.size(); j++)
	{
		if (repo[j]->getSpecie() == 2)ok = 1;
		fltr.push_back(repo[j]);
	}

	fltr.erase(remove_if(fltr.begin(), fltr.end(),
		[n](Patient* p) { return (p->getSpecie() != 2 || (p->getSpecie() == 2 && dynamic_cast<Bird*>(p)->getFlyAbility() == n)); }), fltr.end());

	/// throws an exception if nothing was found
	if (fltr.size() == 0)
		throw exception();
	return fltr;
}


/// method that returns the vector containing the repository
vector<Patient*> PatientRepository::get_repo()
{
	return repo;
}
