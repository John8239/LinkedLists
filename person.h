#ifndef LINKEDLISTS_PERSON_H
#define LINKEDLISTS_PERSON_H
#include <iostream>
using namespace std;

class person {
    private:
        string name;
        int age;
        person *nextPerson;
    public:
        person(){this->name = ""; this->age = 0; this->nextPerson = nullptr;}
        person(string n, int a){this->name = n; this->age = a; this->nextPerson = nullptr;}
        void setName(string n) {this->name = n;}
        void setAge(int a) {this->age = a;}
        void setNameAndAge(string n, int a) {this->name = n; this->age = a;}
        void setNextPerson(person *p) {this->nextPerson = p;}
        string getName(){return this->name;}
        int getAge() {return this->age;}
        person* getNextPerson() {return this->nextPerson;}
};


#endif //LINKEDLISTS_PERSON_H
