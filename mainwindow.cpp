#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <map>
#include <utility>
#include "dialogwindow.h"
#include "ui_dialogwindow.h"
//#include <QPushButton>

using namespace std;

#define MONTH_CONNECTS(MMM) \
    connect(ui->pushButton_##MMM##_1, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_2, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_3, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_4, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_5, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_6, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_7, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_8, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_9, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_10, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_11, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_12, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_13, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_14, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_15, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_16, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_17, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_18, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_19, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_20, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_21, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_22, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_23, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_24, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_25, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_26, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_27, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_28, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_29, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_30, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_31, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_32, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_33, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_34, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_35, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_36, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_37, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_38, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_39, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_40, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_41, SIGNAL(clicked()), this, SLOT(notes())); \
    connect(ui->pushButton_##MMM##_42, SIGNAL(clicked()), this, SLOT(notes()));

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MONTH_CONNECTS(Jan);
    MONTH_CONNECTS(Feb);
    MONTH_CONNECTS(Mar);
    MONTH_CONNECTS(Apr);
    MONTH_CONNECTS(May);
    MONTH_CONNECTS(Jun);
    MONTH_CONNECTS(Jul);
    MONTH_CONNECTS(Aug);
    MONTH_CONNECTS(Sep);
    MONTH_CONNECTS(Oct);
    MONTH_CONNECTS(Nov);
    MONTH_CONNECTS(Dec);

    connect(ui->pushButton_year, SIGNAL(clicked()), this, SLOT(drawing()));
}

map<pair<int, QPushButton *>, QString> mark;
int year;

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::notes() {
    QPushButton *button = (QPushButton *)sender();
    if (button->text() != " ") {
        DialogWindow win;
        if (mark[{year, button}] != " ") {
            win.set_note(mark[{year, button}]);
        }
        if (win.exec()) {
            if (win.note() != "") {
                button->setStyleSheet("color: rgb(0, 255, 0);");
                mark[{year, button}] = win.note();
            } else {
                mark[{year, button}] = "";
                button ->setStyleSheet("");
            }
        }
    }

}
bool visokos(int year) {
    if ((year % 4 == 0)) {
        return true;
    } else  {
        return false;
    }
}

int first_day () {
    int a, b;
    a = (6 + (year % 100) + (year % 100) / 4) % 7;
    b = (1 + 1 + a) % 7 - 1;
    if (visokos(year) == true) {
        if (b > 1) {
            return b - 2;
        } else {
            return (7 - abs(b - 2));
        }
    } else {
        if (b > 0) {
            return b - 1;
        } else {
            return (7 - abs(b - 1));
        }
    }

}

int feb() {
    int a = 31 - ((31 - (7 - first_day() + 1 )) / 7 * 7);
    int b = a - (7 - first_day() + 1) + 1;
    return b;

}
int mar() {
    if (visokos(year) == true) {
        int a = 29 - ((29 - (7 - feb() + 1 )) / 7 * 7);
        int b = a - (7 - feb() + 1) + 1;
        if (feb() < 8) {
            return b;
        } else {
            return b - 7;
        }
    } else {
        int a = 28 - ((28 - (7 - feb() + 1 )) / 7 * 7);
        int b = a - (7 - feb() + 1) + 1;
        if (feb() < 8) {
            return b;
        } else {
            return b - 7;
        }

    }
}
int apr() {
    int a = 31 - ((31 - (7 - mar() + 1 )) / 7 * 7);
    int b = a - (7 - mar() + 1) + 1;
    if (mar() < 8) {
        return b;
    } else {
        return b - 7;
    }
}
int may() {
    int a = 30 - ((30 - (7 - apr() + 1 )) / 7 * 7);
    int b = a - (7 - apr() + 1) + 1;
    if (apr() < 8) {
        return b;
    } else {
        return b - 7;
    }
}
int jun() {
    int a = 31 - ((31 - (7 - may() + 1 )) / 7 * 7);
    int b = a - (7 - may() + 1) + 1;
    if (may() < 8) {
        return b;
    } else {
        return b - 7;
    }
}
int jul() {
    int a = 30 - ((30 - (7 - jun() + 1 )) / 7 * 7);
    int b = a - (7 - jun() + 1) + 1;
    if (jun() < 8) {
        return b;
    } else {
        return b - 7;
    }
}
int aug() {
    int a = 31 - ((31 - (7 - jul() + 1 )) / 7 * 7);
    int b = a - (7 - jul() + 1) + 1;
    if (jul() < 8) {
        return b;
    } else {
        return b - 7;
    }
}

int sep() {
    int a = 31 - ((31 - (7 - aug() + 1 )) / 7 * 7);
    int b = a - (7 - aug() + 1) + 1;
    if (aug() < 8) {
        return b;
    } else {
        return b - 7;
    }
}

int oct() {
    int a = 30 - ((30 - (7 - sep() + 1 )) / 7 * 7);
    int b = a - (7 - sep() + 1) + 1;
    if (sep() < 8) {
        return b;
    } else {
        return b - 7;
    }
}

int nov() {
    int a = 31 - ((31 - (7 - oct() + 1 )) / 7 * 7);
    int b = a - (7 - oct() + 1) + 1;
    if (oct() < 8) {
        return b;
    } else {
        return b - 7;
    }
}
int dec() {
    int a = 30 - ((30 - (7 - nov() + 1 )) / 7 * 7);
    int b = a - (7 - nov() + 1) + 1;
    if (nov() < 8) {
        return b;
    } else {
        return b - 7;
    }
}

#define MONTH_BUTTONS(MMM) \
    QPushButton *MMM[42] = {ui->pushButton_##MMM##_1, ui->pushButton_##MMM##_2, ui->pushButton_##MMM##_3, ui->pushButton_##MMM##_4, ui->pushButton_##MMM##_5, \
                            ui->pushButton_##MMM##_6, ui->pushButton_##MMM##_7, ui->pushButton_##MMM##_8, ui->pushButton_##MMM##_9, ui->pushButton_##MMM##_10, \
                            ui->pushButton_##MMM##_11, ui->pushButton_##MMM##_12, ui->pushButton_##MMM##_13, ui->pushButton_##MMM##_14, ui->pushButton_##MMM##_15, \
                            ui->pushButton_##MMM##_16, ui->pushButton_##MMM##_17, ui->pushButton_##MMM##_18, ui->pushButton_##MMM##_19, ui->pushButton_##MMM##_20, \
                            ui->pushButton_##MMM##_21, ui->pushButton_##MMM##_22, ui->pushButton_##MMM##_23, ui->pushButton_##MMM##_24, ui->pushButton_##MMM##_25, \
                            ui->pushButton_##MMM##_26, ui->pushButton_##MMM##_27, ui->pushButton_##MMM##_28, ui->pushButton_##MMM##_29, ui->pushButton_##MMM##_30, \
                            ui->pushButton_##MMM##_31, ui->pushButton_##MMM##_32, ui->pushButton_##MMM##_33, ui->pushButton_##MMM##_34, ui->pushButton_##MMM##_35, \
                            ui->pushButton_##MMM##_36, ui->pushButton_##MMM##_37, ui->pushButton_##MMM##_38, ui->pushButton_##MMM##_39, ui->pushButton_##MMM##_40, \
                            ui->pushButton_##MMM##_41, ui->pushButton_##MMM##_42};

void MainWindow::drawing() {
    MONTH_BUTTONS(Jan);
    MONTH_BUTTONS(Feb);
    MONTH_BUTTONS(Mar);
    MONTH_BUTTONS(Apr);
    MONTH_BUTTONS(May);
    MONTH_BUTTONS(Jun);
    MONTH_BUTTONS(Jul);
    MONTH_BUTTONS(Aug);
    MONTH_BUTTONS(Sep);
    MONTH_BUTTONS(Oct);
    MONTH_BUTTONS(Nov);
    MONTH_BUTTONS(Dec);

    year = ui->lineEdit->text().toInt();
    int count = 1;
    int count2 = 0;
    int i;

    for (i = 0; i < 42; ++i) {
        Jan[i]->setStyleSheet("");
        Jan[i]->setText("");
        Jan[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Jan[i]}] != "") {
            Jan[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = first_day(); i < 42; ++i) {
        if (count <= 31) {
        Jan[i]->setText(QString::number(count));
        ++count;
        Jan[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Feb[i]->setStyleSheet("");
        Feb[i]->setText("");
        Feb[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Feb[i]}] != "") {
            Feb[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = feb(); i < 42; ++i) {
        if (visokos(year) == true) {
            if (count <= 29) {
            Feb[i]->setText(QString::number(count));
            ++count;
            Feb[i]->setDisabled(false);
            }
        } else {
                if (count <= 28) {
                Feb[i]->setText(QString::number(count));
                ++count;
                Feb[i]->setDisabled(false);
                }
        }
    }
    count = 1;

    for (i = 0; i < 42; ++i) {
        Mar[i]->setStyleSheet("");
        Mar[i]->setText("");
        Mar[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Mar[i]}] != "") {
            Mar[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = mar(); i < 42; ++i) {
        if (count <= 31) {
        Mar[i]->setText(QString::number(count));
        ++count;
        Mar[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Apr[i]->setStyleSheet("");
        Apr[i]->setText("");
        Apr[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Apr[i]}] != "") {
            Apr[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = apr(); i < 42; ++i) {
        if (count <= 30) {
        Apr[i]->setText(QString::number(count));
        ++count;
        Apr[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        May[i]->setStyleSheet("");
        May[i]->setText("");
        May[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, May[i]}] != "") {
            Jan[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = may(); i < 42; ++i) {
        if (count <= 31) {
        May[i]->setText(QString::number(count));
        ++count;
        May[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Jun[i]->setStyleSheet("");
        Jun[i]->setText("");
        Jun[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Jun[i]}] != "") {
            Jan[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = jun(); i < 42; ++i) {
        if (count <= 30) {
        Jun[i]->setText(QString::number(count));
        ++count;
        Jun[i]->setDisabled(false);
        }
    }

    count = 1;
    for (i = 0; i < 42; ++i) {
        Jul[i]->setStyleSheet("");
        Jul[i]->setText("");
        Jul[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Jul[i]}] != "") {
            Jul[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = jul(); i < 42; ++i) {
        if (count <= 31) {
        Jul[i]->setText(QString::number(count));
        ++count;
        Jul[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Aug[i]->setStyleSheet("");
        Aug[i]->setText("");
        Aug[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Aug[i]}] != "") {
            Jan[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = aug(); i < 42; ++i) {
        if (count <= 31) {
        Aug[i]->setText(QString::number(count));
        ++count;
        Aug[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Sep[i]->setStyleSheet("");
        Sep[i]->setText("");
        Sep[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Sep[i]}] != "") {
            Jan[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = sep(); i < 42; ++i) {
        if (count <= 30) {
        Sep[i]->setText(QString::number(count));
        ++count;
        Sep[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Oct[i]->setStyleSheet("");
        Oct[i]->setText("");
        Oct[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Oct[i]}] != "") {
            Oct[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = oct(); i < 42; ++i) {
        if (count <= 31) {
        Oct[i]->setText(QString::number(count));
        ++count;
        Oct[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Nov[i]->setStyleSheet("");
        Nov[i]->setText("");
        Nov[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Nov[i]}] != "") {
            Nov[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = nov(); i < 42; ++i) {
        if (count <= 30) {
        Nov[i]->setText(QString::number(count));
        ++count;
        Nov[i]->setDisabled(false);
        }
    }
    count = 1;
    for (i = 0; i < 42; ++i) {
        Dec[i]->setStyleSheet("");
        Dec[i]->setText("");
        Dec[i]->setDisabled(true);
    }

    for (i = 0; i < 42; ++i) {
        if (mark[{year, Dec[i]}] != "") {
            Dec[i]->setStyleSheet("color: rgb(0, 255, 0);");
        }
    }

    for (i = dec(); i < 42; ++i) {
        if (count <= 31) {
        Dec[i]->setText(QString::number(count));
        ++count;
        Dec[i]->setDisabled(false);
        }
    }
    count = 1;
}



