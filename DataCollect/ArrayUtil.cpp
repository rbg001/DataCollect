#pragma once
#pragma execution_character_set("utf-8")
#include "ArrayUtil.h"


//b 是一个指向 string 数组的指针
char ** ArrayUtil::getArr(std::string * b, int length){
	//第2个* 代表char * 指向字符数组
	//第1个* 是指向 字符数组的指针
	char* *q = new char*[length];

	for (int i = 0; i < length; i++)
	{
		b = b + i;
		char * _cp = new char[100];
		strcpy(_cp, b->c_str());
		q[i] = _cp;
		b = b - i;

	}

	return q;
}