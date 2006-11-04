
#include <stdio.h>
#include <unistd.h>

#include "wsocks.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s command [...]\n", argv[0]);
		return -1;
	}
	putenv("LD_PRELOAD=" WSOCKS_LIB_PATH "/libwsocks.so");
	execvp(argv[1], &argv[1]);
	perror("Execute error");

	return -1;
}
