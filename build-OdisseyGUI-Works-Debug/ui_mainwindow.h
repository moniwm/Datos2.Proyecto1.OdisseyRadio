/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *closeBtn;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox;
    QFrame *frame;
    QPushButton *playBtn;
    QSlider *songControl;
    QLabel *nowPlayingLabel;
    QPushButton *infoBtn;
    QTableWidget *songsList;
    QPushButton *loadBtn;
    QLabel *memoryUsageLabel;
    QProgressBar *memoryPB;
    QRadioButton *paginateBtn;
    QLabel *label_2;
    QFrame *line;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        MainWindow->setMaximumSize(QSize(1000, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Avenir Next"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 50, 51)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        closeBtn = new QPushButton(centralwidget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(20, 20, 10, 10));
        closeBtn->setMaximumSize(QSize(25, 25));
        closeBtn->setCursor(QCursor(Qt::PointingHandCursor));
        closeBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(237, 107, 97)"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 70, 81, 16));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 100, 261, 301));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalLayoutWidget->sizePolicy().hasHeightForWidth());
        verticalLayoutWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, 0, 30, 0);
        checkBox_2 = new QCheckBox(verticalLayoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(checkBox_2);

        checkBox_5 = new QCheckBox(verticalLayoutWidget);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        verticalLayout->addWidget(checkBox_5);

        checkBox_7 = new QCheckBox(verticalLayoutWidget);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        verticalLayout->addWidget(checkBox_7);

        checkBox_6 = new QCheckBox(verticalLayoutWidget);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        verticalLayout->addWidget(checkBox_6);

        checkBox_4 = new QCheckBox(verticalLayoutWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        verticalLayout->addWidget(checkBox_4);

        checkBox_3 = new QCheckBox(verticalLayoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);

        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(260, 0, 741, 101));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(33, 34, 34)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        playBtn = new QPushButton(frame);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        playBtn->setGeometry(QRect(40, 30, 61, 41));
        songControl = new QSlider(frame);
        songControl->setObjectName(QString::fromUtf8("songControl"));
        songControl->setGeometry(QRect(150, 50, 441, 22));
        songControl->setOrientation(Qt::Horizontal);
        nowPlayingLabel = new QLabel(frame);
        nowPlayingLabel->setObjectName(QString::fromUtf8("nowPlayingLabel"));
        nowPlayingLabel->setGeometry(QRect(300, 20, 151, 16));
        infoBtn = new QPushButton(frame);
        infoBtn->setObjectName(QString::fromUtf8("infoBtn"));
        infoBtn->setGeometry(QRect(700, 10, 31, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Optima"));
        font1.setItalic(true);
        infoBtn->setFont(font1);
        songsList = new QTableWidget(centralwidget);
        if (songsList->columnCount() < 4)
            songsList->setColumnCount(4);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font2);
        songsList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font2);
        songsList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font2);
        songsList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font2);
        songsList->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (songsList->rowCount() < 16)
            songsList->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(8, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(9, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(10, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(11, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(12, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(13, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(14, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        songsList->setVerticalHeaderItem(15, __qtablewidgetitem19);
        songsList->setObjectName(QString::fromUtf8("songsList"));
        songsList->setGeometry(QRect(260, 100, 740, 500));
        songsList->setMinimumSize(QSize(740, 500));
        songsList->setMaximumSize(QSize(740, 500));
        songsList->setLineWidth(3);
        songsList->setMidLineWidth(1);
        songsList->setSortingEnabled(true);
        songsList->horizontalHeader()->setCascadingSectionResizes(false);
        songsList->horizontalHeader()->setMinimumSectionSize(150);
        songsList->horizontalHeader()->setDefaultSectionSize(184);
        songsList->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        songsList->verticalHeader()->setVisible(false);
        songsList->verticalHeader()->setHighlightSections(false);
        songsList->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        loadBtn = new QPushButton(centralwidget);
        loadBtn->setObjectName(QString::fromUtf8("loadBtn"));
        loadBtn->setGeometry(QRect(70, 410, 112, 41));
        memoryUsageLabel = new QLabel(centralwidget);
        memoryUsageLabel->setObjectName(QString::fromUtf8("memoryUsageLabel"));
        memoryUsageLabel->setGeometry(QRect(20, 500, 161, 16));
        memoryPB = new QProgressBar(centralwidget);
        memoryPB->setObjectName(QString::fromUtf8("memoryPB"));
        memoryPB->setGeometry(QRect(20, 520, 221, 23));
        memoryPB->setValue(24);
        paginateBtn = new QRadioButton(centralwidget);
        paginateBtn->setObjectName(QString::fromUtf8("paginateBtn"));
        paginateBtn->setGeometry(QRect(20, 550, 100, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 20, 191, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Avenir Next"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8(""));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 475, 261, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Odissey Radio", nullptr));
        closeBtn->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "LIBRARY", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Album 1", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "Album 2", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "Album 3", nullptr));
        checkBox_6->setText(QCoreApplication::translate("MainWindow", "Album 4", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Album 5", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Album 6", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Album 7", nullptr));
        playBtn->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        nowPlayingLabel->setText(QCoreApplication::translate("MainWindow", "Dream on - Aerosmith", nullptr));
        infoBtn->setText(QCoreApplication::translate("MainWindow", "i", nullptr));
        QTableWidgetItem *___qtablewidgetitem = songsList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = songsList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = songsList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Length", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = songsList->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = songsList->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = songsList->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = songsList->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = songsList->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = songsList->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = songsList->verticalHeaderItem(5);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = songsList->verticalHeaderItem(6);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = songsList->verticalHeaderItem(7);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = songsList->verticalHeaderItem(8);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = songsList->verticalHeaderItem(9);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = songsList->verticalHeaderItem(10);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = songsList->verticalHeaderItem(11);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = songsList->verticalHeaderItem(12);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = songsList->verticalHeaderItem(13);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = songsList->verticalHeaderItem(14);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = songsList->verticalHeaderItem(15);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "New Row", nullptr));
        loadBtn->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        memoryUsageLabel->setText(QCoreApplication::translate("MainWindow", "Memory usage: ", nullptr));
        paginateBtn->setText(QCoreApplication::translate("MainWindow", "Paginate", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ODISSEY RADIO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
