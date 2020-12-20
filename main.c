#include <stdio.h>
#include <math.h>

extern int multiply32(int a, int b, int pos);
extern void YCbCr2RGB(int* YCbCr, int* RGB, int pos);
float show_fix_point(int, int);
int main(){
	test_main();
	int YCbCr[] = {17,132,127};
	int RGB[] = {0,0,0};
	int pos = 20;
	YCbCr2RGB(YCbCr,RGB,pos);
	// float res_Y = show_fix_point(YCbCr[0],20);
	// float res_Cb = show_fix_point(YCbCr[1],20);
	// float res_Cr = show_fix_point(YCbCr[2],20);
	printf("[%d,%d,%d]",YCbCr[0],YCbCr[1],YCbCr[2]);
	// float res_R = show_fix_point(RGB[0],20);
	// float res_G = show_fix_point(RGB[1],20);
	// float res_B = show_fix_point(RGB[2],20);
	printf("[%d,%d,%d]",RGB[0],RGB[1],RGB[2]);

	return 0;
}
int test_main(){
	int dividend[] = {0x01100000,0xFFF00000,0x00400000,0xFFF00000,0x00400000};
	int divisor[] = {0x00129FBE,0x00166E97,0xFFFA7EFA,0xFFF49375,0x001C5A1c};
	int i = 0;
	int pos = 20;
	for (;i<5;i++){
		int a = dividend[i];
		int b = divisor[i];
		int res = multiply32(a,b,pos);
		float s_a = show_fix_point(a,pos);
		float s_b = show_fix_point(b,pos);
		float s_res = show_fix_point(res,pos);
		printf("%x * %x = %x  ",a,b,res);
		printf("%f * %f = %f\n",s_a,s_b,s_res);

	}return 0;
}
float show_fix_point(int a, int pos){
	int integer = a>>pos;
	int i =pos;
	float result = 0;
	for (; i>0; i--){
		if (a & 0x00000001 ==1)
			result += pow(2,-i);
		a = a >> 1;
	}
	float res = (float)integer + result;
	//printf("%f",res);
	return res;
}
