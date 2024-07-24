#include <stdio.h>
#include <stdint.h> //for uint32_t
#include <netinet/in.h>
#include <stdlib.h> //for exit()

uint32_t open_read_file(const char *filename){
	FILE *file;
	file = fopen(filename, "r");
	
	if (file == NULL){
		printf("Error : Cannot Open File. Sorry!");
		exit(1);
	}

	uint32_t buffer;
	size_t size;
	size = fread(&buffer, sizeof(buffer), 1, file);

	if(size<1){
		printf("Error : Failed read 4bytes...");
		exit(1);
	}

	fclose(file);

	return ntohl(buffer);
}


int main(int argc, char* argv[]){
	if (argc != 3){
		printf("Sorry. Something is WRONG...");
		return -1;
	}

	uint32_t text[2];
	text[0] = open_read_file(argv[1]);
	text[1] = open_read_file(argv[2]);

	uint32_t sum = text[0] + text[1];

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", text[0], text[0], text[1], text[1], sum, sum);

	return 0;
}
