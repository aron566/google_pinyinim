/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "virtualkeyboard.h"
QT_BEGIN_NAMESPACE

class Ui_keyboard
{
public:
    QWidget *centralwidget;
    QGroupBox *keyboardgroupBox;
    QLineEdit *keyboardeditbox;
    QLabel *keyboardtitlelabel;
    QPushButton *key_language;
    QPushButton *key_virgule;
    QPushButton *key_dash;
    QPushButton *key_colon;
    QPushButton *key_point;
    QPushButton *key_comma;
    QPushButton *key_at;
    QPushButton *key_1;
    QPushButton *key_2;
    QPushButton *key_3;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_6;
    QPushButton *key_7;
    QPushButton *key_8;
    QPushButton *key_9;
    QPushButton *key_0;
    QPushButton *key_q;
    QPushButton *key_w;
    QPushButton *key_e;
    QPushButton *key_r;
    QPushButton *key_t;
    QPushButton *key_y;
    QPushButton *key_u;
    QPushButton *key_i;
    QPushButton *key_o;
    QPushButton *key_p;
    QPushButton *key_a;
    QPushButton *key_s;
    QPushButton *key_d;
    QPushButton *key_f;
    QPushButton *key_g;
    QPushButton *key_h;
    QPushButton *key_j;
    QPushButton *key_k;
    QPushButton *key_l;
    QPushButton *key_z;
    QPushButton *key_x;
    QPushButton *key_c;
    QPushButton *key_v;
    QPushButton *key_b;
    QPushButton *key_n;
    QPushButton *key_m;
    QPushButton *key_caps;
    QPushButton *key_ok;
    QPushButton *key_del;
    QLineEdit *key_pinyininput;
    QPushButton *NEXTpushButton;
    QPushButton *LASTpushButton;

    void setupUi(QMainWindow *keyboard)
    {
        if (keyboard->objectName().isEmpty())
            keyboard->setObjectName(QString::fromUtf8("keyboard"));
        keyboard->resize(UI_KEYBOARDWINDOW_WIDTH, UI_KEYBOARDWINDOW_HEIGHT);
        keyboard->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(keyboard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        keyboardgroupBox = new QGroupBox(centralwidget);
        keyboardgroupBox->setObjectName(QString::fromUtf8("keyboardgroupBox"));

        keyboardgroupBox->setGeometry(QRect(10, 10,UI_KEYBOARDWINDOW_WIDTH-20, UI_KEYBOARDWINDOW_HEIGHT*140/720));

        keyboardgroupBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        keyboardeditbox = new QLineEdit(keyboardgroupBox);
        keyboardeditbox->setObjectName(QString::fromUtf8("keyboardeditbox"));

        keyboardeditbox->setGeometry(QRect(((UI_KEYBOARDWINDOW_WIDTH-20)*230)/1260, ((UI_KEYBOARDWINDOW_HEIGHT*140/720)*25)/140,((UI_KEYBOARDWINDOW_WIDTH-20)*1010)/1260, ((UI_KEYBOARDWINDOW_HEIGHT*140/720)*100)/140));

        keyboardtitlelabel = new QLabel(keyboardgroupBox);
        keyboardtitlelabel->setObjectName(QString::fromUtf8("keyboardtitlelabel"));

        keyboardtitlelabel->setGeometry(QRect(10, ((UI_KEYBOARDWINDOW_HEIGHT*140/720)*30)/140,((UI_KEYBOARDWINDOW_WIDTH-20)*200)/1260, ((UI_KEYBOARDWINDOW_HEIGHT*140/720)*90)/140));

        key_language = new QPushButton(centralwidget);
        key_language->setObjectName(QString::fromUtf8("key_language"));

        key_language->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*110/1280, UI_KEYBOARDWINDOW_HEIGHT*640/720, UI_KEYBOARDWINDOW_WIDTH*92/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_language->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_virgule = new QPushButton(centralwidget);
        key_virgule->setObjectName(QString::fromUtf8("key_virgule"));

        key_virgule->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*910/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*92/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_virgule->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_dash = new QPushButton(centralwidget);
        key_dash->setObjectName(QString::fromUtf8("key_dash"));

        key_dash->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*810/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*92/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_dash->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_colon = new QPushButton(centralwidget);
        key_colon->setObjectName(QString::fromUtf8("key_colon"));

        key_colon->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*910/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*92/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_colon->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_point = new QPushButton(centralwidget);
        key_point->setObjectName(QString::fromUtf8("key_point"));

        key_point->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1190/1280, UI_KEYBOARDWINDOW_HEIGHT*640/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_point->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_comma = new QPushButton(centralwidget);
        key_comma->setObjectName(QString::fromUtf8("key_comma"));

        key_comma->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*710/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*92/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_comma->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_at = new QPushButton(centralwidget);
        key_at->setObjectName(QString::fromUtf8("key_at"));

        key_at->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1010/1280, UI_KEYBOARDWINDOW_HEIGHT*640/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_at->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_1 = new QPushButton(centralwidget);
        key_1->setObjectName(QString::fromUtf8("key_1"));

        key_1->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1012/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_2 = new QPushButton(centralwidget);
        key_2->setObjectName(QString::fromUtf8("key_2"));

        key_2->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1100/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_3 = new QPushButton(centralwidget);
        key_3->setObjectName(QString::fromUtf8("key_3"));

        key_3->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1190/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_4 = new QPushButton(centralwidget);
        key_4->setObjectName(QString::fromUtf8("key_4"));

        key_4->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1010/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_5 = new QPushButton(centralwidget);
        key_5->setObjectName(QString::fromUtf8("key_5"));

        key_5->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1100/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_6 = new QPushButton(centralwidget);
        key_6->setObjectName(QString::fromUtf8("key_6"));

        key_6->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1190/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_7 = new QPushButton(centralwidget);
        key_7->setObjectName(QString::fromUtf8("key_7"));

        key_7->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1010/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_8 = new QPushButton(centralwidget);
        key_8->setObjectName(QString::fromUtf8("key_8"));

        key_8->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1100/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_9 = new QPushButton(centralwidget);
        key_9->setObjectName(QString::fromUtf8("key_9"));

        key_9->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1190/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_0 = new QPushButton(centralwidget);
        key_0->setObjectName(QString::fromUtf8("key_0"));

        key_0->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1100/1280, UI_KEYBOARDWINDOW_HEIGHT*640/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_q = new QPushButton(centralwidget);
        key_q->setObjectName(QString::fromUtf8("key_q"));

        key_q->setGeometry(QRect(10, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_q->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_w = new QPushButton(centralwidget);
        key_w->setObjectName(QString::fromUtf8("key_w"));

        key_w->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*110/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_w->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_e = new QPushButton(centralwidget);
        key_e->setObjectName(QString::fromUtf8("key_e"));

        key_e->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*210/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_e->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_r = new QPushButton(centralwidget);
        key_r->setObjectName(QString::fromUtf8("key_r"));

        key_r->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*310/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_r->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_t = new QPushButton(centralwidget);
        key_t->setObjectName(QString::fromUtf8("key_t"));

        key_t->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*410/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_t->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_y = new QPushButton(centralwidget);
        key_y->setObjectName(QString::fromUtf8("key_y"));

        key_y->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*510/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_y->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_u = new QPushButton(centralwidget);
        key_u->setObjectName(QString::fromUtf8("key_u"));

        key_u->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*610/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_u->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_i = new QPushButton(centralwidget);
        key_i->setObjectName(QString::fromUtf8("key_i"));

        key_i->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*710/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_i->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_o = new QPushButton(centralwidget);
        key_o->setObjectName(QString::fromUtf8("key_o"));

        key_o->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*810/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_o->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_p = new QPushButton(centralwidget);
        key_p->setObjectName(QString::fromUtf8("key_p"));

        key_p->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*910/1280, UI_KEYBOARDWINDOW_HEIGHT*400/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_p->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_a = new QPushButton(centralwidget);
        key_a->setObjectName(QString::fromUtf8("key_a"));

        key_a->setGeometry(QRect(10, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));


        key_a->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_s = new QPushButton(centralwidget);
        key_s->setObjectName(QString::fromUtf8("key_s"));

        key_s->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*110/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_s->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_d = new QPushButton(centralwidget);
        key_d->setObjectName(QString::fromUtf8("key_d"));

        key_d->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*210/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));


        key_d->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_f = new QPushButton(centralwidget);
        key_f->setObjectName(QString::fromUtf8("key_f"));

        key_f->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*310/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_f->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_g = new QPushButton(centralwidget);
        key_g->setObjectName(QString::fromUtf8("key_g"));

        key_g->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*410/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_g->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_h = new QPushButton(centralwidget);
        key_h->setObjectName(QString::fromUtf8("key_h"));

        key_h->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*510/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_h->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_j = new QPushButton(centralwidget);
        key_j->setObjectName(QString::fromUtf8("key_j"));

        key_j->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*610/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_j->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_k = new QPushButton(centralwidget);
        key_k->setObjectName(QString::fromUtf8("key_k"));

        key_k->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*710/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_k->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_l = new QPushButton(centralwidget);
        key_l->setObjectName(QString::fromUtf8("key_l"));

        key_l->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*810/1280, UI_KEYBOARDWINDOW_HEIGHT*480/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_l->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_z = new QPushButton(centralwidget);
        key_z->setObjectName(QString::fromUtf8("key_z"));

        key_z->setGeometry(QRect(10, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_z->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_x = new QPushButton(centralwidget);
        key_x->setObjectName(QString::fromUtf8("key_x"));

        key_x->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*110/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_x->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_c = new QPushButton(centralwidget);
        key_c->setObjectName(QString::fromUtf8("key_c"));

        key_c->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*210/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_c->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_v = new QPushButton(centralwidget);
        key_v->setObjectName(QString::fromUtf8("key_v"));

        key_v->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*310/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_v->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_b = new QPushButton(centralwidget);
        key_b->setObjectName(QString::fromUtf8("key_b"));

        key_b->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*410/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_b->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_n = new QPushButton(centralwidget);
        key_n->setObjectName(QString::fromUtf8("key_n"));

        key_n->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*510/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_n->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_m = new QPushButton(centralwidget);
        key_m->setObjectName(QString::fromUtf8("key_m"));

        key_m->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*610/1280, UI_KEYBOARDWINDOW_HEIGHT*560/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_m->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_caps = new QPushButton(centralwidget);
        key_caps->setObjectName(QString::fromUtf8("key_caps"));

        key_caps->setGeometry(QRect(10, UI_KEYBOARDWINDOW_HEIGHT*640/720, UI_KEYBOARDWINDOW_WIDTH*90/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_caps->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_ok = new QPushButton(centralwidget);
        key_ok->setObjectName(QString::fromUtf8("key_ok"));

        key_ok->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*210/1280, UI_KEYBOARDWINDOW_HEIGHT*640/720, UI_KEYBOARDWINDOW_WIDTH*640/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_ok->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_del = new QPushButton(centralwidget);
        key_del->setObjectName(QString::fromUtf8("key_del"));

        key_del->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*860/1280, UI_KEYBOARDWINDOW_HEIGHT*640/720, UI_KEYBOARDWINDOW_WIDTH*140/1280, UI_KEYBOARDWINDOW_HEIGHT*70/720));

        key_del->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        key_pinyininput = new QLineEdit(centralwidget);
        key_pinyininput->setObjectName(QString::fromUtf8("key_pinyininput"));

        key_pinyininput->setGeometry(QRect(10, UI_KEYBOARDWINDOW_HEIGHT*330/720, UI_KEYBOARDWINDOW_WIDTH-20, UI_KEYBOARDWINDOW_HEIGHT*60/720));

        key_pinyininput->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));

        NEXTpushButton = new QPushButton(centralwidget);
        NEXTpushButton->setObjectName(QString::fromUtf8("NEXTpushButton"));
        NEXTpushButton->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1190/1280, UI_KEYBOARDWINDOW_HEIGHT*160/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*80/720));
        NEXTpushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        LASTpushButton = new QPushButton(centralwidget);
        LASTpushButton->setObjectName(QString::fromUtf8("LASTpushButton"));
        LASTpushButton->setGeometry(QRect(UI_KEYBOARDWINDOW_WIDTH*1190/1280, UI_KEYBOARDWINDOW_HEIGHT*240/720, UI_KEYBOARDWINDOW_WIDTH*80/1280, UI_KEYBOARDWINDOW_HEIGHT*80/720));
        LASTpushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 65, 66);"));
        keyboard->setCentralWidget(centralwidget);

        retranslateUi(keyboard);

        QMetaObject::connectSlotsByName(keyboard);
    } // setupUi

    void retranslateUi(QMainWindow *keyboard)
    {
        keyboard->setWindowTitle(QCoreApplication::translate("keyboard", "keyboard", nullptr));
        keyboardgroupBox->setTitle(QCoreApplication::translate("keyboard", "\346\226\207\346\234\254\347\274\226\350\276\221", nullptr));
        keyboardeditbox->setText(QCoreApplication::translate("keyboard", "***", nullptr));
        keyboardtitlelabel->setText(QCoreApplication::translate("keyboard", "<html><head/><body><p align=\"center\">xx\347\274\226\350\276\221\350\276\223\345\205\245:</p></body></html>", nullptr));
        key_language->setText(QCoreApplication::translate("keyboard", "en/zh", nullptr));
        key_virgule->setText(QCoreApplication::translate("keyboard", "/", nullptr));
        key_dash->setText(QCoreApplication::translate("keyboard", "-", nullptr));
        key_colon->setText(QCoreApplication::translate("keyboard", ":", nullptr));
        key_point->setText(QCoreApplication::translate("keyboard", ".", nullptr));
        key_comma->setText(QCoreApplication::translate("keyboard", ",", nullptr));
        key_at->setText(QCoreApplication::translate("keyboard", "@", nullptr));
        key_1->setText(QCoreApplication::translate("keyboard", "1", nullptr));
        key_2->setText(QCoreApplication::translate("keyboard", "2", nullptr));
        key_3->setText(QCoreApplication::translate("keyboard", "3", nullptr));
        key_4->setText(QCoreApplication::translate("keyboard", "4", nullptr));
        key_5->setText(QCoreApplication::translate("keyboard", "5", nullptr));
        key_6->setText(QCoreApplication::translate("keyboard", "6", nullptr));
        key_7->setText(QCoreApplication::translate("keyboard", "7", nullptr));
        key_8->setText(QCoreApplication::translate("keyboard", "8", nullptr));
        key_9->setText(QCoreApplication::translate("keyboard", "9", nullptr));
        key_0->setText(QCoreApplication::translate("keyboard", "0", nullptr));
        key_q->setText(QCoreApplication::translate("keyboard", "q", nullptr));
        key_w->setText(QCoreApplication::translate("keyboard", "w", nullptr));
        key_e->setText(QCoreApplication::translate("keyboard", "e", nullptr));
        key_r->setText(QCoreApplication::translate("keyboard", "r", nullptr));
        key_t->setText(QCoreApplication::translate("keyboard", "t", nullptr));
        key_y->setText(QCoreApplication::translate("keyboard", "y", nullptr));
        key_u->setText(QCoreApplication::translate("keyboard", "u", nullptr));
        key_i->setText(QCoreApplication::translate("keyboard", "i", nullptr));
        key_o->setText(QCoreApplication::translate("keyboard", "o", nullptr));
        key_p->setText(QCoreApplication::translate("keyboard", "p", nullptr));
        key_a->setText(QCoreApplication::translate("keyboard", "a", nullptr));
        key_s->setText(QCoreApplication::translate("keyboard", "s", nullptr));
        key_d->setText(QCoreApplication::translate("keyboard", "d", nullptr));
        key_f->setText(QCoreApplication::translate("keyboard", "f", nullptr));
        key_g->setText(QCoreApplication::translate("keyboard", "g", nullptr));
        key_h->setText(QCoreApplication::translate("keyboard", "h", nullptr));
        key_j->setText(QCoreApplication::translate("keyboard", "j", nullptr));
        key_k->setText(QCoreApplication::translate("keyboard", "k", nullptr));
        key_l->setText(QCoreApplication::translate("keyboard", "l", nullptr));
        key_z->setText(QCoreApplication::translate("keyboard", "z", nullptr));
        key_x->setText(QCoreApplication::translate("keyboard", "x", nullptr));
        key_c->setText(QCoreApplication::translate("keyboard", "c", nullptr));
        key_v->setText(QCoreApplication::translate("keyboard", "v", nullptr));
        key_b->setText(QCoreApplication::translate("keyboard", "b", nullptr));
        key_n->setText(QCoreApplication::translate("keyboard", "n", nullptr));
        key_m->setText(QCoreApplication::translate("keyboard", "m", nullptr));
        key_caps->setText(QCoreApplication::translate("keyboard", "caps", nullptr));
        key_ok->setText(QCoreApplication::translate("keyboard", "ok", nullptr));
        key_del->setText(QCoreApplication::translate("keyboard", "del", nullptr));
        key_pinyininput->setText(QCoreApplication::translate("keyboard", "***", nullptr));
        NEXTpushButton->setText(QCoreApplication::translate("keyboard", "=>", nullptr));
        LASTpushButton->setText(QCoreApplication::translate("keyboard", "<=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keyboard: public Ui_keyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
