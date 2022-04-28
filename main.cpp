//#include <QCoreApplication>
#include "stack.h"
#include <iostream>
#include <cstring>
#include <locale.h>
#include <stdlib.h>
#include "person_keeper.h"
using namespace std;

int main()
{


 Stack<int> st1;
 Stack<float> st2;
 Stack<string> st3;
for(int i = 0;i<20;i++)
{
    st1.Push(i);
}
st1.Pop();
cout<<st1.Size()<<endl;
cout << "Sortie de valeurs int"<< endl;
st1.Print([&](const int &k){
        cout<<k<<" ";
    });
cout<< endl;
for (int i = 0; i < 10; ++i) {
    st2.Push(0.001*rand()/10);
}

cout << "Sortie de valeurs float"<< endl;
st2.Print([&](const float &k){
        cout<<k<<" ";
    });
string s1="Sortie de", s2="valeurs",s3="string";
cout << endl;
st3.Push(s3);
st3.Push(s2);
st3.Push(s1);
st3.Print([&](const string &k){
        cout<<k<<" ";
    });
cout <<endl;

PersonKeeper &person(PersonKeeper::Instance());
   QString path1 = "ReadPerson.txt";
   QString path2 = "WritePerson.txt";
   person.Clear(); // удаляем имена
   person.ReadPersons(path1); // считываем имена из файла
   person.WritePersons(path2); // записываем имена в файл
    return 0;
}

//int main(int argc, char *argv[])
//{
  //  QCoreApplication a(argc, argv);
//
  //  return a.exec();
//}
