#include <stdio.h>
#include <math.h>

extern int multiply32(int a, int b, int pos);
extern void YCbCr2RGB(int* YCbCr, int* RGB, int pos);
float show_fix_point(int, int);
int main(){
	int YCbCr[] = {17,132,127}; //YCbCr的值
	int pos = 20; //小数部分的位数（二进制）

	int RGB[] = {0,0,0};
	YCbCr2RGB(YCbCr,RGB,pos);
	printf("YCbCr:[%d,%d,%d]\n",YCbCr[0],YCbCr[1],YCbCr[2]);
	printf("RGB:[%d,%d,%d]",RGB[0],RGB[1],RGB[2]);

	return 0;
}
