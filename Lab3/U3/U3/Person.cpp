#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Person{

    private:
        string name;
        string address;
        

    public:
    
        Person(string name, string address) : name(name), address(address){}

        string& GetName() const { return const_cast<string&>(name); }

        int CompareName(const string& namn) const {
            return name.compare(this->name);
        }

        void Print() const {
            cout << "Name: " + name + " + Addy: " + address << endl;
        }
};