/********************************************************************************
** Form generated from reading UI file 'filtros.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTROS_H
#define UI_FILTROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Filtros
{
public:

    void setupUi(QWidget *Filtros)
    {
        if (Filtros->objectName().isEmpty())
            Filtros->setObjectName("Filtros");
        Filtros->resize(800, 600);

        retranslateUi(Filtros);

        QMetaObject::connectSlotsByName(Filtros);
    } // setupUi

    void retranslateUi(QWidget *Filtros)
    {
        Filtros->setWindowTitle(QCoreApplication::translate("Filtros", "Filtros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Filtros: public Ui_Filtros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTROS_H
