#include "console.h"

void CNS_PrintLine(char* message)
{
    puts(message);
}

void CNS_Print( char* message )
{
	printf("%s", message);
}

// this is ony supported on terminals that support ascii escape characters. so no cmd.exe
void table(const char *title, const char *mode)
{
	int f, b;
	printf("\n\033[1m%s\033[m\n bg\t fg\n", title);
	for (b = 40; b <= 107; b++) {
		if (b == 48) b = 100;
		printf("%3d\t\033[%s%dm", b, mode, b);
		for (f = 30; f <= 97; f++) {
			if (f == 38) f = 90;
			printf("\033[%dm%3d ", f, f);
		}
		puts("\033[m");
	}
}
