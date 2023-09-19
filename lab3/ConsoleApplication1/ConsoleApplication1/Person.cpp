#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;

class Person {

private:
    string name;
    string address;


public:

    Person() {}
    Person(string name, string address) : name(name), address(address) {}

    const string& GetName() const { return name; }
    const string& GetAddress() const { return address; }

    int CompareName(const string& namn) const {
        string lowerName = this->name;
        string lowerInputName = namn;

        std::transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        std::transform(lowerInputName.begin(), lowerInputName.end(), lowerInputName.begin(), ::tolower);

        return lowerName.compare(lowerInputName);
    }

    virtual void Print() const {
        if (name.compare("") != 0) {
            cout << "Name: " + name + " + Addy: " + address << endl;
        }
    }

    virtual ~Person() {}
};


class PersonMedTel : public Person {

private:
    string number;

public:
    PersonMedTel(const std::string& name, const std::string& address, const std::string& number)
        : Person(name, address), number(number) {}

    void Print() const override {
        Person::Print();
        std::cout << "Phone Number: " << number << std::endl;
    }

    ~PersonMedTel() {
    }

};
