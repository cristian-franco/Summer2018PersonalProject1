#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("DnD Character Center");

    std::vector <int> stats;


    QWidget* buttonWidget = new QWidget;
    QVBoxLayout* layoutVert = new QVBoxLayout;
    QPushButton* buttonRandom = new QPushButton("Random");
    //QPushButton* buttonBarbarian = new QPushButton("Barbarian");
    //QPushButton* buttonBard = new QPushButton("Bard");
    //QPushButton* buttonDruid = new QPushButton("Druid");
    //QPushButton* buttonMonk = new QPushButton("Monk");
    //QPushButton* buttonPaladin = new QPushButton("Paladin");
    //QPushButton* buttonRanger = new QPushButton("Ranger");
    //QPushButton* buttonSorcerer = new QPushButton("Sorcerer");
    //QPushButton* buttonWarlock = new QPushButton("Warlock");



    layoutVert->addWidget(buttonRandom);
/*    layoutVert->addWidget(buttonBarbarian);
    layoutVert->addWidget(buttonBard);
    layoutVert->addWidget(buttonDruid);
    layoutVert->addWidget(buttonMonk);
    layoutVert->addWidget(buttonPaladin);
    layoutVert->addWidget(buttonRanger);
    layoutVert->addWidget(buttonSorcerer);
    layoutVert->addWidget(buttonWarlock)*/;
    buttonWidget->setLayout(layoutVert);

    QTextEdit* statDisplay = new QTextEdit();
    statDisplay->setObjectName("STATS");

    QWidget* mainWidget = new QWidget();
    QHBoxLayout* layoutHoriz = new QHBoxLayout();

    layoutHoriz->addWidget(buttonWidget);
    layoutHoriz->addWidget(statDisplay);

    mainWidget->setLayout(layoutHoriz);

    setCentralWidget(mainWidget);

    connect(buttonRandom, SIGNAL (clicked()), this, SLOT (gdStats()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gdStats() {

    //QTextStream cout(stdout);
    //cout << "Hello there" << endl;

    QList<QTextEdit *> text = centralWidget()->findChildren<QTextEdit *>();

//    cout << text.isEmpty() << endl;
//    cout << text.size() << endl;

    QTextEdit* disp = text.at(0);

    stats.clear();
    mods.clear();
    statsString.clear();
    modsString.clear();

    for (int i = 0; i < 6; i++) {
        int stat = rand() % 20 + 1;

        QString statString = QString::number(stat);

        //cout << i << " " << stat << endl;

        int mod = (stat / 2) - 5;

        QString modString = "(";
        if (mod > -1) {
            modString.append("+");
        }
        modString.append(QString::number(mod));
        modString.append(")");

        //cout << i <<  " " << modString << endl;

        statsString.push_back(statString);
        modsString.push_back(modString);

        stats.push_back(stat);
        mods.push_back(mod);
    }

    disp->setText("Stats:\n");

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

    disp->append(strengthLine);
    disp->append(dexterityLine);
    disp->append(constitutionLine);
    disp->append(intelligenceLine);
    disp->append(wisdomLine);
    disp->append(charismaLine);



//    QString nextStat = QString::number(stats.at(0));

//    disp->append(nextStat);

    //cout << "\nGeneral Kenobi" << endl;


}
