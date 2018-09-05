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
    QPushButton* buttonDwarf = new QPushButton("Dwarf");
    layoutVert->addWidget(buttonRandom);
    layoutVert->addWidget(buttonDwarf);
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
