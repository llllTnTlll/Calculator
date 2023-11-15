/*
 * calculate.h
 *
 *  Created on: Nov 15, 2023
 *      Author: zhiyuan
 */

#ifndef INC_CALCULATE_H_
#define INC_CALCULATE_H_

#include <stack>
#include <string>

namespace CALCULATE{

class Calculate{
private:
	std::stack<char> optStack;
	std::stack<double> numStack;

	//获取运算符优先级
	int getLevel(char opt) const;
	//进行计算
	double doCalcu();

public:
	std::string operand;    //显示在屏幕上的数
	std::string suffix;     //后缀表达式
	//获取输入内容
	void getInput(char opt);

};

}

#endif /* INC_CALCULATE_H_ */
