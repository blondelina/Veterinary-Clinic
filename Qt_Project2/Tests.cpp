#include "Patient.h"
#include "Bird.h"
#include "Cat.h"
#include "Dog.h"
#include "PatientRepository.h"
#include<assert.h>


void tests_patient()
{

	Patient p1(1, "patient1", 1);
	Patient p2(2, "patient2", 2);
	Patient p3(3, "patient3", 3);
	/// tests setters and getters
	p1.setIdNr(10); p2.setIdNr(11); p3.setIdNr(12);
	assert(p1.getIdNr() == 10);
	assert(p2.getIdNr() == 11);
	assert(p3.getIdNr() == 12);

	p1.setName("p1"); p2.setName("p2"); p3.setName("p3");
	assert(p1.getName() == "p1");
	assert(p2.getName() == "p2");
	assert(p3.getName() == "p3");

	p1.setSpecie(specie(3)); p2.setSpecie(specie(1)); p3.setSpecie(specie(2));
	assert(p1.getSpecie() == 3);
	assert(p2.getSpecie() == 1);
	assert(p3.getSpecie() == 2);



}

void tests_bird()
{
	Bird b1(1, "b1", 2, 1);
	Bird b2(2, "b2", 2, 0);
	Bird b3(3, "b3", 2, 1);

	/// tests can_fly setters and getters
	b1.setFlyAbility(false); b2.setFlyAbility(true); b3.setFlyAbility(false);
	assert(b1.getFlyAbility() == 0);
	assert(b2.getFlyAbility() == 1);
	assert(b3.getFlyAbility() == 0);

}

void tests_repository()
{

	PatientRepository repo;

	/// tests add
	Patient* p1 = new Patient(1, "patient1", 1);
	repo.add(p1);
	assert(repo.getPatientAtIndex(0)->getIdNr() == p1->getIdNr());
	assert(repo.getPatientAtIndex(0)->getName() == p1->getName());
	assert(repo.getPatientAtIndex(0)->getSpecie() == p1->getSpecie());

	try
	{
		Patient* p2 = new Patient(1, "patient1", 1);
		repo.add(p2);


	}
	catch (exception)
	{
		Patient* p2 = new Patient(10, "patient1", 1);
		repo.add(p2);
		assert(repo.getPatientAtIndex(1)->getIdNr() == p2->getIdNr());
		assert(repo.getPatientAtIndex(1)->getName() == p2->getName());
		assert(repo.getPatientAtIndex(1)->getSpecie() == p2->getSpecie());

		repo.remove(10);

	}

	Bird* b1 = new Bird(2, "b1", 2, 1);
	repo.add(b1);
	assert(repo.getPatientAtIndex(1)->getIdNr() == b1->getIdNr());
	assert(repo.getPatientAtIndex(1)->getName() == b1->getName());
	assert(repo.getPatientAtIndex(1)->getSpecie() == b1->getSpecie());
	assert(dynamic_cast<Bird*>(repo.getPatientAtIndex(1))->getFlyAbility() == b1->getFlyAbility());

	Cat* c1 = new Cat(3, "c1", 1);
	repo.add(c1);
	assert(repo.getPatientAtIndex(2)->getIdNr() == c1->getIdNr());
	assert(repo.getPatientAtIndex(2)->getName() == c1->getName());
	assert(repo.getPatientAtIndex(2)->getSpecie() == c1->getSpecie());

	Dog* d1 = new Dog(4, "d1", 3);
	repo.add(d1);
	assert(repo.getPatientAtIndex(3)->getIdNr() == d1->getIdNr());
	assert(repo.getPatientAtIndex(3)->getName() == d1->getName());
	assert(repo.getPatientAtIndex(3)->getSpecie() == d1->getSpecie());



	/// tests remove
	repo.remove(1);
	assert(repo.getPatientAtIndex(0)->getIdNr() == b1->getIdNr());
	assert(repo.getPatientAtIndex(0)->getName() == b1->getName());
	assert(repo.getPatientAtIndex(0)->getSpecie() == b1->getSpecie());


	repo.remember();
	repo.remove(3);
	assert(repo.getPatientAtIndex(1)->getIdNr() == d1->getIdNr());
	assert(repo.getPatientAtIndex(1)->getName() == d1->getName());
	assert(repo.getPatientAtIndex(1)->getSpecie() == d1->getSpecie());


	/// tests undo and redo
	repo.remember_redo();
	repo.undo();
	assert(repo.getPatientAtIndex(1)->getIdNr() == c1->getIdNr());
	assert(repo.getPatientAtIndex(1)->getName() == c1->getName());
	assert(repo.getPatientAtIndex(1)->getSpecie() == c1->getSpecie());

	repo.redo();
	assert(repo.getPatientAtIndex(1)->getIdNr() == d1->getIdNr());
	assert(repo.getPatientAtIndex(1)->getName() == d1->getName());
	assert(repo.getPatientAtIndex(1)->getSpecie() == d1->getSpecie());

	repo.undo();
	assert(repo.getPatientAtIndex(1)->getIdNr() == c1->getIdNr());
	assert(repo.getPatientAtIndex(1)->getName() == c1->getName());
	assert(repo.getPatientAtIndex(1)->getSpecie() == c1->getSpecie());


	/// tests filter by specie
	for (int i = 0; i < repo.filtering_by_specie(1).size(); i++)
		assert(repo.filtering_by_specie(1)[i]->getSpecie() == 1);

	for (int i = 0; i < repo.filtering_by_specie(2).size(); i++)
		assert(repo.filtering_by_specie(2)[i]->getSpecie() == 2);

	for (int i = 0; i < repo.filtering_by_specie(3).size(); i++)
		assert(repo.filtering_by_specie(3)[i]->getSpecie() == 3);


	/// tests filter birds by flying
	try
	{
		repo.filtering_birds(5).size();
	}
	catch (exception) {};

	Bird* b3 = new Bird(142, "b1", 2, 1);
	repo.add(b3);

	try {
		for (int i = 0; i < repo.filtering_birds(true).size(); i++)
		{
			assert(repo.filtering_birds(true)[i]->getSpecie() == 2);
			assert(dynamic_cast<Bird*>(repo.filtering_birds(true)[i])->getFlyAbility() == false);
		}
	}
	catch
		(exception) {
	};

	for (int i = 0; i < repo.filtering_birds(false).size(); i++)
	{
		assert(repo.filtering_birds(false)[i]->getSpecie() == 2);
		assert(dynamic_cast<Bird*>(repo.filtering_birds(false)[i])->getFlyAbility() == true);
	}
}

void run_tests()
{
	tests_patient();
	tests_bird();
	tests_repository();
}