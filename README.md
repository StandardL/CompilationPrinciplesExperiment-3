# 编译原理课程实验3 - TINY扩充语言的语法树生成

## 实验内容

### 扩充或改写Tiny语句的语法

1. 实现改写书写格式的新if语句；
2. 增加for循环；
3. 扩充算术表达式的运算符号：+= 加法赋值运算符号（类似于C语言的+=）、求余%、乘方^，
4. 扩充扩充比较运算符号：=（等于），>(大于)、<=(小于等于)、>=(大于等于)、<>(不等于)等运算符号，
5. 增加正则表达式，其支持的运算符号有：  或(|)  、连接(&)、闭包(#)、括号( ) 、可选运算符号（？）和基本正则表达式。 
6. 增加位运算表达式，其支持的位运算符号有 and(与)、or（或）、 not(非），如果对位运算不熟悉，可以参考C/C++的位运算。

### 对应的语法规则

1. 把TINY语言原有的if语句书写格式
    if_stmt-->if exp then stmt-sequence end  |  | if exp then stmt-sequence else stmt-sequence end 
    改写为：
    if_stmt-->if(exp) stmt-sequence else stmt-sequence | if(exp) stmt-sequence

2. for语句的语法规则：
   （1) for-stmt-->for identifier:=simple-exp  to  simple-exp  do  stmt-sequence enddo    步长递增1
     (2) for-stmt-->for identifier:=simple-exp  downto  simple-exp  do  stmt-sequence enddo    步长递减1

3. += 加法赋值运算符号、求余%、乘方^等运算符号的文法规则请自行组织。
4. =（等于），>(大于)、<=(小于等于)、>=(大于等于)、<>(不等于)等运算符号的文法规则请自行组织。
5. 为tiny语言增加一种新的表达式——正则表达式，其支持的运算符号有：  或(|)  、连接(&)、闭包(#)、括号( ) 、可选运算符号（？）和基本正则表达式，对应的文法规则请自行组织。
6. 为tiny语言增加一种新的语句，ID:=正则表达式  
7. 为tiny语言增加一种新的表达式——位运算表达式，其支持的运算符号有  and(与)  、or (或)、非(not)。
8. 为tiny语言增加一种新的语句，ID:=位运算表达式  
9. 为了实现以上的扩充或改写功能，还需要注意对原tiny语言的文法规则做一些相应的改造处理。 

### 根据提示构建的文法规则

```
G[stmt]
stmt -> assign-stmt
assign-stmt -> id := exp | id += exp | id := REEXP
exp -> BITOR [BITOR-OP BITOR]
BITOR-OP -> or
BITOR -> BITAND [BITAND-OP BITAND]
BITAND-OP -> and
BITAND -> sim-exp[CP-OP sim-exp]
CP-OP -> < | > | = | <= | >= | <>
sim-exp -> term {addop term}
addop -> + | -
term -> power {mulop power|
mulop-> * | / | %
power -> BITNOT {powerup BITNOT}
power-op -> ^
BITNOT -> [BITNOT-OP] factor
BITNOT-OP -> not
factor -> (exp) | number | id

G[REEXP]
REEXP -> RE
RE -> RE “|” RT | RT
RT -> RT “&” RC | RC
RC -> # | ? | RF
RF -> (RE) | number | id
```

## 实验要求

1. 要提供一个源程序编辑的界面，以让用户输入源程序（可输入，可保存、可打开源程序）
2. 可由用户选择是否生成语法树，并可查看所生成的语法树。
3. 实验3的实现只能选用的程序设计语言为：C++
4. 要求应用程序的操作界面应为Windows界面。
5. 应该书写完善的软件文档

## 💻程序

### 截图

**软件主界面**

![软件主界面](D:\Coder\Github Repos\CompilationPrinciplesExperiment-3\images\软件主界面.png)

![软件主界面2](D:\Coder\Github Repos\CompilationPrinciplesExperiment-3\images\软件主界面2.png)

**软件通知示例**

![软件通知](D:\Coder\Github Repos\CompilationPrinciplesExperiment-3\images\软件通知.png)

![分析结束通知](D:\Coder\Github Repos\CompilationPrinciplesExperiment-3\images\分析结束通知.png)

### 🧪测试数据

共2组测试数据，已放入[Test instance文件夹]().

## 🧭编译

### 环境要求

#### Qt 6.5.3

- Qt Design Studio 4.2.0
- Qt 6.5.3
  - MSVC 2019 64-bit
  - MinGW 11.2.0 64-bit
  - Qt 5 Compatibility Module
  - Qt Shader Tools
  - Additional Libraries
- Developer and Designer Tools
  - Qt Creator 11.0.2
  - Qt Creator 11.0.2 CDB Debugger Support
  - Debugging Tools for Windows
  - MinGW 11.2.0 64-bit
  - Qt Installer Framwork 4.6
  - CMake 3.24.2
  - Ninja 1.10.2

#### Visual Studio 2022

选择安装**使用C++的桌面开发**

<img src="D:\Coder\Github Repos\CompilationPrinciplesExperiment-3\images\VS组件.png" alt="image-20230926211152531" style="zoom:67%;" />

进入到Visual Studio 2022，在**扩展**>**管理扩展**>**联机**（**Extensions** > **Manage Extensions** > **Online**）处搜索安装Qt Visual Studio Tools.

<img src="D:\Coder\Github Repos\CompilationPrinciplesExperiment-3\images\VS插件.png" alt="image-20230926211819218" style="zoom:80%;" />

重启Visual Studio 2022。

点击**扩展**>**Qt VS Tools**>**Qt Versions**，确保已勾选MSVC编译器。若无可手动添加MSVC编译器路径：\\ ${Qt安装目录} \\ {Qt版本号} \ msvc2019_64 \ bin \ qmake.exe

#### 编译方法

使用Visual Studio打开目录下TinyGUI.sln，选择Debug - x64或Release - x64即可开始编译运行。

## ☁未来展望

- [ ] QT界面美化
- [ ] UnitTest

## 🔗其他链接

- [Console(CLI)版本](https://github.com/StandardL/ComplieExp2-Console)
