#include<boost/bind.hpp>
#include<boost/function.hpp>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

/**********************************
  boost::function使用示例

替代函数指针并提供更大的灵活性
boost::function 有两种使用形式：
1.根据函数的参数不同而决定使用的function1-function10
2.不论函数签名为何一律使用boost::function
**********************************/
int fun_add(int a,int b)
{
	return a+b;
}

double fun_div(double a,double b)
{
	return a/b;
}

class X
{
public:
	X(int _a,int _b):
		a(_a),b(_b){};

	int minus(){return a-b;}
private:
		int a;
		int b;
};
/*******************************************
	boost::bind 使用示例
	std::bindlist和std::bind2nd的结合体。提供一个
	任意的函数对象（仿函数）、函数、函数指针、成员
	函数指针。可绑定任意参数。
*******************************************/
int main(int arg,char *args[])
{
	boost::function<int (int,int)> fun1;
	fun1 = fun_add;
  std::cout<<fun1(3,4)<<std::endl;

	boost::function<double (double,double)> fun2;
	fun2 = fun_div;
	std::cout<<fun2(3.0,1.5)<<std::endl;

	boost::function<int (X*)> fun3;
	fun3 = &X::minus;
	X x(3,4);
	std::cout<<fun3(&x)<<std::endl;
	//bind示例
	std::cout<<boost::bind(fun_add,4,6)()<<std::endl;
	std::cout<<boost::bind(fun_div,5,2.5)()<<std::endl;
	fun3 = boost::bind(&X::minus,&x);
	std::cout<<fun3(&x)<<std::endl;

}
