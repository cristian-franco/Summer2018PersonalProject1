#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("DnD Character Center");
    setStyleSheet("QMainWindow {background: 'grey';}");

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

    //QPlainTextEdit* statDisplay = new QPlainTextEdit();
    //statDisplay->setObjectName("STATS");
    QLabel* statDisplay = new QLabel();
    statDisplay->setObjectName("STATS");
    statDisplay->setTextInteractionFlags(Qt::TextSelectableByMouse);

    QWidget* mainWidget = new QWidget();
    QHBoxLayout* layoutHoriz = new QHBoxLayout();

    layoutHoriz->addWidget(buttonWidget);
    layoutHoriz->addWidget(statDisplay);

    mainWidget->setLayout(layoutHoriz);

    setCentralWidget(mainWidget);

    // connect all button signals to same slot that will take argument and generate stats
    connect(buttonRandom, SIGNAL (clicked()), this, SLOT (randomSlot()));
    connect(buttonBarbarian, SIGNAL (clicked()), this, SLOT (barbarianSlot()));
    connect(buttonBard, SIGNAL (clicked()), this, SLOT (bardSlot()));
    connect(buttonDruid, SIGNAL (clicked()), this, SLOT (druidSlot()));
    connect(buttonMonk, SIGNAL (clicked()), this, SLOT (monkSlot()));
    connect(buttonPaladin, SIGNAL (clicked()), this, SLOT (paladinSlot()));
    connect(buttonRanger, SIGNAL (clicked()), this, SLOT (rangerSlot()));
    connect(buttonSorcerer, SIGNAL (clicked()), this, SLOT (sorcererSlot()));
    connect(buttonWarlock, SIGNAL (clicked()), this, SLOT (warlockSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// SLOTS

void MainWindow::randomSlot() {

    // findChildren returns a QList of type in <>
    // findChild will return a single object of type in <>
    //QPlainTextEdit* disp = centralWidget()->findChild<QPlainTextEdit *>("STATS");

    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();
    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {    

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    // label
    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::barbarianSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(10);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::bardSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(20);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::druidSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(30);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::monkSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(40);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::paladinSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(50);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::rangerSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(60);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::sorcererSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(70);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}

void MainWindow::warlockSlot() {
    QLabel* disp = centralWidget()->findChild<QLabel *>("STATS");

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();
    classMods.clear();

    std::vector<int> stats = generateStats();

    for (int b = 0; b < 6; b++) {
        classMods.push_back(80);
    }

    for (int c = 0; c < 6; c++) {
        stats.at(c) = stats.at(c) + classMods.at(c);
    }

    std::vector<int> mods = createMods(stats);

    for (int g = 0; g < 6; g++) {

        QString statString = QString::number(stats.at(g));
        QString modString = createModsString(mods, g);

        statsString.push_back(statString);
        modsString.push_back(modString);
    }

    QString finalString = createDisplayString(statsString, modsString);

    disp->setText(finalString);
}




// HELPER FUNCTION
// default stat generation function
// only generate vector int of stats
// modifiers calculated in slots
std::vector<int> MainWindow::generateStats() {
    std::vector<int> stats;

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

        stats.push_back(stat);
    }

    return stats;
}

// HELPER FUNCTION
// Setup the strings to append to display
std::vector<int> MainWindow::createMods(std::vector<int> stats) {
    std::vector<int> mods;
    int mod = 0;

    for (int i = 0; i < stats.size(); i++) {
        mod = (stats.at(i) / 2) - 5;
        mods.push_back(mod);
    }

    return mods;
}

// HELPER FUNCTION
// Turns mods vector into string
QString MainWindow::createModsString(std::vector <int> mods, int g) {

    QString modString = "(";
    if (mods.at(g) > -1) {
        modString.append("+");
    }
    modString.append(QString::number(mods.at(g)));
    modString.append(")");

    return modString;
}

// HELPER FUNCTION
// Creates string to put on the rightside label

QString MainWindow::createDisplayString(std::vector<QString> statsString, std::vector<QString> modsString) {
    QString finalString = "";

    finalString.append("Stats:\n");

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

    finalString.append(strengthLine);
    finalString.append("\n");
    finalString.append(dexterityLine);
    finalString.append("\n");
    finalString.append(constitutionLine);
    finalString.append("\n");
    finalString.append(intelligenceLine);
    finalString.append("\n");
    finalString.append(wisdomLine);
    finalString.append("\n");
    finalString.append(charismaLine);
    finalString.append("\n");

    return finalString;
}

