# google_pinyinim
谷歌拼音输入法移植至QT
# 移植方法
## 第一种直接带入源码编译
### 这个无需多讲，直接将所有的工程包含到你所需的工程中去即可，可查看.pro文件涉及哪些文件。
## 第二种链接方式
1、clone工程到你的本地目录，打开项目
2、动态库的生成：修改项目中.pro文件中TEMPLATE = **app**改为**lib**即可生成动态库文件

```bash
# 生成库文件
TARGET = virtualkeyboard
TEMPLATE = lib
```

3、静态库的生成（不会更新之前已生成的动态库文件！）：

```bash
# 生成库文件
TARGET = virtualkeyboard
TEMPLATE = lib
# 指定生成为静态库
CONFIG += staticlib
```

4、取出工程中所有.h文件及编译生成的库文件
5、将.h文件加入到**你需要用到的工程中**，.pro文件中链接此动态库文件即可

项目中`.pro`文件增加的内容如下：

```bash
# 软键盘
include(keyboard/keyboard.pri)

# 软键盘linux
unix:!macx: LIBS += -L$$PWD/keyboard/
unix:!macx: LIBS += -lvirtualkeyboard

# 软键盘windows
win32: LIBS += -L$$PWD/keyboard/
win32: LIBS += -lvirtualkeyboard
```

5.1、在你的工程中新建keyboard文件夹

5.2、在keyboard文件夹中新建keyboard.pri文件

填入如下内容：

```bash
HEADERS += \
    $$PWD/customerqpushbutton.h \
    $$PWD/keyboard.h \
    $$PWD/lib/atomdictbase.h \
    $$PWD/lib/dictbuilder.h \
    $$PWD/lib/dictdef.h \
    $$PWD/lib/dictlist.h \
    $$PWD/lib/dicttrie.h \
    $$PWD/lib/lpicache.h \
    $$PWD/lib/matrixsearch.h \
    $$PWD/lib/mystdlib.h \
    $$PWD/lib/ngram.h \
    $$PWD/lib/pinyinime.h \
    $$PWD/lib/pinyinime_global.h \
    $$PWD/lib/searchutility.h \
    $$PWD/lib/spellingtable.h \
    $$PWD/lib/spellingtrie.h \
    $$PWD/lib/splparser.h \
    $$PWD/lib/sync.h \
    $$PWD/lib/userdict.h \
    $$PWD/lib/utf16char.h \
    $$PWD/lib/utf16reader.h \
    $$PWD/virtualkeyboard.h
```

5.3、复制`customerqpushbutton.h` `keyboard.h` `virtualkeyboard.h`到`keyboard`文件夹

5.4、复制编译的动态库文件或者静态库文件到`keyboard`文件夹

5.5、在**keyboard**文件夹中新建**lib**文件夹

将克隆的工程中`googlelib`文件夹中所有.h后缀的文件复制到此

5.6、修改`keyboard.h` 中`#include <pinyinime.h>`改为 `#include <keyboard/lib/pinyinime.h>`

5.7、复制`data`目录下的词典文件到**keyboard**文件夹内，（在其他目标板上运行，需将词典复制过去，实例化时指定加载路径信息）

6、点击小锤子编译即可

7、如果动态库则上传动态库文件到特定硬件上

## 修改相关参数
### 修改输入法界面尺寸大小
- 打开`virtualkeyboard.h`文件,文件中定义皆以**pixel**为单位
  修改其中`UI_KEYBOARDWINDOW_WIDTH`与`UI_KEYBOARDWINDOW_HEIGHT`宏定义为多少pixel
  修改显示中文结果的间隙大小：水平间隙`CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_X_GAP`，垂直间隙`CHINESESEARCH_BLOCKSTYLE_MULTI_RECT_Y_GAP`
  修改每页显示数目：列数目`CHINESESEARCH_BLOCKSTYLE_RECT_H_NUM_MAX`，行数目`CHINESESEARCH_BLOCKSTYLE_RECT_V_NUM_MAX`

  **其他修改直接看文件中说明**

  # 使用方式

  输入框使用单一`QLineEdit`控件便于管理
  
  ## 初始化部分
  
  1、实例化键盘
  
  ```cpp
  keyboard *pKeyboard = new keyboard(this ,"谷歌词典文件路径" ,"用户词典文件路径");
  ```
  
  2、连接键盘输入结束信号
  
  ```cpp
  connect(pKeyboard ,&keyboard::editisModifiedok ,this ,&MainWindow::slotKeyboardReturn);
  ```
  
  6、槽函数处理，参数str为输入的内容
  
  ```cpp
  void MainWindow::slotKeyboardReturn(QString &str)
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
/*连接子界面要求显示键盘的信号*/
connect(parameterui ,&parameter::show_keyboard ,this ,&MainWindow::slotprocessedit);
```

```cpp
void MainWindow::slotprocessedit(QWidget *pObject ,QLineEdit *pwidget ,QString title ,QString edittext)
{
    pLastCallobj = pObject;
    pLastCallwidget = pwidget;
	pKeyboard->showKeyboard(title ,edittext);
}
```

3、主线程，连接键盘输入完成信号

```cpp
connect(pKeyboard ,&keyboard::editisModifiedok ,this ,&MainWindow::slotKeyboardReturn);
```

```cpp
void MainWindow::slotKeyboardReturn(QString str)
{
    /*重新显示子级页面*/
    pLastCallobj->show();
    /*将键盘的字符串给编辑框*/
    pLastCallwidget->setText(str);
}
```

4、主线程子级页面，输入控件被点击处理

QLineEdit控件有以下几个信号：

```cpp
// returnPressed：聚焦在控件上按下回车键时发出，通常用作不带触摸屏的环境
// selectionChanged：聚焦到时发出一次信号
// 连接信号：
connect(ui->clientiplineEdit ,&QLineEdit::selectionChanged ,this ,&parameter::on_clientip_Pressed);
connect(ui->clientiplineEdit ,&QLineEdit::returnPressed ,this ,&parameter::on_clientip_Pressed);
/*需要注意的是，当控件代码由UI设计器自动生成时，信号与槽的建立应当在UI设计器中完成*/
```

```cpp
signals:
    void show_keyboard(QWidget * ,QLineEdit *,QString,QString);
```

```cpp
/*在parameter界面，clientip输入框被点击*/
void parameter::on_clientip_Pressed()
{
    emit show_keyboard(this ,ui->clientip,"输入客户端IP" ,ui->clientip->text());
    this->hide();
}
```

5、连接信号与槽

```cpp
connect(parameterui ,&parameter::show_keyboard ,this ,&MainWindow::slotprocessedit);/*parameterui为主界面的子级页面*/
```

