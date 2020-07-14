# Polynomial

##  安装和使用

linux系统使用命令 

```bash
sudo bash ./install_linux.sh
```

来进行安装。之后重启系统或者 

```bash
source /etc/profile
```

使得环境变量生效



使用时，请在代码头文件中添加：

``` c++
#include <polynomial.h>
```

在编译时使用如下选项：

```
-lpoly
```



## 基础功能

poly类支持多项式之间的+-*/%运算和幂运算，支持从输出流输出

poly类分两种type，定义了常数typei表示int型poly，常数typed表示double型poly

int型poly默认对998244353取模，想改模数请自行到/usr/include/poly/poly.h里面修改，请注意要支持ntt

int型poly和double型poly运算会得到double型poly



### 构造方法

以下是一些构造方法的例子

``` c++
poly A = {1,2,3};
poly B = {4.0,5.0,6.0};
poly C (100); //长度为100的全零多项式

int s[] = {6,6,6,6};
poly D (s+1,s+4);
```

### 成员函数

```c++
poly A;
A[i];//返回x^i的系数，有两个重载，一个带引用一个不带
A.size();//返回A的大小
A.type();//返回A的类型
```

### 其他功能

```c++
cout<<format(A)<<endl; //可将多项式以格式化的形式输出

polyvar &x = polyvar::x;
poly B = (x^3)+2*x+1; //使用polyvar::x来自然语言式地定义多项式（请注意^运算符的优先级）
```

### 更多计算功能

使用polycalc类来进行$\mod{x^n}$意义下的多项式运算。

```c++
polycalc C(n); //指定x^n中，n的值

C.setprecision(n);//重新设置n
    
C.derivative(A);// 求导数运算
C.intgration(A); //积分运算，常数项设置为0

C.inv(A); //求逆
C.ln(A); //求ln
C.exp(A); // 求exp
```



