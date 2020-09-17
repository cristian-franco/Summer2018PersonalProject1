#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QLabel>

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
        //QTextEdit* statDisplay;

    private:
        Ui::MainWindow *ui;
        QWidget* mainWidget;
        //QWidget* buttonWidget;
        //QHBoxLayout* layoutHoriz;
        //QVBoxLayout* layoutVert;
        //QPushButton* buttonRandom;
        QLabel* statDisplay;

        std::vector <int> specRaceMods, specClassMods;


        std::vector <int> stats, mods, classMods;
        std::vector <QString> statsString, modsString;

        std::vector<int> generateStats();
        std::vector<int> createMods(std::vector<int> stats);

        QString createDisplayString(std::vector<QString> statsString, std::vector<QString> modsString);
        QString createModsString(std::vector <int> mods, int g);



    private slots:
        void randomSlot();
        void barbarianSlot();
        void bardSlot();
        void druidSlot();
        void monkSlot();
        void paladinSlot();
        void rangerSlot();
        void sorcererSlot();
        void warlockSlot();




};

#endif // MAINWINDOW_H
