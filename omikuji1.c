#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TM 32000

void delay_ms(unsigned int ms);

char *uranai_str(unsigned char r_num);

void print_uranai(char *result_str);

int mode = 0;
int main(void)
{
	unsigned char i;
	char j = 0, k =2;
	srand((unsigned)time(NULL));

	char *moji[] = {
		"-O-O-O-O-O-O-O-O-O-O-O-O\nO-                    O-\n-O",
		"O-O-O-O-O-O-O-O-O-O-O-O-\n-O                    -O\nO-",
		"-O\nO-                    O-\n-O-O-O-O-O-O-O-O-O-O-O-O\n",
		"O-\n-O                    -O\nO-O-O-O-O-O-O-O-O-O-O-O-\n"
	};

	printf("  【占いをはじめます】  \n");
	while(1) {
		printf("エンターキーをおしてください。\n");
		char c = getchar();
		if(c=='\n')
			break;
	}

	system("clear\n");


	for(i=0;i<8;i++) {
		printf("%s", moji[j]);
		printf("     【判定中】     ");
		j = (j==1) ? 0:1;
		printf("%s", moji[k]);
		k = (k==3) ? 2:3;
		delay_ms(3000);
		system("clear\n");
		delay_ms(500);
	}
	delay_ms(4000);


	unsigned char r_num = rand() % 5;
	char *result_str = uranai_str(r_num);

	print_uranai(result_str);

	return 0;
}


void delay_ms(unsigned int ms)
{
	volatile unsigned long k, m;
	for(k=0;k<ms;k++)
		for(m=0;m<TM;m++);
}

char *uranai_str(unsigned char r_num)
{
	char *p_str;
	switch(r_num) {
		case 0:
			mode = 0;
			p_str =  "OO大吉です!おめでとう!OO";
			break;
		case 1:
			mode = 1;
			p_str =  "OO     小吉です!      OO";
			break;
		case 2:
			mode = 2;
			p_str =  "--     吉です.        --";
			break;
		case 3:
			mode = 3;
			p_str =  "//     凶です...      //";
			break;
		case 4:
			mode = 4;
			p_str =  "×× 大凶ですヨ...残念! ××";
			break;
	}
	return p_str;

}

void print_uranai(char *result_str)
{
	if(mode==0) {
		printf("OOOOOOOOOOOOOOOOOOOOOOOO\n");
		printf("OO                    OO\n");
		printf("%s\n", result_str);
		printf("OO                    OO\n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOO\n");
	}
	else if(mode==1) {
		printf("OOOOOOOOOOOOOOOOOOOOOOOO\n");
		printf("OO                    OO\n");
		printf("%s\n", result_str);
		printf("OO                    OO\n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOO\n");
	}
	else if(mode==2) {
		printf("------------------------\n");
		printf("--                    --\n");
		printf("%s\n", result_str);
		printf("--                    --\n");
		printf("------------------------\n");
	}
	else if(mode==3) {
		printf("////////////////////////\n");
		printf("//                    //\n");
		printf("%s\n", result_str);
		printf("//                    //\n");
		printf("////////////////////////\n");
	}
	else if(mode==4) {
		printf("××××××××××××××××××××××××\n");
		printf("××                    ××\n");
		printf("%s\n", result_str);
		printf("××                    ××\n");
		printf("××××××××××××××××××××××××\n");
	}
}
