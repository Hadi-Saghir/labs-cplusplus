#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#include "PersonReg.cpp"

#if 1
#define PN(x) cout << x
#define DN(x) x
#define PD(x) cout << x
#else
#define PN(x)
#define DN(x)
#define PD(x) (x)
#endif

void Init(PersonReg& tr) {
    tr.ClearRegistry();
    PD(tr.AddTestPerson("olle", "0703955123"));
    PD(tr.AddTestPerson("olle", "123"));
    PD(tr.AddTestPerson("kurtke", "12345"));
    PD(tr.AddTestPerson("olle", "456"));
    PD(tr.AddTestPerson("sven", "456"));
    PD(tr.AddTestPerson("kurt", "95815"));
    PN(endl);
    PN(("fullt reg "));
    PN((endl));
    DN((tr.Print()));
}

#include <fstream>

using std::ifstream;

bool ReadReg(PersonReg& reg, string fileName) {
    string line;
    ifstream myfile(fileName);

    if (myfile.is_open())
    {
        Person* personPtr;

        while (getline(myfile, line))
        {
            while (line.length() == 0 && getline(myfile, line))
                ;
            string name(line);
            string address;
            getline(myfile, address);

            personPtr = new Person(name, address);

            reg.AddPerson(personPtr);
        }
        myfile.close();
        return true;
    }
    else {
        cout << "Unable to open file";
        return false;
    }
}

void Test1() {
    PersonReg reg(10);
    ReadReg(reg, "PersonExempel.txt");
    reg.Print(); cout << "\n\n";
    reg.ClearRegistry();
    reg.Print();
}

void Test2() {
    PersonReg reg(10);
    Init(reg);
    string namn, address;
    Person * tep;

    tep = reg.SearchByName("olle");
    if (tep) {
        cout << tep->GetAddress() << endl;
        reg.RemoveEntry(tep);
    }
    else
        cout << "not found \n";

    tep = reg.SearchByName("olle");
    if (tep) {
        cout << tep->GetAddress() << endl;
        reg.RemoveEntry(tep);
    }
    else
        cout << "not found \n";

    tep = reg.SearchByName("olle");
    if (tep) {
        cout << tep->GetAddress() << endl;
        reg.RemoveEntry(tep);
    }
    else
        cout << "not found \n";

    tep = reg.SearchByName("olle");
    if (tep) {
        cout << tep->GetAddress() << endl;
        reg.RemoveEntry(tep);
    }
    else
        cout << "not found \n";

    tep = reg.SearchByName("olle");
    if (tep) {
        cout << tep->GetAddress() << endl;
        reg.RemoveEntry(tep);
    }
    else
        cout << "not found \n";

    reg.Print();

    reg.ClearRegistry();
    reg.Print();
}

void Test3() {
    PersonReg reg(10);

    Init(reg);
    reg.Print();
    string namn, address;
    Person *tep;

    tep = nullptr;
    while (tep = reg.SearchByName("olle", tep)) {
        tep->Print();
                cout << tep->GetAddress() << endl;
    }
    cout << "not found \n";

    cout << "blandade sökningar \n";
    Person* ptr1 = nullptr, * ptr2 = nullptr;
    bool first = true;
    while (first || ptr1 || ptr2) {
        if (ptr1 || first) {
            ptr1 = reg.SearchByName("olle", ptr1);
            if (ptr1)
                ptr1->Print();
        }
        if (ptr2 || first) {
            ptr2 = reg.SearchByName("581", ptr2);
            if (ptr2)
                ptr2->Print();
        }
        first = false;
    }
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    std::locale::global(std::locale::locale("swedish"));
    PersonReg pr(5);
    Init(pr);
    Test1();
    Test2();
    Test3();
    std::cin.get();
}