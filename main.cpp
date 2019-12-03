#include <QDebug>

#include <QApplication>
#include <QLoggingCategory>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLoggingCategory::setFilterRules("*.debug=true\n"
                                     "qt.qpa.input*=false\n"
                                     "qt.widgets*=false");
    new Game();
    return a.exec();
}
