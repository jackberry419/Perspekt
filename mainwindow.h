#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "Player.h"
#include "Exercise.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Exercise *exercise;
    Player *player;

private slots:
    void on_actionStart_Word_Excersice_triggered();

    void on_actionBack_to_main_menu_triggered();

    void on_actionStart_Verben_Excersice_triggered();

    void on_pushButton_verben_last_clicked();

    void on_pushButton_verben_next_clicked();

    void update_verben_text();

    void update_word_text();

    void on_actionQuit_triggered();

    void on_pushButton_hide_clicked();


    void on_pushButton_online_clicked();


    void on_actionKapitel_1_triggered();

    void on_actionKapitel_8_triggered();



    void on_actionKapitel_2_triggered();

    void on_actionKapitel_3_triggered();

    void on_actionKapitel_4_triggered();

    void on_actionKapitel_5_triggered();

    void on_actionKapitel_6_triggered();

    void on_actionKapitel_7_triggered();

    void on_actionKapitel_9_triggered();

    void on_actionKapitel_10_triggered();

    void on_actionChinesisch_triggered();

    void on_actionEnglisch_triggered();

    void on_pushButton_I_remember_clicked();

private:
    Ui::MainWindow *ui;
    void showHiddenButtons();
    void hideButtons();
    static bool hideDisplay;
    void setChapter(QAction* actionKapitel, int chapterNum);
};

#endif // MAINWINDOW_H
