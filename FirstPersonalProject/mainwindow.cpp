#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("DnD Character Center");

    //std::vector <int> stats;

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

    QPlainTextEdit* statDisplay = new QPlainTextEdit();
    statDisplay->setObjectName("STATS");

    QWidget* mainWidget = new QWidget();
    QHBoxLayout* layoutHoriz = new QHBoxLayout();

    layoutHoriz->addWidget(buttonWidget);
    layoutHoriz->addWidget(statDisplay);

    mainWidget->setLayout(layoutHoriz);

    setCentralWidget(mainWidget);

    // connect all button signals to same slot that will take argument and generate stats
    connect(buttonRandom, SIGNAL (clicked()), this, SLOT (randomSlot()));
//    connect(buttonBarbarian, SIGNAL (clicked()), this, SLOT (createMods()));
//    connect(buttonBard, SIGNAL (clicked()), this, SLOT (createMods()));
//    connect(buttonDruid, SIGNAL (clicked()), this, SLOT (createMods()));
//    connect(buttonMonk, SIGNAL (clicked()), this, SLOT (createMods()));
//    connect(buttonPaladin, SIGNAL (clicked()), this, SLOT (createMods()));
//    connect(buttonRanger, SIGNAL (clicked()), this, SLOT (createMods()));
//    connect(buttonSorcerer, SIGNAL (clicked()), this, SLOT (createMods()));
//    connect(buttonWarlock, SIGNAL (clicked()), this, SLOT (createMods()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::randomSlot() {

    // findChildren returns a QList of type in <>
    // findChild will return a single object of type in <>
    QPlainTextEdit* disp = centralWidget()->findChild<QPlainTextEdit *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();

    vector<int> stats = generateStats();
    createMods(stats);

    disp->setPlainText("Stats:\n");

    QString strengthLine = "STR  |  ";
    strengthLine.append(statsString.at(0));
    strengthLine.append(" ");
    strengthLine.append(modsString.at(0));

    QString dexterityLine = "DEX  |  ";
    dexterityLine.append(statsString.at(1));
    dexterityLine.append(" ");
    dexterityLine.append(modsString.at(1));

    QString constitutionLine = "CON |  ";
    constitutionLine.append(statsString.at(2));
    constitutionLine.append(" ");
    constitutionLine.append(modsString.at(2));

    QString intelligenceLine = "INT   |  ";
    intelligenceLine.append(statsString.at(3));
    intelligenceLine.append(" ");
    intelligenceLine.append(modsString.at(3));

    QString wisdomLine = "WIS  |  ";
    wisdomLine.append(statsString.at(4));
    wisdomLine.append(" ");
    wisdomLine.append(modsString.at(4));

    QString charismaLine = "CHA |  ";
    charismaLine.append(statsString.at(5));
    charismaLine.append(" ");
    charismaLine.append(modsString.at(5));

    disp->appendPlainText(strengthLine);
    disp->appendPlainText(dexterityLine);
    disp->appendPlainText(constitutionLine);
    disp->appendPlainText(intelligenceLine);
    disp->appendPlainText(wisdomLine);
    disp->appendPlainText(charismaLine);
}

//void MainWindow::createMods() {

//}

//void MainWindow::createMods() {

//}

//void MainWindow::createMods() {

//}

// HELPER FUNCTION
// default stat generation function
// only generate vector int of stats
// modifiers calculated in slots
vector<int> generateStats() {

    for (int i = 0; i < 6; i++) {

        // new way, roll 4d6, remove smallest number
        std::vector <int> tempStat;
        int tempVal;
        for (int j = 0; j < 4; j++) {
            tempVal = rand() % 6 + 1;
            tempStat.push_back(tempVal);
        }

        // remove lowest value, index 0, after sorting
        std::sort(tempStat.begin(), tempStat.begin() + 4);
        tempStat.erase(tempStat.begin());

        int stat = 0;
        for (int x = 0; x < tempStat.size(); x++) {
            stat += tempStat.at(x);
        }

        QString statString = QString::number(stat);

        int mod = (stat / 2) - 5;

        QString modString = "(";
        if (mod > -1) {
            modString.append("+");
        }
        modString.append(QString::number(mod));
        modString.append(")");

        statsString.push_back(statString);
        modsString.push_back(modString);

        stats.push_back(stat);
        mods.push_back(mod);
    }
}

// HELPER FUNCTION
// Setup the strings to append to display
vector<int> createMods() {

}

