#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>

#include "array.hpp"
#include "Timer.hpp"

double ipow(double x, int n) {
	unsigned int nn = abs(n);		// absolute value of n
	double y = 1.0;					// used for multiplication
	while (nn != 0) {				// loop for each bit in nn
		if (nn & 1) y *= x;			// multiply if bit = 1
		x *= x;						// square x
		nn >>= 1;					// get next bit of nn
	}
	if (n < 0) y = 1.0 / y;			// reciprocal if n is negative
	return y;						// return y = pow(x,n)
}

// MASM style inline assembly, 32 bit mode
double ipow1(double x, int n) {
	__asm {
		mov eax, n					// Move n to eax
									// abs(n) is calculated by inverting all bits and
									// adding 1 if n < 0:
		cdq							// Get sign bit into all bits of edx
		xor eax, edx				// Invert bits if negative
		sub eax, edx				// Add 1 if negative. Now eax = abs(n)
		fld1						// st(0) = 1.0
		jz L9						// End if n = 0
		fld qword ptr x				// st(0) = x, st(1) = 1.0
		jmp L2						// Jump into loop
		L1 :						// Top of loop
		fmul st(0), st(0)			// Square x
			L2 :					// Loop entered here
			shr eax, 1				// Get each bit of n into carry flag
			jnc L1					// No carry. Skip multiplication, goto next
			fmul st(1), st(0)		// Multiply by x squared i times for bit # i
			jnz L1					// End of loop. Stop when nn = 0
			fstp st(0)				// Discard st(0)
			test edx, edx			// Test if n was negative
			jns L9					// Finish if n was not negative
			fld1					// st(0) = 1.0, st(1) = x^abs(n)
			fdivr					// Reciprocal
			L9 :					// Finish
	}								// Result is in st(0)
#pragma warning(disable:1011) // Don't warn for missing return value
}

void function() {
	//InstrumentationTimer timer("function");
	PROFILE_FUNCTION();
	for (int i(0); i < 100; ++i)
		std::cout << "Hi!";
}



int main() {

	Instrumentor::Get().BeginSession("Profile");

	array a;
	a.sum();
	a.sum_a();

	a.multiply();
	a.multiply_a();

	Instrumentor::Get().EndSession();

	__asm {
		xor eax, eax
	}
}