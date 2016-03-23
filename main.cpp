#include <QApplication>
#include <QMessageBox>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMessageBox msgbx;
    msgbx.setText("Begin?");
    msgbx.addButton(QMessageBox::No);
    msgbx.addButton(QMessageBox::Yes);
    int ret = msgbx.exec();
    if (ret == QMessageBox::No)
        return 0;

    Game   game;

    return a.exec();
}
