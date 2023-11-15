/*
 * calculate.cpp
 *
 *  Created on: Nov 15, 2023
 *      Author: zhiyuan
 */

# include "calculate.h"

namespace CALCULATE{

int Calculate::getLevel(char opt) const{
	switch (opt) {
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case ')':
		return 3;
		}
}

void Calculate::getInput(char opt){
	//若输入字符是未完成的状态将其写入数字缓存区
	if(std::isdigit(opt)){
		operand += opt;
		//TODO 刷新屏幕
	}
	else{
		//若不是数字说明上一个操作数输入完毕 将其入栈
		numStack.push(std::stod(operand));
		operand = "";

		if(opt == '('){
			optStack.push(opt);
		}
		else if(opt == ')'){
			while (optStack.top() != '(') {
				suffix += optStack.top();
			}
		}
	}
}

}
