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
    void getInformation(std::string title, std::string genre, std::string artist, std::string length);

private slots:
    void on_btn_close_clicked();

private:
    Ui::Information *ui;
};
#endif // INFORMATION_H
