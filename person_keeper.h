#ifndef PERSON_KEEPER_H
#define PERSON_KEEPER_H
#include <QString>
#include "stack.h"
#include "person.h"
#include <QTextStream>
#include <QFile>



//паттер Singleton
class PersonKeeper
{
private:
    PersonKeeper(){}// конструкторы по умолчанию
    PersonKeeper(const PersonKeeper &);//конструктор копирования
    ~PersonKeeper(){}//деструктор
    PersonKeeper &operator=(const PersonKeeper &);//оператор присовения
    Stack<Person> s;//имена
public:
    static PersonKeeper &Instance();// хранится единственный экземпляр класса
    void ReadPersons(QString path);//читаем файл
    void WritePersons(QString path) const;//запись файла
    int Size();//количество человек
    void Clear();//стереть человека

};


int PersonKeeper::Size()
{
    return s.Size();
}
void PersonKeeper::Clear()
{
    return s.Clear();
}

PersonKeeper &PersonKeeper::Instance()
{
    static PersonKeeper instance;
    return instance;
}

void PersonKeeper::ReadPersons(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//проверка, отрылся ли файл для чтения
    {
        throw "Файл не открыт";
    }
    QTextStream stream(&file);// поток текстовых данных файла
    QString l;//считывание в буфер строк
    while (stream.readLineInto(&l))
    { s.Push(Person(l));//добавляем человека
    }
    file.close();//закрываем файл
}


void PersonKeeper::WritePersons(QString path) const
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))// открываем файл для записи
    {
        throw "Файл не открыт";
    }
    QTextStream stream(&file);// поток текстовых данных файла
    s.Print([&](const Person &k)//перебор значения
    {
        stream << k.Get_l_name() << " " << k.Get_f_name() << " " << k.Get_p_name() << Qt::endl;//записываем человека в файл
    });
    file.close();//закрытие файла
}


#endif // PERSON_KEEPER_H



