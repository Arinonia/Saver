#include "mainwindow.h"
#include <QApplication>
#include <QTextEdit>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <saver.h>
#include <iostream>
QString qStrindToStdString (std::string str);

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QTextEdit zoneTexte; zoneTexte.setGeometry(100,100,400,200);

    QString texte;
    QFile file("test.dat");
    Saver saver(file);
    saver.put("pseudo", "arinonia");
    saver.put("password", "0000");
    saver.put("rank", "administrateur");
    zoneTexte.setText(qStrindToStdString(saver.get("pseudo")) + "\n" + qStrindToStdString(saver.get("password")) + "\n" + qStrindToStdString(saver.get("rank")));
    zoneTexte.show();
    return a.exec();
}

QString qStrindToStdString (std::string str){
    return QString::fromStdString(str);
}
