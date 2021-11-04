#include "array.hpp"

array::array() {
	length = 10000;
	for (int i = 0; i < length; i++) {
		buffer[i] = i;
	}
}

void array::addItem(int item) {
	if (length < 10000) {
		buffer[length++] = item;
	}
}

int array::sum() {
	PROFILE_FUNCTION();
	int i, sum(0);
	for (i = 0; i < length; i++)
		sum += buffer[i];
	return sum;
}
/*
auto generated code by Debug X86 compiler:
	int i, sum(0);
00F1D2BE  mov         dword ptr [sum],0
	for (i = 0; i < length; i++)
00F1D2C5  mov         dword ptr [i],0
00F1D2CC  jmp         array::sum+67h (0F1D2D7h)
00F1D2CE  mov         eax,dword ptr [i]
00F1D2D1  add         eax,1
00F1D2D4  mov         dword ptr [i],eax
00F1D2D7  mov         eax,dword ptr [this]
00F1D2DA  mov         ecx,dword ptr [i]
00F1D2DD  cmp         ecx,dword ptr [eax]
00F1D2DF  jge         array::sum+83h (0F1D2F3h)
		sum += buffer[i];
00F1D2E1  mov         eax,dword ptr [i]
00F1D2E4  mov         ecx,dword ptr [this]
00F1D2E7  mov         edx,dword ptr [sum]
00F1D2EA  add         edx,dword ptr [ecx+eax*4+4]
00F1D2EE  mov         dword ptr [sum],edx
00F1D2F1  jmp         array::sum+5Eh (0F1D2CEh)
	return sum;
00F1D2F3  mov         eax,dword ptr [sum]
00F1D2F6  mov         dword ptr [ebp-110h],eax
00F1D2FC  lea         ecx,[timer__LINE__]
00F1D2FF  call        InstrumentationTimer::~InstrumentationTimer (0F11528h)
00F1D304  mov         eax,dword ptr [ebp-110h]
*/

int array::sum_a() {
	PROFILE_FUNCTION();
	__asm {
		mov ecx, this
		xor eax, eax
		xor edx, edx
		cmp [ecx].length, 0
		je end
		loop1 : add eax, [ecx].buffer[edx * 4]
		add edx, 1
		cmp edx, [ecx].length
		jb loop1
		end :
	}
	#pragma warning(disable:1011)
}

void array::multiply() {
	PROFILE_FUNCTION();
	int i;
	for (i = 0; i < length; i++)
		buffer[i] = buffer[i] * 3;
}
/*
void array::multiply() {
003D4390  push        ebp
003D4391  mov         ebp,esp
003D4393  sub         esp,0FCh
003D4399  push        ebx
003D439A  push        esi
003D439B  push        edi
003D439C  push        ecx
003D439D  lea         edi,[ebp-0FCh]
003D43A3  mov         ecx,3Fh
003D43A8  mov         eax,0CCCCCCCCh
003D43AD  rep stos    dword ptr es:[edi]
003D43AF  pop         ecx
003D43B0  mov         eax,dword ptr [__security_cookie (03ED014h)]
003D43B5  xor         eax,ebp
003D43B7  mov         dword ptr [ebp-4],eax
003D43BA  mov         dword ptr [this],ecx
003D43BD  mov         ecx,offset _53027E2C_array@cpp (03F1033h)
003D43C2  call        @__CheckForDebuggerJustMyCode@4 (03D196Ah)
	PROFILE_FUNCTION();
003D43C7  push        18h
003D43C9  lea         ecx,[timer__LINE__]
003D43CC  call        InstrumentationTimer::__autoclassinit2 (03D10FAh)
003D43D1  push        offset string "front() called on empty string" (03E9344h)
003D43D6  lea         ecx,[timer__LINE__]
003D43D9  call        InstrumentationTimer::InstrumentationTimer (03D1537h)
	int i;
	for (i = 0; i < length; i++)
003D43DE  mov         dword ptr [i],0
003D43E5  jmp         array::multiply+60h (03D43F0h)
003D43E7  mov         eax,dword ptr [i]
003D43EA  add         eax,1
003D43ED  mov         dword ptr [i],eax
003D43F0  mov         eax,dword ptr [this]
003D43F3  mov         ecx,dword ptr [i]
003D43F6  cmp         ecx,dword ptr [eax]
003D43F8  jge         array::multiply+81h (03D4411h)
		buffer[i] = buffer[i] * 3;
003D43FA  mov         eax,dword ptr [i]
003D43FD  mov         ecx,dword ptr [this]
003D4400  imul        edx,dword ptr [ecx+eax*4+4],3
003D4405  mov         eax,dword ptr [i]
003D4408  mov         ecx,dword ptr [this]
003D440B  mov         dword ptr [ecx+eax*4+4],edx
003D440F  jmp         array::multiply+57h (03D43E7h)
}
*/

void array::multiply_a() {
	PROFILE_FUNCTION();
	__asm {
		push ebx

		mov ecx, this
		xor ebx, ebx
		xor edx, edx
		cmp [ecx].length, 0
		je end
			loop1 : 
		mov ebx, [ecx].buffer[edx * 4]
		shl ebx, 1
		add ebx, [ecx].buffer[edx * 4]
		mov [ecx].buffer[edx * 4], ebx
		add edx, 1
		cmp edx, [ecx].length
		jb loop1
			end :

		pop ebx
	}
}

void array::multiply_var(int value) {
	PROFILE_FUNCTION();
	int i;
	for (i = 0; i < length; i++)
		buffer[i] = buffer[i] * value;
}
/*
int i;
	for (i = 0; i < length; i++)
009FC68E  mov         dword ptr [i],0
009FC695  jmp         array::multiply_var+60h (09FC6A0h)
009FC697  mov         eax,dword ptr [i]
009FC69A  add         eax,1
009FC69D  mov         dword ptr [i],eax
009FC6A0  mov         eax,dword ptr [this]
009FC6A3  mov         ecx,dword ptr [i]
009FC6A6  cmp         ecx,dword ptr [eax]
009FC6A8  jge         array::multiply_var+84h (09FC6C4h)
		buffer[i] = buffer[i] * value;
009FC6AA  mov         eax,dword ptr [i]
009FC6AD  mov         ecx,dword ptr [this]
009FC6B0  mov         edx,dword ptr [ecx+eax*4+4]
009FC6B4  imul        edx,dword ptr [value]
009FC6B8  mov         eax,dword ptr [i]
009FC6BB  mov         ecx,dword ptr [this]
009FC6BE  mov         dword ptr [ecx+eax*4+4],edx
009FC6C2  jmp         array::multiply_var+57h (09FC697h)
}
*/

void array::multiply_var_a(int value) {
	PROFILE_FUNCTION();
	__asm {
		push ebx
		push esi
		push edi

		mov ecx, this
		xor eax, eax
		xor ebx, ebx
		xor edx, edx
		xor esi, esi
		xor edi, edi
		cmp[ecx].length, 0
		je end

		loop1 :
		
			mov ebx, 1
			
				loop2:
					xor edi, edi
					inc edi
					;shl edi, ebx
					shl edi, 1
					;
					cmp ebx, 1
						je continu
						shl edi, 1
					continu:
					;

					cmp edi, dword ptr [value]
						jg end_if

						and edi, dword ptr [value]
						cmp edi, 1
							jl zero
							
							mov esi, [ecx].buffer[edx * 4]
							;shl esi, ebx
							shl esi, 1
							;
							cmp ebx, 1
								je continu1
								shl esi, 1
								continu1:
							;
							add eax, esi

						zero:
					inc ebx

					end_if:
					cmp edi, dword ptr[value]
						jle loop2


			add edx, 1
			cmp edx, [ecx].length
			jb loop1
		
		end :

		pop edi
		pop esi
		pop ebx
	}
}