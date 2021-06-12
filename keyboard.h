/**
 *  @file keyboard.h
 *
 *  @date 2020-08-14
 *
 *  @author aron566
 *
 *  @brief 软键盘实现
 *
 *  @version V1.0
 */
#ifndef KEYBOARD_H
#define KEYBOARD_H
/** Includes -----------------------------------------------------------------*/
#include <QMainWindow>
#include <QPushButton>
#include <QMap>
#include <pinyinime.h>
#include "customerqpushbutton.h"
/** Private includes ---------------------------------------------------------*/

/** Private defines ----------------------------------------------------------*/
#if defined(VIRTUALKEYBOARD_LIBRARY)
#  define VIRTUALKEYBOARD_EXPORT Q_DECL_EXPORT
#else
#  define VIRTUALKEYBOARD_EXPORT Q_DECL_IMPORT
#endif
/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

QT_BEGIN_NAMESPACE
namespace Ui { class keyboard; }
QT_END_NAMESPACE

class VIRTUALKEYBOARD_EXPORT keyboard : public QMainWindow
{
    Q_OBJECT
public:
    explicit keyboard(QWidget *parent = nullptr ,const char* datapath = nullptr ,const char* userdatapt = nullptr);
    ~keyboard();
    void InitTabOrder(void);
    void Init_MAP_Key_value(void);
public:
    QMap<int,QPushButton *>keyboardmap;
    QMap<size_t,QPushButton *>Resultmap;
    bool keycapsmode = false;
    bool IsZhMode = false;
private:
    const char *dict_datapath = nullptr;
    const char *dict_userdatapath = nullptr;
    QStringList ResultStr;
    quint16 CurrentResultPageNUM = 1;
    quint16 TotalResultPageNUM = 1;
public:
    enum KEYBOARD_MODE
    {
        NUM_ONLY = 0,/**< 数字模式*/
        EN_ONLY,/**< 英文模式*/
        ANY,/**< 全功能*/
    };
    void showKeyboard(QString title = "键入xx的内容：" ,QString str = "2020");
    void set_editTips(QString title = "键入xx的内容：");
    void set_editBox(QString str = "2020");
    void set_keyboardmode(KEYBOARD_MODE mode);
private:
    void Google_PinyinInit(const char* datapath = nullptr ,const char* userdatapt = nullptr);
    void ZhResultWigdetInit();
    void set_capsLockmode(bool enable);
    void UpdateSymbolDisplay();
    void writeABC(int index);
    void AppendOnKeyInputWindow(QString &str,bool result = false);
    void ShowSearchResult(QStringList &result);
    void ShowNextPageResult();
    void ShowLastPageResult();
    void SetResultHidden();
    void SetEnableNUM(bool state);
    void SetEnableEN(bool state);
signals:
    void editisModifiedok(QString);
private slots:

	void on_key_clear_clicked();
	
    void on_key_caps_clicked();

    void on_key_del_clicked();

    void on_key_ok_clicked();
	
    void on_key_1_clicked();

    void on_key_2_clicked();

    void on_key_3_clicked();

    void on_key_4_clicked();

    void on_key_5_clicked();

    void on_key_6_clicked();

    void on_key_7_clicked();

    void on_key_8_clicked();

    void on_key_9_clicked();

    void on_key_0_clicked();

    void on_key_q_clicked();

    void on_key_w_clicked();

    void on_key_e_clicked();

    void on_key_r_clicked();

    void on_key_t_clicked();

    void on_key_y_clicked();

    void on_key_u_clicked();

    void on_key_i_clicked();

    void on_key_o_clicked();

    void on_key_p_clicked();

    void on_key_a_clicked();

    void on_key_s_clicked();

    void on_key_d_clicked();

    void on_key_f_clicked();

    void on_key_g_clicked();

    void on_key_h_clicked();

    void on_key_j_clicked();

    void on_key_k_clicked();

    void on_key_l_clicked();

    void on_key_z_clicked();

    void on_key_x_clicked();

    void on_key_c_clicked();

    void on_key_v_clicked();

    void on_key_b_clicked();

    void on_key_n_clicked();

    void on_key_m_clicked();

    void on_key_language_clicked();

    void on_key_comma_clicked();

    void on_key_dash_clicked();

    void on_key_virgule_clicked();

    void on_key_colon_clicked();

    void on_key_at_clicked();

    void on_key_point_clicked();

    void on_key_pinyininput_textChanged(const QString &arg1);

    void on_NEXTpushButton_clicked();

    void on_LASTpushButton_clicked();

    void on_key_clear_clicked();

    void slotResult(customerqpushbutton *pbtn);

private:
    Ui::keyboard *ui;
};
#endif // KEYBOARD_H

/******************************** End of file *********************************/
