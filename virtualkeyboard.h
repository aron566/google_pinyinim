/**
 *  @file virtualkeyboard.h
 *
 *  @date 2020-08-14
 *
 *  @author aron566
 *
 *  @brief 调用软件键盘接口，及相关配置
 *
 *  @version V1.0
 */
#ifndef VIRTUALKEYBOARD_H
#define VIRTUALKEYBOARD_H
/** Includes -----------------------------------------------------------------*/
#include "keyboard.h"

/** Private includes ---------------------------------------------------------*/

/** Private defines ----------------------------------------------------------*/
#define UI_KEYBOARDWINDOW_WIDTH     600U
#define UI_KEYBOARDWINDOW_HEIGHT    400U

/*中文结果起始高度，可大不可小*/
#define CHINESESEARCH_RESULT_START_Y  (UI_KEYBOARDWINDOW_HEIGHT*140/720)
/*高度，不可修改*/
#define CHINESESEARCH_RESULT_END_Y    (UI_KEYBOARDWINDOW_HEIGHT*330/720-CHINESESEARCH_RESULT_START_Y)
/*===设定搜索页面文本显示属性===*/
#define CHINESESEARCH_RECT_START_Y         (CHINESESEARCH_RESULT_START_Y)
#define CHINESESEARCH_RECT_END_Y           (CHINESESEARCH_RESULT_END_Y)
#define CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_X_GAP     (5U)        /*搜索结果页面矩形水平间隙*/
#define CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_Y_GAP     (5U)        /*搜索结果页面矩形垂直间隙*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX       (7U)        /*搜索结果页面最大允许每行矩形数目*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX       (3U)        /*搜索结果页面最大允许矩形行数目*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_LEFT_INVALID_LEN     (5U)   /*搜索结果页面左边不可用长度*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_RIGHT_INVALID_LEN    (UI_KEYBOARDWINDOW_WIDTH-UI_KEYBOARDWINDOW_WIDTH*1190/1280U)   /*搜索结果页面右边不可用长度*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_UP_INVALID_LEN       (5U)   /*搜索结果页面上边不可用长度*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_DOWN_INVALID_LEN     (0U)   /*搜索结果页面下边不可用长度*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_ORIGIN_Y        (CHINESESEARCH_RESULT_START_Y+CHINESESEARCH_BLOCKSTYLE_RECT_UP_INVALID_LEN)   /*搜索结果页面矩形起始Y*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_ORIGIN_X        (CHINESESEARCH_BLOCKSTYLE_RECT_LEFT_INVALID_LEN)

/*通过计算每矩形允许宽度X*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_WIDTH       \
((UI_KEYBOARDWINDOW_WIDTH-CHINESESEARCH_BLOCKSTYLE_RECT_LEFT_INVALID_LEN-CHINESESEARCH_BLOCKSTYLE_RECT_RIGHT_INVALID_LEN-(CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_X_GAP*(CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX+1)))/CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX)
/*通过计算每矩形允许高度Y*/
#define CHINESESEARCH_BLOCKSTYLE_RECT_END_Y       \
((CHINESESEARCH_RECT_END_Y-CHINESESEARCH_BLOCKSTYLE_RECT_DOWN_INVALID_LEN-CHINESESEARCH_BLOCKSTYLE_RECT_UP_INVALID_LEN-(CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_Y_GAP*(CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX+1)))/CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX)

/*计算多个视频矩形X相对坐标起点,数目从0开始则间隙X需+1，高度x不变*/
#define CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_H_X(X)   (CHINESESEARCH_BLOCKSTYLE_RECT_ORIGIN_X+CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_X_GAP*((X%CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX)+1)+CHINESESEARCH_BLOCKSTYLE_RECT_WIDTH*(X%CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX))
/*计算多个视频矩形Y相对坐标起点,数目从0开始则间隙X需+1，高度x不变*/
#define CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_Y_X(X)   (CHINESESEARCH_BLOCKSTYLE_RECT_ORIGIN_Y+CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_Y_GAP*((X/CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX)+1)+CHINESESEARCH_BLOCKSTYLE_RECT_END_Y*(X/CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX))
/** Exported typedefines -----------------------------------------------------*/

/** Exported constants -------------------------------------------------------*/

/** Exported macros-----------------------------------------------------------*/

#define GOOGLEPINGYIN_DATAFILE_PATH "G:/C_file/QT/MyVirtualKeyboard/data/dict_pinyin.dat"
#define USERPINGYIN_DATAFILE_PATH "G:/C_file/QT/MyVirtualKeyboard/data/user_dict_pinyin"

/** Exported variables -------------------------------------------------------*/
/** Exported functions prototypes --------------------------------------------*/

#endif // VIRTUALKEYBOARD_H
/******************************** End of file *********************************/
