#include "wifisafenetwork.h"
#include "ui_wifisafenetwork.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QtGui>

wifisafenetwork::wifisafenetwork(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wifisafenetwork)
{
    ui->setupUi(this);
    loadTextFile();
}

wifisafenetwork::~wifisafenetwork()
{
    delete ui;
}

void wifisafenetwork::on_pushButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}


void wifisafenetwork::loadTextFile() {
    QFile inputFile(":/readme.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);

}

void wifisafenetwork::on_actionAbout_GUI_Program_triggered()
{
    QMessageBox about_dialog;
    about_dialog.setWindowTitle("About is WIFI a safe Network");
    about_dialog.setToolTip("About is WIFI a safe Network");
    about_dialog.setText("<H1>Is this WIFI network safe or not?</H1> <b>version 1.2 bata Gnome stable branch</b>. "
                         "<BR> Programmed by Johnny Buckallew Stroud 2018 Open source <BR> <font color='green' size='16'>Information:</font>"
                         "<p align='center'> This is the graphical front-end for the bash shell C program that checks A wireless network for A mother zero-day vulnerability. "
                         "'Mother Zero-day' is A slang term that refers to the amount of days passed that the manufacturer of Hardware and/or Software has done nothing to correct the problems found.</p> <BR> "
                         ""
                         "<u><center><h2>Be Free, "
                         "Feel Freedom not fear!</h2></u></center>");
    about_dialog.exec();
}

void wifisafenetwork::on_actionProject_notes_2_triggered()
{
    QMessageBox project_dialog;
    project_dialog.setToolTip("Project notes GCC");
    project_dialog.setWindowTitle("how to make A GCC ELF file!");
    project_dialog.setText("<H1>How to MAKE the, <font color='red'> isnetworksafe.c source file</font></h1> <BR> <b>Step 1</b>: Open bash shell <BR> <b>Step 2</b>: gcc isnetworksafe.c -o isnetworksafe <BR> you now have a working ELF command line program for bash."
                           "<BR> So Just FYI Qt Creator only makes the GUI. ");
    project_dialog.exec();
}

void wifisafenetwork::on_actionConnect_to_host_2_triggered()
{
    if(!QProcess::startDetached("isnetworksafe localhost >>readme.txt"));
        qDebug() << "Error: Failed to run script.";

}

void wifisafenetwork::on_actionBash_shell_triggered()
{
    if(!QProcess::startDetached("terminator"))
        qDebug() << "Error: Failed to run script.";
}
