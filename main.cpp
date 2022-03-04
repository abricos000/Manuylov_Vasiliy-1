//#include <QCoreApplication>
#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
 Stack<int> st;
for(int i = 0;i<10;i++)
{
    st.Push(i);
}
st.Pop();
cout<<st.Size()<<endl;
    return 0;
}

//int main(int argc, char *argv[])
//{
  //  QCoreApplication a(argc, argv);
//
  //  return a.exec();
//}
