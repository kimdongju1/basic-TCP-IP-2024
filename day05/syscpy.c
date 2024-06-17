#include <stdio.h>
#include <fcntl.h>
#define BUF_SIZE 3	// 배열의 길이를 최소한으로 구성

int main(int argc, char *argv[])
{
	int fd1, fd2;	// fd1, fd2에 저장되는 것은 파일 디스크립터!
	int len;
	char buf[BUF_SIZE];

	fd1=open("news.txt", O_RDONLY);
	fd2=open("cpy.txt", O_WRONLY|O_CREAT|O_TRUNC);

	while((len=fread(fd1, buf, sizeof(buf)))>0)
		fwrite(fd2, buf, len);

	pclose(fd1);
	pclose(fd2);
	return 0;
}
