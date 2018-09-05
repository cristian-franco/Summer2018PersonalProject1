#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;
        QWidget* mainWidget;
        QWidget* buttonWidget;
        QHBoxLayout* layoutHoriz;
        QVBoxLayout* layoutVert;
        QPushButton* buttonRandom;
        QTextEdit* statDisplay;



};

#endif // MAINWINDOW_H
