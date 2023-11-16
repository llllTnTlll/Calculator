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

	std::string suffix;            //后缀表达式
	std::string operand;           //显示在屏幕上的数

	void addToSuffix(char& c);
	void addToSuffix(std::string& str);
	void clrStack();
	bool isNumber(std::string& str);
	double getNumStackValue();
	int getLevel(char& opt) const;
	bool doCalcu();
public:
	//获取输入内容
	void getInput(char opt);
	//获取当前数据缓存区内容
	inline std::string getOperand() const{
		return operand;
	}
};

}

#endif /* INC_CALCULATE_H_ */
