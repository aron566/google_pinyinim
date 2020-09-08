/**
  ******************************************************************************
  * @file    keyboard.cpp
  * @author  aron566
  * @version v1.0
  * @date    2020-08-14
  * @brief   实现软件键盘，支持按键触发聚焦.
  ******************************************************************************
  */
/* Header includes -----------------------------------------------------------*/
#include "keyboard.h"
#include "ui_keyboard.h"
#include <QKeyEvent>
#include <QFileInfo>
#include <QDebug>
#include "virtualkeyboard.h"

/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/
/**
 * @brief keyboard::keyboard
 * @param parent
 */
keyboard::keyboard(QWidget *parent ,const char* datapath ,const char* userdatapth)
    : QMainWindow(parent)
    , dict_datapath(datapath)
    , dict_userdatapath(userdatapth)
    , ui(new Ui::keyboard)
{
    ui->setupUi(this);

    /*去掉windows关闭窗口按钮*/
    this->setWindowFlag(Qt::FramelessWindowHint);

    this->hide();

    /*聚焦排序*/
    InitTabOrder();

    /*映射按键对象*/
    Init_MAP_Key_value();

    /*中文结果预处理*/
    ZhResultWigdetInit();

    /*初始化谷歌拼音*/
    Google_PinyinInit(dict_datapath ,dict_userdatapath);

    /*初始化键盘模式*/
    set_keyboardmode(ANY);
}

/**
 * @brief keyboard::~keyboard
 */
keyboard::~keyboard()
{
    delete ui;
}

/**
 * @brief keyboard::InitTabOrder
 */
void keyboard::InitTabOrder(void)
{
    keyboard::setTabOrder(ui->key_1, ui->key_2);
    keyboard::setTabOrder(ui->key_2, ui->key_3);
    keyboard::setTabOrder(ui->key_3, ui->key_4);
    keyboard::setTabOrder(ui->key_4, ui->key_5);
    keyboard::setTabOrder(ui->key_5, ui->key_6);
    keyboard::setTabOrder(ui->key_6, ui->key_7);
    keyboard::setTabOrder(ui->key_7, ui->key_8);
    keyboard::setTabOrder(ui->key_8, ui->key_9);
    keyboard::setTabOrder(ui->key_9, ui->key_0);
    keyboard::setTabOrder(ui->key_0, ui->key_q);
    keyboard::setTabOrder(ui->key_q, ui->key_w);
    keyboard::setTabOrder(ui->key_w, ui->key_e);
    keyboard::setTabOrder(ui->key_e, ui->key_r);
    keyboard::setTabOrder(ui->key_r, ui->key_t);
    keyboard::setTabOrder(ui->key_t, ui->key_y);
    keyboard::setTabOrder(ui->key_y, ui->key_u);
    keyboard::setTabOrder(ui->key_u, ui->key_i);
    keyboard::setTabOrder(ui->key_i, ui->key_o);
    keyboard::setTabOrder(ui->key_o, ui->key_p);
    keyboard::setTabOrder(ui->key_p, ui->key_a);
    keyboard::setTabOrder(ui->key_a, ui->key_s);
    keyboard::setTabOrder(ui->key_s, ui->key_d);
    keyboard::setTabOrder(ui->key_d, ui->key_f);
    keyboard::setTabOrder(ui->key_f, ui->key_g);
    keyboard::setTabOrder(ui->key_g, ui->key_h);
    keyboard::setTabOrder(ui->key_j, ui->key_k);
    keyboard::setTabOrder(ui->key_k, ui->key_l);
    keyboard::setTabOrder(ui->key_l, ui->key_z);
    keyboard::setTabOrder(ui->key_z, ui->key_x);
    keyboard::setTabOrder(ui->key_x, ui->key_c);
    keyboard::setTabOrder(ui->key_c, ui->key_v);
    keyboard::setTabOrder(ui->key_v, ui->key_b);
    keyboard::setTabOrder(ui->key_b, ui->key_n);
    keyboard::setTabOrder(ui->key_n, ui->key_m);
    keyboard::setTabOrder(ui->key_m, ui->key_caps);
    keyboard::setTabOrder(ui->key_caps, ui->key_del);
    keyboard::setTabOrder(ui->key_del, ui->key_ok);
}

/**
 * @brief keyboard::Init_MAP_Key_value
 */
void keyboard::Init_MAP_Key_value(void)
{
    keyboardmap.insert('a',ui->key_a);
    keyboardmap.insert('b',ui->key_b);
    keyboardmap.insert('c',ui->key_c);
    keyboardmap.insert('d',ui->key_d);
    keyboardmap.insert('e',ui->key_e);
    keyboardmap.insert('f',ui->key_f);
    keyboardmap.insert('g',ui->key_g);
    keyboardmap.insert('h',ui->key_h);
    keyboardmap.insert('i',ui->key_i);
    keyboardmap.insert('j',ui->key_j);
    keyboardmap.insert('k',ui->key_k);
    keyboardmap.insert('l',ui->key_l);
    keyboardmap.insert('m',ui->key_m);
    keyboardmap.insert('n',ui->key_n);
    keyboardmap.insert('o',ui->key_o);
    keyboardmap.insert('p',ui->key_p);
    keyboardmap.insert('q',ui->key_q);
    keyboardmap.insert('r',ui->key_r);
    keyboardmap.insert('s',ui->key_s);
    keyboardmap.insert('t',ui->key_t);
    keyboardmap.insert('u',ui->key_u);
    keyboardmap.insert('v',ui->key_v);
    keyboardmap.insert('w',ui->key_w);
    keyboardmap.insert('x',ui->key_x);
    keyboardmap.insert('y',ui->key_y);
    keyboardmap.insert('z',ui->key_z);
}

/**
 * @brief keyboard::Google_PinyinInit
 */
void keyboard::Google_PinyinInit(const char* datapath ,const char* userdatapt)
{
    QFileInfo info(datapath);
    qDebug() << info.size();

    if (!ime_pinyin::im_open_decoder(datapath,
                                     userdatapt))
    {
        qDebug("%s[%d] open pinyin dictionary failed", __func__, __LINE__);
        return;
    }

    /*初始化英文模式,隐藏拼音区域*/
    ui->key_pinyininput->setHidden(true);
    ui->NEXTpushButton->setHidden(true);
    ui->LASTpushButton->setHidden(true);
}

/**
 * @brief keyboard::ZhWigdetInit
 */
void keyboard::ZhResultWigdetInit()
{
    customerqpushbutton *strbut;
    /*依据最大设定进行初始化*/
    for(quint16 i = 0;i < CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX*CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX;i++)
    {
        strbut = new customerqpushbutton(this);

        /*加入映射表*/
        Resultmap.insert(i ,strbut);

        /*设置属性*/
        strbut->setObjectName((QString::fromUtf8("strbut")));
        strbut->setText(QString::fromUtf8(""));
        strbut->setGeometry(QRect(CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_H_X(i), CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_Y_X(i), CHINESESEARCH_BLOCKSTYLE_RECT_WIDTH, CHINESESEARCH_BLOCKSTYLE_RECT_END_Y));
        strbut->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
    "background-color: rgb(64, 65, 66);"));

        /*默认隐藏状态*/
        strbut->setHidden(true);

        /*连接点击选中信号*/
        connect(strbut ,&customerqpushbutton::clicked ,this ,&keyboard::slotResult);
    }
}

/**
 * @brief keyboard::SetResultHidden
 */
void keyboard::SetResultHidden()
{
    /*隐藏中文结果显示*/
    for(quint16 i = 0;i < CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX*CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX;i++)
    {
        Resultmap[i]->setHidden(true);
    }
}

/**
 * @brief keyboard::showKeyboard
 * @param title
 * @param str
 */
void keyboard::showKeyboard(QString title ,QString str)
{
    set_editTips(title);
    set_editBox(str);
    this->show();
}

/**
 * @brief keyboard::set_editTips
 * @param title
 */
void keyboard::set_editTips(QString title)
{
    ui->keyboardtitlelabel->setText(title);
}

/**
 * @brief keyboard::set_editBox
 * @param str
 */
void keyboard::set_editBox(QString str)
{
   ui->keyboardeditbox->setText(str);
}

/**
 * @brief keyboard::set_keyboardmode
 * @param mode
 */
void keyboard::set_keyboardmode(KEYBOARD_MODE mode)
{
    switch(mode)
    {
        case ANY:
            SetEnableNUM(true);
            SetEnableEN(true);
            break;
        case NUM_ONLY:
            SetEnableNUM(true);
            SetEnableEN(false);
            break;
        case EN_ONLY:
            SetEnableNUM(false);
            SetEnableEN(true);
            break;
    }
}

/**
 * @brief keyboard::SetEnableNUM
 * @param state
 */
void keyboard::SetEnableNUM(bool state)
{
    ui->key_0->setEnabled(state);
    ui->key_1->setEnabled(state);
    ui->key_2->setEnabled(state);
    ui->key_3->setEnabled(state);
    ui->key_4->setEnabled(state);
    ui->key_5->setEnabled(state);
    ui->key_6->setEnabled(state);
    ui->key_7->setEnabled(state);
    ui->key_8->setEnabled(state);
    ui->key_9->setEnabled(state);
    if(state)
    {
        ui->key_0->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                   "background-color: rgb(64, 65, 66);"));
    }
    else
    {
        ui->key_0->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
        ui->key_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                   "background-color: rgb(64, 65, 66);"));
    }
}

/**
 * @brief keyboard::SetEnableNUM
 * @param state
 */
void keyboard::SetEnableEN(bool state)
{
    for(int i = 'a';i <= 'z';i++)
    {
         keyboardmap[i]->setEnabled(state);
         if(state)
         {
             keyboardmap[i]->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                        "background-color: rgb(64, 65, 66);"));
         }
         else
         {
             keyboardmap[i]->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                        "background-color: rgb(64, 65, 66);"));
         }
    }
}

/**
 * @brief keyboard::set_capsLockmode
 * @param enable
 */
void keyboard::set_capsLockmode(bool enable)
{
    if(enable == true)
    {
        for(int i = 'a';i <= 'z';i++)
        {
            keyboardmap[i]->setText(keyboardmap[i]->text().toUpper());
        }
    }
    else
    {
        for(int i = 'a';i <= 'z';i++)
        {
            keyboardmap[i]->setText(keyboardmap[i]->text().toLower());
        }
    }
}

/**
 * @brief keyboard::on_key_caps_clicked
 */
void keyboard::on_key_caps_clicked()
{
    keycapsmode = !keycapsmode;
    if(keycapsmode)
    {
        //转为大写字母模式
        set_capsLockmode(true);
    }
    else
    {
        //转为小写字母模式
        set_capsLockmode(false);
    }
    /*转换符号*/
    UpdateSymbolDisplay();
}

/**
 * @brief keyboard::UpdateSymbolDisplay
 */
void keyboard::UpdateSymbolDisplay()
{
    /*清除缓冲区*/
    ResultStr.clear();

    if(keycapsmode)
    {
        /*关闭中文拼音输入区*/
        ui->key_pinyininput->setText("");
        ui->key_pinyininput->hide();
        /*关闭结果显示区*/
        SetResultHidden();
        ui->NEXTpushButton->setHidden(true);
        ui->LASTpushButton->setHidden(true);

        ui->key_point->setText(".");
        ui->key_comma->setText(",");
        ui->key_colon->setText(":");
        ui->key_virgule->setText("/");
        ui->key_dash->setText("_");
        ui->key_language->setText("en/zh");
        ui->key_caps->setText("CAPS");
    }
    else
    {
        ui->key_caps->setText("caps");
        /*判断是否需要恢复中文输入模式*/
        if(IsZhMode)
        {
            ui->key_pinyininput->setHidden(false);
            ui->key_language->setText("zh/en");
            /*中文标点符号*/
            ui->key_point->setText("。");
            ui->key_comma->setText("，");
            ui->key_colon->setText("：");
            ui->key_virgule->setText("\\");
            ui->key_dash->setText("-");
        }
        else
        {
            ui->key_pinyininput->setText("");
            ui->key_pinyininput->hide();
            SetResultHidden();
            ui->key_language->setText("en/zh");
            ui->key_point->setText(".");
            ui->key_comma->setText(",");
            ui->key_colon->setText(":");
            ui->key_virgule->setText("/");
            ui->key_dash->setText("_");
            ui->NEXTpushButton->setHidden(true);
            ui->LASTpushButton->setHidden(true);
        }
    }
}

/**
 * @brief keyboard::on_key_ok_clicked
 */
void keyboard::on_key_ok_clicked()
{
    ime_pinyin::im_flush_cache();
    /*清除结果缓冲区*/
    ResultStr.clear();
    IsZhMode = keycapsmode = false;
    /*更新为隐藏态*/
    SetResultHidden();
    UpdateSymbolDisplay();
    this->hide();
    emit editisModifiedok(ui->keyboardeditbox->text());
}

/**
 * @brief keyboard::on_key_1_clicked
 */
void keyboard::on_key_1_clicked()
{
    QString str = "1";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_2_clicked
 */
void keyboard::on_key_2_clicked()
{
    QString str = "2";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_3_clicked
 */
void keyboard::on_key_3_clicked()
{
    QString str = "3";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_4_clicked
 */
void keyboard::on_key_4_clicked()
{
    QString str = "4";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_5_clicked
 */
void keyboard::on_key_5_clicked()
{
    QString str = "5";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_6_clicked
 */
void keyboard::on_key_6_clicked()
{
    QString str = "6";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_7_clicked
 */
void keyboard::on_key_7_clicked()
{
    QString str = "7";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_8_clicked
 */
void keyboard::on_key_8_clicked()
{
    QString str = "8";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_9_clicked
 */
void keyboard::on_key_9_clicked()
{
    QString str = "9";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_0_clicked
 */
void keyboard::on_key_0_clicked()
{
    QString str = "0";
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::writeABC
 * @param index
 */
void keyboard::writeABC(int index)
{
    QString str;
    str = keyboardmap[index]->text();
    AppendOnKeyInputWindow(str);
}

/**
 * @brief keyboard::on_key_q_clicked
 */
void keyboard::on_key_q_clicked()
{
    writeABC('q');
}

/**
 * @brief keyboard::on_key_w_clicked
 */
void keyboard::on_key_w_clicked()
{
    writeABC('w');
}

/**
 * @brief keyboard::on_key_e_clicked
 */
void keyboard::on_key_e_clicked()
{
    writeABC('e');
}

/**
 * @brief keyboard::on_key_r_clicked
 */
void keyboard::on_key_r_clicked()
{
    writeABC('r');
}

/**
 * @brief keyboard::on_key_t_clicked
 */
void keyboard::on_key_t_clicked()
{
    writeABC('t');
}

/**
 * @brief keyboard::on_key_y_clicked
 */
void keyboard::on_key_y_clicked()
{
    writeABC('y');
}

/**
 * @brief keyboard::on_key_u_clicked
 */
void keyboard::on_key_u_clicked()
{
    writeABC('u');
}

/**
 * @brief keyboard::on_key_i_clicked
 */
void keyboard::on_key_i_clicked()
{
    writeABC('i');
}

/**
 * @brief keyboard::on_key_o_clicked
 */
void keyboard::on_key_o_clicked()
{
    writeABC('o');
}

/**
 * @brief keyboard::on_key_p_clicked
 */
void keyboard::on_key_p_clicked()
{
    writeABC('p');
}

/**
 * @brief keyboard::on_key_a_clicked
 */
void keyboard::on_key_a_clicked()
{
    writeABC('a');
}

/**
 * @brief keyboard::on_key_s_clicked
 */
void keyboard::on_key_s_clicked()
{
    writeABC('s');
}

/**
 * @brief keyboard::on_key_d_clicked
 */
void keyboard::on_key_d_clicked()
{
    writeABC('d');
}

/**
 * @brief keyboard::on_key_f_clicked
 */
void keyboard::on_key_f_clicked()
{
    writeABC('f');
}

/**
 * @brief keyboard::on_key_g_clicked
 */
void keyboard::on_key_g_clicked()
{
    writeABC('g');
}

/**
 * @brief keyboard::on_key_h_clicked
 */
void keyboard::on_key_h_clicked()
{
    writeABC('h');
}

/**
 * @brief keyboard::on_key_j_clicked
 */
void keyboard::on_key_j_clicked()
{
    writeABC('j');
}

/**
 * @brief keyboard::on_key_k_clicked
 */
void keyboard::on_key_k_clicked()
{
    writeABC('k');
}

/**
 * @brief keyboard::on_key_l_clicked
 */
void keyboard::on_key_l_clicked()
{
    writeABC('l');
}

/**
 * @brief keyboard::on_key_z_clicked
 */
void keyboard::on_key_z_clicked()
{
    writeABC('z');
}

/**
 * @brief keyboard::on_key_x_clicked
 */
void keyboard::on_key_x_clicked()
{
    writeABC('x');
}

/**
 * @brief keyboard::on_key_c_clicked
 */
void keyboard::on_key_c_clicked()
{
    writeABC('c');
}

/**
 * @brief keyboard::on_key_v_clicked
 */
void keyboard::on_key_v_clicked()
{
    writeABC('v');
}

/**
 * @brief keyboard::on_key_b_clicked
 */
void keyboard::on_key_b_clicked()
{
    writeABC('b');
}

/**
 * @brief keyboard::on_key_n_clicked
 */
void keyboard::on_key_n_clicked()
{
    writeABC('n');
}

/**
 * @brief keyboard::on_key_m_clicked
 */
void keyboard::on_key_m_clicked()
{
    writeABC('m');
}

/**
 * @brief keyboard::on_key_language_clicked
 */
void keyboard::on_key_language_clicked()
{
    IsZhMode = !IsZhMode;
    UpdateSymbolDisplay();
}

/**
 * @brief keyboard::on_key_comma_clicked
 */
void keyboard::on_key_comma_clicked()
{
    QString str = ui->key_comma->text();
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_dash_clicked
 */
void keyboard::on_key_dash_clicked()
{
    QString str = ui->key_dash->text();
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_virgule_clicked
 */
void keyboard::on_key_virgule_clicked()
{
    QString str = ui->key_virgule->text();
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_colon_clicked
 */
void keyboard::on_key_colon_clicked()
{
    QString str = ui->key_colon->text();
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_at_clicked
 */
void keyboard::on_key_at_clicked()
{
    QString str = ui->key_at->text();
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::on_key_point_clicked
 */
void keyboard::on_key_point_clicked()
{
    QString str = ui->key_point->text();
    AppendOnKeyInputWindow(str ,true);
}

/**
 * @brief keyboard::AppendOnKeyInputWindow
 * @param str
 */
void keyboard::AppendOnKeyInputWindow(QString &str ,bool result)
{
   /*追加文本到键盘输入缓冲区，进行中文识别*/
    if(IsZhMode && keycapsmode == false && result == false)
    {
        /*中文模式则将输入重定向到keyinput空间中，进行搜素*/
        ui->key_pinyininput->setText(ui->key_pinyininput->text()+str);
    }
    else
    {
        /*英文模式直接将结果输入到文本区*/
        ui->keyboardeditbox->setText(ui->keyboardeditbox->text()+str);
    }
}


/**
 * @brief keyboard::on_key_del_clicked
 */
void keyboard::on_key_del_clicked()
{
    if(IsZhMode && keycapsmode == false && ui->key_pinyininput->text().isEmpty() == false)
    {
        /*中文模式则将输入重定向到keyinput*/
        ui->key_pinyininput->backspace();
    }
    else
    {
        /*英文模式直接删除文本区，单次*/
        ui->keyboardeditbox->backspace();
    }
}

/**
 * @brief keyboard::on_key_pinyininput_textChanged
 * @param arg1
 */
void keyboard::on_key_pinyininput_textChanged(const QString &arg1)
{
    ime_pinyin::char16 buf[256] = {0};
    /*重置至第一页结果*/
    CurrentResultPageNUM = 1;
    ResultStr.clear();
    /*获得本次搜索到数目*/
    size_t ResultCnt = ime_pinyin::im_search(arg1.toUtf8().data(), static_cast<size_t>(arg1.size()));

    /*保存搜索结果*/
    for(size_t i = 0; i < ResultCnt; ++i)
    {
        if(i >= SEARCH_RESULT_NUM_MAX)
        {
            break;
        }
        ime_pinyin::im_get_candidate(i, buf, 255);
        if(ResultStr.size() <= i)
        {
            ResultStr.append(QString::fromUtf16(buf));
        }
        else
        {
            ResultStr.replace(i ,QString::fromUtf16(buf));
        }
    }
    /*统计页数*/
    TotalResultPageNUM = ResultStr.size()>1?(ResultStr.size()-1)/(CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX*CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX)+1:1;

    /*更新一次搜索结果显示*/
    ShowSearchResult(ResultStr);
}

/**
 * @brief keyboard::ShowSearchResult
 * @param num
 */
void keyboard::ShowSearchResult(QStringList &result)
{
    for(size_t i = 0;i < CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX*CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX;i++)
    {
        if(result.size() <= i+(CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX*CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX*(CurrentResultPageNUM-1)))
        {
            Resultmap[i]->setText(QString(""));
            Resultmap[i]->setHidden(true);
        }
        else
        {
            Resultmap[i]->setText(QString::fromUtf8(result.value(i+(CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX*CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX*(CurrentResultPageNUM-1))).toUtf8()));
            Resultmap[i]->setHidden(false);
        }
    }

    /*显示翻页键*/
    if(CurrentResultPageNUM*CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX*CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX < result.size())
    {
        ui->NEXTpushButton->setText(QString("=>%1").arg(CurrentResultPageNUM));
        ui->NEXTpushButton->setHidden(false);
    }
    else
    {
        ui->NEXTpushButton->setHidden(true);
    }
}

/**
 * @brief keyboard::ShowNextPageResult
 */
void keyboard::ShowNextPageResult()
{
    if(CurrentResultPageNUM < TotalResultPageNUM)
    {
        CurrentResultPageNUM++;
        CurrentResultPageNUM = CurrentResultPageNUM>TotalResultPageNUM?1:CurrentResultPageNUM;
        /*更新显示*/
        if(CurrentResultPageNUM > 1)
        {
            ui->LASTpushButton->setHidden(false);
            /*更新一次搜索结果显示*/
            ShowSearchResult(ResultStr);
        }
        else
        {
            ui->LASTpushButton->setHidden(true);
        }
    }
    else
    {
        ui->NEXTpushButton->setHidden(true);
    }
    ui->NEXTpushButton->setText(QString("=>%1").arg(CurrentResultPageNUM));
    ui->LASTpushButton->setText(QString("%1<=").arg(CurrentResultPageNUM));
}

/**
 * @brief keyboard::ShowLastPageResult
 */
void keyboard::ShowLastPageResult()
{
    if(CurrentResultPageNUM > 1)
    {
        CurrentResultPageNUM--;
        CurrentResultPageNUM = CurrentResultPageNUM<1?TotalResultPageNUM:CurrentResultPageNUM;
        /*更新显示*/
        if(TotalResultPageNUM > CurrentResultPageNUM)
        {
            ui->NEXTpushButton->setHidden(false);
            /*更新一次搜索结果显示*/
            ShowSearchResult(ResultStr);
        }
        else
        {
            ui->NEXTpushButton->setHidden(true);
        }
    }
    else
    {
        /*翻页到头隐藏上翻键*/
        ui->LASTpushButton->setHidden(true);
    }
    ui->NEXTpushButton->setText(QString("=>%1").arg(CurrentResultPageNUM));
    ui->LASTpushButton->setText(QString("%1<=").arg(CurrentResultPageNUM));
}

/**
 * @brief keyboard::on_NEXTpushButton_clicked
 */
void keyboard::on_NEXTpushButton_clicked()
{
    ShowNextPageResult();
}

/**
 * @brief keyboard::on_LASTpushButton_clicked
 */
void keyboard::on_LASTpushButton_clicked()
{
    ShowLastPageResult();
}

/**
 * @brief keyboard::on_key_clear_clicked
 */
void keyboard::on_key_clear_clicked()
{
    ui->keyboardeditbox->setText("");
}

/**
 * @brief keyboard::slotResult
 */
void keyboard::slotResult(customerqpushbutton *pbtn)
{
    /*搜索结果选中,发送到输入端*/
    QString str = pbtn->text();
    AppendOnKeyInputWindow(str ,true);
}

/* ---------------------------- end of file ----------------------------------*/
