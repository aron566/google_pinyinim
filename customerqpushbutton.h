/**
 *  @file customerqpushbutton.h
 *
 *  @date 2020-08-16
 *
 *  @author aron566
 *
 *  @brief 自定按钮控件
 *
 *  @version V1.0
 */
#ifndef CUSTOMERQPUSHBUTTON_H
#define CUSTOMERQPUSHBUTTON_H
/** Includes -----------------------------------------------------------------*/
#include <QPushButton>
/** Private includes ---------------------------------------------------------*/

/** Private defines ----------------------------------------------------------*/

/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/
/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/
/**
 * @brief The customerqpushbutton class
 */
class customerqpushbutton : public QPushButton
{
    Q_OBJECT

public:
    explicit customerqpushbutton(QWidget *parent = nullptr);
    explicit customerqpushbutton(const QString &text, QWidget *parent = nullptr);
    customerqpushbutton(const QIcon& icon, const QString &text, QWidget *parent = nullptr);
    ~customerqpushbutton();
signals:
    void clicked(customerqpushbutton *pbtn);
protected:
    virtual void mouseReleaseEvent(QMouseEvent *ev);
};

#endif // CUSTOMERQPUSHBUTTON_H
/******************************** End of file *********************************/
