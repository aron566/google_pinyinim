# google_pinyinim
谷歌拼音输入法移植至QT
# 移植方法
## 直接带入源码编译
### 加入头文件进入你的工程
## 链接方式
1、clone工程到你的本地目录，打开项目
2、动态库的生成：修改项目中.pro文件中TEMPLATE = **app**改为**lib**即可生成动态库文件

```bash
# 生成库文件
TARGET = virtualkeyboard
TEMPLATE = lib
```

3、动态库的基础上静态库的生成：

```bash
# 生成库文件
TARGET = virtualkeyboard
TEMPLATE = lib
# 生成静态库
CONFIG += staticlib
```

4、取出工程中所有.h文件及编译生成的库文件
5、将.h文件加入到你需要用到的工程中，.pro文件中链接此动态库文件即可

## 修改相关参数
### 修改输入法界面尺寸大小
- 打开`virtualkeyboard.h`文件,文件中定义皆以**pixel**为单位
  修改其中`UI_KEYBOARDWINDOW_WIDTH`与`UI_KEYBOARDWINDOW_HEIGHT`宏定义为多少pixel
  修改显示中文结果的间隙大小：水平间隙`CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_X_GAP`，垂直间隙`CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_Y_GAP`
  修改每页显示数目：列数目`CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX`，行数目`CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX`

  **其他修改直接看文件中说明**

  # 使用方式

  ## 初始化部分
  
  1、实例化键盘
  
  ```cpp
  keyboard *pKeyboard = new keyboard;
  ```
  
  2、连接键盘输入结束信号
  
  ```cpp
  connect(pKeyboard ,&keyboard::editisModifiedok ,this ,slotKeyboardReturn);
  ```
  
  6、槽函数处理，参数str为输入的内容
  
  ```cpp
  void slotKeyboardReturn(QString &str)
  {
      /*do something...*/
  }
  ```
  
  ## 调用键盘
  
  ```cpp
  /*设置显示键盘*/
  void showKeyboard(QString title = "键入xx的内容：" ,QString str = "2020");
  /*单独设置标题*/
  void set_editTips(QString title = "键入xx的内容：");
  /*单独设置输入框内容*/
  void set_editBox(QString str = "2020");
  /*设置键盘模式*/
  void set_keyboardmode(KEYBOARD_MODE mode);
  ```

**1、调整键盘模式**

```c
enum KEYBOARD_MODE
{
    NUM_ONLY = 0,/**< 数字模式,字母键将不可用*/
    EN_ONLY,/**< 英文模式,数字键将不可用*/
    ANY,/**< 全功能,默认模式*/
};
```

eg：

```cpp
pKeyboard->set_keyboardmode(keyboard::NUM_ONLY);
```

## 互动

1、主线程的主界面部分管理

```cpp
private:
    QWidget* pLastCallobj;/**< 保存着上次隐藏的页面，也可不用，但需要调用键盘的页面不隐藏*/
    QLineEdit *pLastCallwidget;/**< 保存上次调用键盘的控件*/
```

2、主线程建立槽，调用键盘显示

```cpp
void slotprocessedit(QWidget *,QLineEdit *,QString title ,QString edittext)
{
    pLastCallobj = pObject;
    pLastCallwidget = pwidget;
	pKeyboard->showKeyboard(title ,edittext);
}
```

3、主线程，连接键盘输入完成信号

```cpp
connect(pKeyboard ,&keyboard::editisModifiedok ,this ,slotKeyboardReturn);
```

```cpp
void slotKeyboardReturn(QString &str)
{
    /*重新显示子级页面*/
    pLastCallobj->show();
    /*将键盘的字符串给编辑框*/
    pLastCallwidget->setText(str);
}
```



4、主线程子级页面，输入控件被点击处理

```cpp
signals:
    void show_keyboard(QWidget * ,QLineEdit *,QString,QString);
```

```cpp
/*在parameter界面，clientip输入框被点击*/
void parameter::on_clientip_Pressed()
{
    emit show_keyboard(this ,this->ui->clientip,"输入客户端IP",this->ui->clientip->text());
    this->hide();
}
```

5、连接信号与槽

```cpp
connect(parameterui ,&parameter::show_keyboard ,this ,&MainWindow::slotprocessedit);/*parameterui为主界面的子级页面*/
```

