#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<stdint.h>

void usage()
{
   printf("syntax : add-nbo <file1> <file2>");
   printf("sample : add-nbo a.bin b.bin");
}
uint32_t readInt(char* fileName)
{
   FILE* fp = fopen(fileName, "rb");
   if (fp == nullptr)
   {
      fprintf(stderr, "fopen returns null%s\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   uint32_t n;
   size_t readLen = fread(&n, 1, sizeof(n), fp);
   if (readLen != sizeof(n))
   {
      fprintf(stderr, "fread return %lu\n", readLen);
      exit(EXIT_FAILURE)
   }

   n = ntohl(n);
   fclose(fp);
   return n;

}


int main(int argc, char* argv[])
{
   if (argc != 3)
   {
      usage();
      exit(EXIT_FAILURE);
   }

   uint32_t n1 = readInt(argv[1]);
   uint32_t n2 = readInt(argv[1]);
   printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2);

}
