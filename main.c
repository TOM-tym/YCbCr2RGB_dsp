#include <stdio.h>
#include <math.h>

extern int multiply32(int a, int b, int pos);
extern int YCbCr2RGB(int a, int b, int c, int pos);
float show_fix_point(int, int);
int main(){
	int res = YCbCr2RGB(1,2,3,20);
	float res_S = show_fix_point(res,20);
	printf("%f",res_S);
	return 0;
}
int test_main(){
	int t = -4;
	int dividend[] = {0x00129FBE,0x00129FBE,0xFFFD8000,0xFFFA7EFA,0x00641000,0x00010000,0x02000000};
	int divisor[] = {0x00020000,0x7FF29FAE,0x000092A0,0xFFFD8000,0x00021000,0x00030000,0x03000000};
	int i = 0;
	int pos = 20;
	for (;i<7;i++){
		int a = dividend[i];
		int b = divisor[i];
		int res = multiply32(a,b,pos);
		float s_a = show_fix_point(a,pos);
		float s_b = show_fix_point(b,pos);
		float s_res = show_fix_point(res,pos);
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
