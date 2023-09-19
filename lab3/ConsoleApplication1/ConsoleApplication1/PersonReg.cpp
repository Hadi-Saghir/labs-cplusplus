#include "Person.cpp"

#include <iostream>
#include <string>

using std::string;


class person;

class PersonReg {

private:
    const int maxSize;
    int currSize = 0;
    Person* personRegistry;


public:

    PersonReg(int maxSize) : maxSize(maxSize) {
        personRegistry = new Person[maxSize];
    }

    bool AddPerson(const Person* const personToAdd) { //pointer personToAdd

        if (currSize >= maxSize) {
            return false;
        }

        if (currSize == 0) {
            personRegistry[0] = *personToAdd;
            currSize++;
            return true;
        }

        for (Person* ptr = personRegistry; ptr != personRegistry + currSize; ++ptr) {

            const Person& currentPerson = *ptr;
            int comparisonResult = currentPerson.CompareName(personToAdd->GetName());
            

            //find alphabetically greater
            if (comparisonResult >= 0) {
                //shift one right
                for (Person* shift = (personRegistry + currSize); shift != ptr; --shift) {
                    *shift = *(shift - 1);
                }
                *ptr = *personToAdd;
                currSize++;
                return true;
            }

            // If we've reached the end 
            if (ptr == personRegistry + currSize - 1) {
                personRegistry[currSize] = *personToAdd;
                currSize++;
                return true;
            }

        }

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

        for (Person* ptr = personRegistry; ptr != personRegistry + currSize; ++ptr) {
            if (ptr->CompareName(namn) == 0) {
                return ptr;
            }
        }

        return nullptr;

    }

    Person* SearchByName(const string& name, const Person* startOnNext) const {
        if (currSize == 0) {
            return nullptr;
        }

        const Person* startPtr = (startOnNext == nullptr) ? personRegistry : startOnNext + 1;

        for (const Person* ptr = startPtr; ptr != personRegistry + currSize; ++ptr) {
            if (ptr->CompareName(name) == 0) {
                return const_cast<Person*>(ptr);
            }
        }

        return nullptr;

    }

    void RemoveEntry(Person* ptr) {

        if (currSize == 0) {
            return;
        }

        const std::string& name = ptr->GetName();

        //find element
        for (Person* ptr = personRegistry; ptr != personRegistry + currSize; ++ptr) {
            if (ptr->CompareName(name) == 0) {
                // Shift right one step
                for (Person* j = ptr; j != personRegistry + currSize - 1; ++j) {
                    *j = *(j + 1);
                }
                --currSize;
                return;
            }
        }

    }

    void Print() const {

        for (Person* ptr = personRegistry; ptr != personRegistry + currSize; ++ptr) {
            ptr->Print();
        }

    }

    void ClearRegistry() {
        for (Person* ptr = personRegistry; ptr != personRegistry + currSize; ++ptr) {
            *ptr = Person();
        }
        currSize = 0;
    }

    ~PersonReg() {
        ClearRegistry();
    }

};