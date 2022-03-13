#include "UI.h"
#include <QtWidgets/QApplication>
#include "Tests.h"

int main(int argc, char *argv[])
{
    run_tests();
    QApplication a(argc, argv);
    UI w;
    w.show();
    return a.exec();
}
