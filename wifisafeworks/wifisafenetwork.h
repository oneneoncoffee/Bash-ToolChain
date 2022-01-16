#ifndef WIFISAFENETWORK_H
#define WIFISAFENETWORK_H

#include <QMainWindow>

namespace Ui {
class wifisafenetwork;
}

class wifisafenetwork : public QMainWindow
{
    Q_OBJECT

public:
    explicit wifisafenetwork(QWidget *parent = 0);
    ~wifisafenetwork();

private slots:
    void on_pushButton_clicked();
    void on_actionAbout_GUI_Program_triggered();

    void on_actionProject_notes_2_triggered();

    void on_actionConnect_to_host_2_triggered();

    void on_actionBash_shell_triggered();

private:
    Ui::wifisafenetwork *ui;
    void loadTextFile();
};

#endif // WIFISAFENETWORK_H
