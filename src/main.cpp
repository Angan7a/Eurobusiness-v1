#include <iostream>
#include "Eurobusiness.hpp"

//int main()
//{
//    std::cout << "Eurobusiness!" << std::endl;
 //   Eurobusiness(2);
 //   return 0;
//}
#include <QApplication>

int main(int argc, char *argv[])
{

    std::cout << "Eurobusiness!" << std::endl;
    QApplication a(argc, argv);
    Eurobusiness e(5);
    e.show();
    return a.exec();
}
