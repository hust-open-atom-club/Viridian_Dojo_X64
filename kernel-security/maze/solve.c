#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

int main()
{
        init();
        print_desc();

        printf("当前挑战用户为: ");
        system("whoami");
        
        print_exit();

	return 0;
}