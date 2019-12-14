#include <QDebug>

#include <QApplication>
#include <QLoggingCategory>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLoggingCategory::setFilterRules("*.debug=true\n"
                                     "qt.qpa*=false\n"
                                     "qt.accessibility*=false\n"
                                     "qt.text*=false\n"
                                     "qt.widgets*=false");
    try {
        new Game();
    } catch (QString e) {
        qDebug() << e;
    }

    return a.exec();
}
