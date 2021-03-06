#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QKeyEvent>
#include "ui_mainwindow.h"

class TeamManager;
class TimeBar;
class CmdLineBar;
class ResultPrinter;
class XmlHandler;
class BestRoundBar;
class LastRoundBar;

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static MainWindow * getInstance() {
            return instance;
    }

    void setStatusMsg(const char *);
    TimeBar * getTimeBar() { return timebar; }
    TeamManager * getTeamManager() { return manager; }
    CmdLineBar * getCmdline() { return cmdline; }
    ResultPrinter * getPrinter() { return printer; }
    XmlHandler * getXmlHandler() { return xml_handler; }
    BestRoundBar * getBestRoundBar() { return bestround_bar; }
    LastRoundBar * getLastRoundBar() { return lastround_bar; }

private:
    static MainWindow * instance;
    TimeBar * timebar;
    TeamManager * manager;
    CmdLineBar * cmdline;
    ResultPrinter * printer;
    XmlHandler * xml_handler;
    BestRoundBar * bestround_bar;
    LastRoundBar * lastround_bar;

protected:
    void closeEvent(QCloseEvent *);
    void mousePressEvent(QMouseEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

public slots:

private slots:
    void run();

    void printBestByRoundsDesc();
    void printBestByRoundsAsc();
    void printBestByTimeDesc();
    void printBestByTimeAsc();

    void printByRoundsDesc();
    void printByRoundsAsc();
    void printByTimeDesc();
    void printByTimeAsc();

    void printByTeam();


    void xmlexport();
    void xmlimport();

signals:

};

#endif // MAINWINDOW_H
