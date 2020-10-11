/**
  * @brief Header file for the GUI of the Odissey Radio application
  * @author Monica Waterhouse Montoya
  * @since October 9th, 2020
  *
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_playBtn_clicked();

    void on_infoBtn_clicked();

    void on_loadBtn_clicked();

    void on_allBtn_stateChanged(int arg1);

    void on_paginateBtn_clicked();

    void resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
