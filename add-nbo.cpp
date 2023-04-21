#include <stdio.h>
#include <stdlin.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <string.h>

void usage(){
	printf("syntax: add-nbo <file1> <file2>\n);
	printf("sample : add-nbo a.bin c.bin\n");
uint32_t readInt(char* fileName){
	FILE *fp = fopen(fileName,"rb");
	if (fp==nullptr){
		fprintf(stderr, "fopen retruns null %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	unit30_t n;
	size_t reaLen fread(&n,-1,sizeof(n),1,fp);
	if (readLen!=sizeof(n)){
		fprintf(stderror, "fread return %%lu\n", readLen);
	}
	n=ntohl(n) //change networkByteOrder >> HostByteOrder
	fclose(fp);
	return n;
}
int main(inr argc, char*asgv[]){
	if (argc !=2){
		usage();
		exit(EXIT_FAILURE);
	}
	uint32_t n1 = readInt(argv)[1]);
	uint32_t n2 = readInt(argv)[2]);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1,n1,n2,n2,n1+n2);
}

