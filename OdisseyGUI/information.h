/**
 * @brief This class creates a window that shows the information of the track that is currently playing
 * @author Monica Waterhouse
 *
 */

#ifndef INFORMATION_H
#define INFORMATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Information; }
QT_END_NAMESPACE

class Information : public QMainWindow
{
    Q_OBJECT

public:
    Information(QWidget *parent = nullptr);
    ~Information();
    void getInformation(QString title, QString genre, QString artist, QString length);

private slots:
    void on_btn_close_clicked();

private:
    Ui::Information *ui;
};
#endif // INFORMATION_H
