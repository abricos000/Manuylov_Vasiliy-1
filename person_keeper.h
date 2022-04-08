#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H
#include <QString>
#include "stack.h"
#include "person.h"

class PersonKeeper
{
private:
    PersonKeeper(){}
    PersonKeeper(const PersonKeeper &);
    ~PersonKeeper(){}
    PersonKeeper &operator=(const PersonKeeper &);
    Stack<Person> s;
public:
    static PersonKeeper &Instance();
    void ReadPersons(QString path);
    void WritePersons(QString path) const;
    int Size();
    void Clear();

};



#endif // PERSON_KEEPER_H



