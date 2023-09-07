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
            int comparisonResult = currentPerson.CompareName(personToAdd->GetName());

            if (comparisonResult >= 0) {
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
                return const_cast<Person*>(&currentPerson); //const_cast removes the const adjective, so i can modify or delete person
            }
        }

        return nullptr;

    }
    
    Person* SearchByName(const string& namn, const Person* person) const {
        if (currSize == 0) {
            return nullptr;
        }

        for (vector<Person>::const_iterator it = personRegistry.begin(); it != personRegistry.end(); ++it) {
            const Person& currentPerson = *it;
            if (currentPerson.CompareName(namn) == 0) {
                return const_cast<Person*>(&currentPerson); //const_cast removes the const adjective, so i can modify or delete person
            }
        }

        return nullptr;

    }

    void RemoveEntry(Person* ptr) {
        
        //"->" to use method from a pointer
        string& name = ptr->GetName();

        //dereferencing pointer to get name, then referencing again by sending as an argument.
        Person* personToDelete = SearchByName(name);

        //delete person if exists
        if (personToDelete != nullptr) {
            delete personToDelete;
        }
    
    }

    void Print() const {

        for (vector<Person>::const_iterator it = personRegistry.begin(); it != personRegistry.end(); ++it) {
            const Person& currentPerson = *it;
            currentPerson.Print();
            
        }
        
    }

    void ClearRegistry() {
        personRegistry.clear();
    }

    ~PersonReg() {
        ClearRegistry();
    }

};