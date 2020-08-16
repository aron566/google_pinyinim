/**
  ******************************************************************************
  * @file    customerqpushbutton.cpp
  * @author  aron566
  * @version v1.0
  * @date    2020-08-16
  * @brief   自定义按钮控件.
  ******************************************************************************
  */
/* Header includes -----------------------------------------------------------*/
#include "customerqpushbutton.h"
/* Macro definitions ---------------------------------------------------------*/
/* Type definitions ----------------------------------------------------------*/
/* Variable declarations -----------------------------------------------------*/
/* Variable definitions ------------------------------------------------------*/
/* Function declarations -----------------------------------------------------*/
/* Function definitions ------------------------------------------------------*/
/**
 * @brief customerqpushbutton::customerqpushbutton
 * @param parent
 */
customerqpushbutton::customerqpushbutton(QWidget *parent)
    :QPushButton(parent)
{

}

/**
 * @brief customerqpushbutton::customerqpushbutton
 * @param text
 * @param parent
 */
customerqpushbutton::customerqpushbutton(const QString &text, QWidget *parent)
    :QPushButton(text ,parent)
{

}

/**
 * @brief customerqpushbutton::customerqpushbutton
 * @param icon
 * @param text
 * @param parent
 */
customerqpushbutton::customerqpushbutton(const QIcon& icon, const QString &text, QWidget *parent)
    :QPushButton(icon ,text ,parent)
{

}

/**
 * @brief customerqpushbutton::~customerqpushbutton
 */
customerqpushbutton::~customerqpushbutton()
{

}

/**
 * @brief customerqlabel::mouseReleaseEvent
 * @param ev
 */
void customerqpushbutton::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    emit clicked(this);
}
/* ---------------------------- end of file ----------------------------------*/
