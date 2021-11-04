#pragma once

#include "Timer.hpp"

class array
{
protected:
	int length;
	int buffer[10000];
public:
	array();
	void addItem(int item);

	int sum();
	int sum_a();

	void multiply();
	void multiply_a();

	void multiply_var(int value);
	void multiply_var_a(int value);
};
