#include <QtGui>
#include <QDebug>
#include "candydialog.h"
#include <QString>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setStyle(new QPlastiqueStyle);

    QFile file(":/qss/candy.qss");
    file.open(QFile::ReadOnly);
    qDebug() << file.readAll();
    //    app.setStyleSheet(file.readAll());

    QString sty_str = "QDialog { background-image: url(:/images/background.png);}";
     sty_str += "QLabel { font: 9pt; color: rgb(0, 0, 127);  }";

      sty_str += "QComboBox:editable,QLineEdit,QListView {\
                  color: rgb(127, 0, 63);\
                  background-color: rgb(255, 255, 241);\
                  selection-color: white;\
                  selection-background-color: rgb(191, 31, 127);\
                  border: 2px groove gray;\
                  border-radius: 10px;\
                  padding: 2px 4px;\
              }";
/* R4 */
//    sty_str += "\
//            QListView {\
//                padding: 5px 4px;\
//            }";

/* R5  */
sty_str  +=  " QComboBox:!editable,\
        QPushButton {\
            color: white;\
            font: bold 10pt;\
            border-image: url(:/images/button.png) 16;\
            border-width: 16px;\
            padding: -16px 0px;\
            min-height: 32px;\
            min-width: 60px;\
        } ";
     /* R6  */
    sty_str += "QComboBox:!editable:hover,\
            QComboBox::drop-down:editable:hover,\
            QPushButton:hover {\
                border-image: url(:/images/button-hover.png) 16;\
            }  ";

    /* R7 */
   sty_str += "QComboBox:!editable:on,\
           QPushButton:pressed {\
               color: lightgray;\
               border-image: url(:/images/button-pressed.png) 16;\
               padding-top: -15px;\
               padding-bottom: -17px;\
           }";
    /* R8 */
    sty_str += "QComboBox::down-arrow {\
           image: url(:/images/down-arrow.png);\
       }";
   /* R9 */
   sty_str += "QComboBox::down-arrow:on { top: 1px;} ";
   /* R10 */
    sty_str += " QComboBox * { font: 9pt; }";
   /* R11 */
    sty_str += " QComboBox::drop-down:!editable {\
                subcontrol-origin: padding;\
                subcontrol-position: center right;\
                width: 11px;\
                height: 6px;\
                background: none;\
            }  ";
   /* R12 */
    sty_str += "QComboBox:!editable { padding-right: 15px; }";

    /* R13 */
    sty_str += "QComboBox::drop-down:editable {\
            border-image: url(:/images/button.png) 16;\
            border-width: 10px;\
            subcontrol-origin: margin;\
            subcontrol-position: center right;\
            width: 7px;\
            height: 6px;\
        }";
    /* R14 */
    sty_str += "QComboBox::drop-down:editable:open { border-image: url(:/images/button-pressed.png) 16; }";

    /* R15 */
    sty_str += "QComboBox:editable { margin-right: 29px; }";


    app.setStyleSheet(sty_str);
    CandyDialog dialog;
    dialog.show();

    return app.exec();
}
