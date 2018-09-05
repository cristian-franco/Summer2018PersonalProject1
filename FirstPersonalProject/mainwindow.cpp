#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* buttonWidget = new QWidget;
    QVBoxLayout* layoutVert = new QVBoxLayout;
    QPushButton* buttonRandom = new QPushButton("Random");
    QPushButton* buttonBarbarian = new QPushButton("Barbarian");
    QPushButton* buttonBard = new QPushButton("Bard");
    QPushButton* buttonDruid = new QPushButton("Druid");
    QPushButton* buttonMonk = new QPushButton("Monk");
    QPushButton* buttonPaladin = new QPushButton("Paladin");
    QPushButton* buttonRanger = new QPushButton("Ranger");
    QPushButton* buttonSorcerer = new QPushButton("Sorcerer");
    QPushButton* buttonWarlock = new QPushButton("Warlock");

    layoutVert->addWidget(buttonRandom);
    layoutVert->addWidget(buttonBarbarian);
    layoutVert->addWidget(buttonBard);
    layoutVert->addWidget(buttonDruid);
    layoutVert->addWidget(buttonMonk);
    layoutVert->addWidget(buttonPaladin);
    layoutVert->addWidget(buttonRanger);
    layoutVert->addWidget(buttonSorcerer);
    layoutVert->addWidget(buttonWarlock);
    buttonWidget->setLayout(layoutVert);

    QTextEdit* statDisplay = new QTextEdit;



    QWidget* mainWidget = new QWidget;
    QHBoxLayout* layoutHoriz = new QHBoxLayout;
    layoutHoriz->addWidget(buttonWidget);

    layoutHoriz->addWidget(statDisplay);

    mainWidget->setLayout(layoutHoriz);

    setCentralWidget(mainWidget);






}

MainWindow::~MainWindow()
{
    delete ui;
}
