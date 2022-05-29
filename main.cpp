#include <iostream>
#include <fstream>
#include "person.h"
#include "linkedList.h"
#include <unordered_map>
using namespace std;


person* createNewPerson(string name, int age);
void addToMap(unordered_map<char, linkedList> &x, char a);

int main() {
    string name;
    int age;
    char c1 = 'A';

    unordered_map<char, linkedList> mapOfPeople;
    while(c1 <= 'Z')                                                    /// fills the list with pre-made listElements
    {                                                                   /// where their chars are already set with each
        addToMap(mapOfPeople, c1);
        c1++;
    }

    //////////////////////////////////////////// File Opened ////////////////////////////////////////////
    ifstream file;
    file.open("people.txt");

    while(!file.eof())                      /// this block of code creates a person object for each person in the file,
    {                                       /// and then takes the first letter of their name and checks to see if a
        file >> name;                       /// linked list has been started yet for that letter in the map
        file >> age;

        person *p = createNewPerson(name, age);
        char firstLetter = toupper(name[0]);

        if(mapOfPeople[firstLetter].getHead() == nullptr && mapOfPeople[firstLetter].getTail() == nullptr)
        {
            mapOfPeople[firstLetter].startList(p);
        }
        else
        {
            mapOfPeople[firstLetter].addPerson(p);
        }
    }
    file.close();
    //////////////////////////////////////////// File Closed ////////////////////////////////////////////

    char c2 = 'A';
    while(c2 <= 'Z')                                                    /// This displays all the people from the map
    {
        cout << "---" << "Names starting with " << c2 << "---" << endl;

        mapOfPeople[c2].displayList();
        cout << endl << endl;

        c2++;
    }

    return 0;
}

person* createNewPerson(string name, int age){                              /// creates a new person object and adds
    person *p = new(person);                                                /// the appropriate name and age
    p->setNameAndAge(name, age);
    return p;
}

void addToMap(unordered_map<char, linkedList> &x, char a){                  /// takes char and creates a linkedList and
    linkedList l;                                                           /// then adds them to the map
    x.insert({a, l});
}
