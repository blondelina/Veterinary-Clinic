#include "Patient.h"
#include <vector>
using namespace std;


// Class used for storing Patient objects
class PatientRepository
{
private:
	/** current repository */
	vector<Patient*> repo;

	/** vector used for the undo() method */
	vector<Patient*> repo_copy;

	/** vector used for the redo() method */
	vector<Patient*> repo_redo;

public:

	PatientRepository();
	~PatientRepository();
	void add(Patient* p);
	int remove(int nr);
	Patient* getPatientAtIndex(int index);
	void loadData();
	void saveData();
	void remember();
	void undo();
	void remember_redo();
	void redo();
	QString display_repo(vector<Patient*>r);
	vector<Patient*> filtering_by_specie(int n);
	vector<Patient*> filtering_birds(bool n);
	vector<Patient*> get_repo();


};
