#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Parameter.h"
#include "InternetConn.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hideButtons();
    exercise = NULL;
    player = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*******Menu Callback************/
void MainWindow::on_actionQuit_triggered()
{
    qApp->exit();
}

void MainWindow::showHiddenButtons(){
    ui->pushButton_verben_last->show();
    ui->pushButton_verben_next->show();
    ui->pushButton_hide->show();
    ui->pushButton_online->show();
    ui->pushButton_I_remember->show();
}

void MainWindow::hideButtons(){
    ui->pushButton_verben_last->hide();
    ui->pushButton_verben_next->hide();
    ui->pushButton_hide->hide();
    ui->pushButton_online->hide();
    ui->pushButton_I_remember->hide();
}

void MainWindow::on_actionStart_Word_Excersice_triggered()
{
    if(player!=NULL){
        delete player;
    }

    player = new WordPlayer;
    if(player->startToPlay()==EStatus::error){
        return;
    }
    ui->stackedWidget->setCurrentIndex(1);
    QObject::connect(player,SIGNAL(updateUI()),this,SLOT(update_word_text()));
    showHiddenButtons();
    update_word_text();
}

void MainWindow::on_actionStart_Verben_Excersice_triggered()
{
    if (player!=NULL){
        delete player;
    }
    player = new VerbenPlayer;
    //when initialization fails
    if(player->startToPlay()==EStatus::error) {
        return;
    }
    //switch the Gui when initialization successes
    ui->stackedWidget->setCurrentIndex(2);
    QObject::connect(player,SIGNAL(updateUI()),this,SLOT(update_verben_text()));
    showHiddenButtons();
    update_verben_text();
}

void MainWindow::on_actionBack_to_main_menu_triggered()
{
    hideButtons();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_verben_last_clicked()
{
    player->playLast();
}

void MainWindow::on_pushButton_verben_next_clicked()
{
    player->playNext();
}

bool MainWindow::hideDisplay = false;

void MainWindow::on_pushButton_hide_clicked()
{
    hideDisplay = !hideDisplay;
    player->updateUI();
}


/*******************Gui Updating******************/
void MainWindow::update_verben_text(){
    ui->label_verben->setText(player->displayList[0].content);
    if(!hideDisplay){
        ui->label_verben_prs->setText(player->displayList[1].content);
        ui->label_verben_prm->setText(player->displayList[2].content);
        ui->label_verben_pft->setText(player->displayList[3].content);
        ui->pushButton_hide->setText("Hide Explaination");
    }
    else{
        ui->label_verben_prs->clear();
        ui->label_verben_prm->clear();
        ui->label_verben_pft->clear();
        ui->pushButton_hide->setText("Show Explaination");
    }
}

void MainWindow::update_word_text(){
    ui->label_word->setText(QString::number(player->getCurrentIndex())+"."+player->displayList[0].content);
    if(!hideDisplay){
        ui->label_expain->setText(player->displayList[1].content);
        ui->pushButton_hide->setText("Hide Explaination");
    }
    else{
        ui->label_expain->clear();
        ui->pushButton_hide->setText("Show Explaination");
    }
}

void MainWindow::on_pushButton_online_clicked()
{
    InternetConn::linkOpen(player->displayList[0].content);
}


void MainWindow::setChapter(QAction* actionKapitel, int chapterNum){
    if(actionKapitel->isChecked()){
        BookRange::setChapterNum(chapterNum);
    }
    else{
        if(!BookRange::clearChapterNum(chapterNum)){
            actionKapitel->setChecked(true);
            return;
        }
    }

    if (exercise!=NULL){
        exercise->reload();
        exercise->updateUI();
    }
}

void MainWindow::on_actionKapitel_1_triggered()
{
    setChapter(ui->actionKapitel_1,KAPITEL1);
}
void MainWindow::on_actionKapitel_2_triggered()
{
    setChapter(ui->actionKapitel_2,KAPITEL2);
}
void MainWindow::on_actionKapitel_8_triggered()
{
    setChapter(ui->actionKapitel_8,KAPITEL8);
}
void MainWindow::on_actionKapitel_3_triggered()
{
    setChapter(ui->actionKapitel_3,KAPITEL3);
}
void MainWindow::on_actionKapitel_4_triggered()
{
    setChapter(ui->actionKapitel_4,KAPITEL4);
}
void MainWindow::on_actionKapitel_5_triggered()
{
    setChapter(ui->actionKapitel_5,KAPITEL5);
}
void MainWindow::on_actionKapitel_6_triggered()
{
    setChapter(ui->actionKapitel_6,KAPITEL6);
}
void MainWindow::on_actionKapitel_7_triggered()
{
    setChapter(ui->actionKapitel_7,KAPITEL7);
}
void MainWindow::on_actionKapitel_9_triggered()
{
    setChapter(ui->actionKapitel_9,KAPITEL9);
}
void MainWindow::on_actionKapitel_10_triggered()
{
    setChapter(ui->actionKapitel_10,KAPITEL10);
}

void MainWindow::on_actionChinesisch_triggered()
{
    if (ui->actionChinesisch->isChecked()){
        ui->actionEnglisch->setChecked(false);
        ui->actionDeutsch->setChecked(false);
        BookRange::language = CHINESE;
    }
}

void MainWindow::on_actionEnglisch_triggered()
{
    if (ui->actionEnglisch->isChecked()){
        ui->actionChinesisch->setChecked(false);
        ui->actionDeutsch->setChecked(false);
        BookRange::language = ENGLISH;
    }
}

void MainWindow::on_pushButton_I_remember_clicked()
{
    player->deleteItem();
}
