#include "Controller.h"
#include <iostream>
using namespace std;

//Controller constructor
Controller::Controller()
{
}

//Controller destructor
Controller::~Controller()
{

}

//Controller method for adding a patient
void Controller::addPatient(Patient* p)
{
	try
	{
		repo.remember();
		repo.add(p);

	}
	catch (exception)
	{
		throw exception();
	}


}

//Controller method for removing a patient
void Controller::deletePatient(int nr)
{
	try
	{
		repo.remember();
		
		if (repo.remove(nr) == -1)
			throw exception();

	}
	catch (exception)
	{
		throw exception();
	}

}

//Controller method for loading data from the .csv file
void Controller::load()
{
	repo.loadData();
}

//Controller method for saving data into the .csv file
void Controller::save()
{
	repo.saveData();

}


//Controller method for the undo operation
void Controller::undo()
{
	try
	{
		repo.remember_redo();
		repo.undo();
	}
	catch (exception)
	{
		throw exception();

	}


}

//Controller method for the redo operation
void Controller::redo()
{
	try
	{
		repo.redo();
	}
	catch (exception)
	{
		throw exception();
	}

}

//Controller method for the filtering by spicie operation
QString Controller::filter_by_specie(int n)
{
	try
	{
		return repo.display_repo(repo.filtering_by_specie(n));
	}
	catch (exception)
	{
		throw exception();
	}
}

//Controller method for the filtering birds operation
QString Controller::filter_birds(int n)
{
	bool m;
	if (n == 1)
		m = false;
	else if (n == 2)
		m = true;
	
	else
	{
		throw exception();
	}


	try
	{
		return repo.display_repo(repo.filtering_birds(m));
		
	}
	catch (exception)
	{
		throw exception();

	}


}

//Controller method for displaying the repository
QString Controller::displayed_repo()
{
	return repo.display_repo(repo.get_repo());

}