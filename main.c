#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_number(const char *filename){
	FILE* file;
	file = fopen(filename, "rb");
	
	if (file == NULL){
		printf("Error: Unable to open file!");
		exit(1);
	}

	uint32_t number;
	uint32_t size = fread(&number, sizeof(uint32_t), 1, file);
	if(size != 1){
		printf("Error reading from file!");
		fclose(file);
		exit(1);
	}

	fclose(file);

	return ntohl(number);
}


int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Error : %s", argv[0]);
		return -1;
	}

	uint32_t number1 = read_number(argv[1]);
	uint32_t number2 = read_number(argv[2]);
	
	uint32_t sum = number1 + number2;

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", number1, number1, number2, number2, sum, sum);

	return 0;
}

