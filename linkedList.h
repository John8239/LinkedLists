#ifndef LINKEDLISTS_LINKEDLIST_H
#define LINKEDLISTS_LINKEDLIST_H
#include "person.h"


class linkedList {
    private:
        person *head;
        person *tail;
    public:
        linkedList(){
            this->head = nullptr;
            this->tail = nullptr;
        }

        void startList(person *&p){
            this->head = p;
            this->tail = p;
        }

        void addPerson(person *&p){
            if(this->head->getNextPerson() == nullptr)              /// checks to see if the list only has one element
            {
                if(p->getName() > this->head->getName())
                {
                    this->tail = p;
                    this->head->setNextPerson(p);
                }
                else
                {
                    this->head = p;
                    head->setNextPerson(tail);
                }
            }
            else if(this->head->getNextPerson() == this->tail)      /// checks to see if list only has two elements
            {
                person *current = this->head;
                if(p->getName() < current->getName())               /// checks to see if p < head
                {
                    this->head = p;
                    this->head->setNextPerson(current);
                }
                else if(p->getName() > current->getName() && p->getName() < tail->getName()) /// if p > head but less
                {                                                                            /// than tail
                    this->head->setNextPerson(p);
                    p->setNextPerson(this->tail);
                }
                else                                                /// else tail's next person is p and then p is set
                {                                                   /// to tail
                    this->tail->setNextPerson(p);
                    this->tail = p;
                }
            }
            else                                                    /// otherwise...
            {
                person *current = this->head;
                if(p->getName() < this->head->getName())            /// if p < head
                {
                    this->head = p;
                    p->setNextPerson(current);
                }
                else
                {
                    while(current != nullptr)                       /// else, iterate through list
                    {
                        if(current->getNextPerson() == nullptr)
                        {
                            current->setNextPerson(p);
                            this->tail = p;
                            break;
                        }
                        else if(p->getName() > current->getName() && p->getName() < current->getNextPerson()->getName())
                        {
                            p->setNextPerson(current->getNextPerson());
                            current->setNextPerson(p);
                            break;
                        }
                        else
                        {
                            current = current->getNextPerson();
                        }
                    }
                }
            }
        }

        void displayList(){
            person *current = this->head;
            while(current != nullptr)
            {
                cout << "Name: " << current->getName() << endl << "Age: " << current->getAge() << endl << endl;
                current = current->getNextPerson();
            }
        }

        person* getHead(){
            return this->head;
        }

        person* getTail(){
            return this->tail;
        }

        string getHeadName(){
            return this->head->getName();
        }
};


#endif //LINKEDLISTS_LINKEDLIST_H
