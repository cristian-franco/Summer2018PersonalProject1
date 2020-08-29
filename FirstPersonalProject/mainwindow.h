#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>

#include <QTextStream>
#include <vector>
#include <algorithm>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        QTextEdit* statDisplay;

    private:
        Ui::MainWindow *ui;
        QWidget* mainWidget;
        QWidget* buttonWidget;
        QHBoxLayout* layoutHoriz;
        QVBoxLayout* layoutVert;
        QPushButton* buttonRandom;
        std::vector <int> stats, mods;
        std::vector <QString> statsString, modsString;



    public slots:
        void gdStats(const int);



};

#endif // MAINWINDOW_H
