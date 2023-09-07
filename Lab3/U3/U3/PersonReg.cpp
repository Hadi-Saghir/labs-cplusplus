#include "Person.cpp"

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector; 

class person;

class PersonReg{

    private:
    const int maxSize;
    int currSize = 0;
    vector<Person> personRegistry;
    

    public:
    
    PersonReg(int maxSize) : maxSize(maxSize)
    {
       
    }

    bool AddPerson(const Person* const personToAdd){ //pointer personToAdd

        if (currSize >= maxSize) {
            return false;
        }

        for (vector<Person>::iterator it = personRegistry.begin(); it != personRegistry.end(); it++)
        {
            const Person& currentPerson = *it; //reference to current person
            bool greaterAlphabeticalOrder = currentPerson.CompareOrderName(personToAdd);

            if (greaterAlphabeticalOrder = false) {
                personRegistry.insert(it, *personToAdd); //dereference pointer to personToAdd
                return true;
            }
        }

        personRegistry.push_back(*personToAdd); // add last
        return true; 

    }

    bool AddTestPerson(const string& name, const string& address) {

        if (currSize >= maxSize) {
            return false;
        }

        Person personToAdd = Person(name, address);


        return AddPerson(&personToAdd); //reference person

    }

    Person* SearchByName(const string& namn) const {
        if (currSize == 0) {
            return nullptr;
        }
        
        for (vector<Person>::const_iterator it = personRegistry.begin(); it != personRegistry.end(); ++it) {
            const Person& currentPerson = *it; 
            if (currentPerson.CompareName(namn) == 0) {
                return const_cast<Person*>(&currentPerson);
            }
        }

        return nullptr;

    }

    void RemoveEntry(Person* ptr) {

        

    
    }
};