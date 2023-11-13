GZHU grade 10 object oriented programming experiments personal backup  
====
This repository is created for personal backup.  
Highly NOT recommand using codes in this repo to submit homework.  
Why "object oriented programming" are all single file?  
At here I would like to blame my oop teacher. He never told us about it. At the end of the term, I was submitting my course design taught by another teacher. She blamed me that why all programs are single file? I ... have nothing to say about that ε-(‐ω‐；)

expriment 1  
---
* 1  
  定义一个score类，其中包括私有数据成员和公有成员函数，即  
  >num &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;学号  
  >Math &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;高等数学成绩  
  >English &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;英语成绩  
  >Programming &nbsp;&nbsp;程序设计成绩  
  >inscore() &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;输入学号和各科成绩，并且计算平均成绩  
  >showscore() &nbsp;&nbsp;&nbsp;&nbsp;输出学号和各科成绩

  使用score类，输入某班n（事先不能确定）个学生的学号和各科成绩，然后求各个学生的平均成绩，并列表输出学生的学号、各科成绩和平均成绩。  

* 3  
建立一个复数类imaginary，其私有数据成员x和y表示复数的实部和虚部，构造函数imaginary用于对复数的实部和虚部初始化，友员函数add,sub,mul和div分别用于进行复数的加、减、乘和除法运算，静态函数show用于显示运算结果。在主函数中，实例化两个复数，并输入一个运算符，按运算符选择相应的友员函数进行复数运算，然后输出运算结果。

expriment 2  
----
* 1  
  以下是Point类的定义以及重载运算符“<<”和“>>”的算法的基本实现。请增加重载运算符“+”等的实现，必要时可能需要相应修改重载运算符“<<”和“>>”的实现。请对增加的实现功能和修改之处做适当说明。  
  In this case I override >> as << and << as >> reversely.  
* 2  
  编写程序，有两个均为3行3列的矩阵ml和m2，求两个矩阵之和。重载运算符“＋”、“>>”和“<<”，使之能用于矩阵相加、输入和输出。  

expirment 3  
----
* 1  
编写一个人员信息管理系统。这个系统的功能是：交互式的实现校园人员信息的录入与显示。  
分析：  
学校里，主要有四类人员：大学本科学生、教师、研究生和助教。  
大学本科生每周有固定的学时数。教师除了固定的学时数外，还有每周的教学时数。研究生除了固定的学时数外，每周还可以自由做一定的研究。助教生除了上课外，还要做研究和一定的教学工作。人员的基本信息包括姓名、编号、性别、身份证号、总学时数以及每周固定学时数。各个人员之间的关系： people类派生出student 类和teacher类，student 类派生出graduate类， graduate类和teacher类派生出TA类。  
In this case I make two programs. One using polymorphism and one didn't.  

expirment 4  
----
* 1  
  函数模板实验：用函数模板方法编写程序，对给各种不同类型的三个数分别求最大数。  
* 2  
  编程序创建一个类模板，可以对不同的数据类型的数组分别进行初始化、添加数据、求和、求平均值、显示数组等功能。  

expirmemt 5
----
* 1  
简单的管理系统的设计：如人事、工资、学生成绩等。（要求部分功能实现）。
