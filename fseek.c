# include <stdio.h>

int main ()
{
	FILE *fp;

	fp = fopen("file.txt","w+");
	fputs("This is runoob.com", fp);

	// from the begin of the file
	// fseek( fp, 7, SEEK_SET );
	// fputs(" C Programming Langauge", fp);
	// fclose(fp);
	// This is C Programming Langauge

	// fseek( fp, 7, SEEK_CUR );
	// fputs(" C Programming Langauge", fp);
	// fclose(fp);
	// // 5468 6973 2069 7320 7275 6e6f 6f62 2e63
	// // 6f6d 0000 0000 0000 0020 4320 5072 6f67
	// // 7261 6d6d 696e 6720 4c61 6e67 6175 6765

	// fseek( fp, -7, SEEK_CUR );
	// fputs(" C Programming Langauge", fp);
	// fclose(fp);
	// // This is run C Programming Langauge

	// fseek( fp, -1, SEEK_CUR );
	// fputs(" C Programming Langauge", fp);
	// fclose(fp);
	// This is runoob.co C Programming Langauge

	// fseek( fp, 7, SEEK_END );
	// fputs(" C Programming Langauge", fp);
	// fclose(fp);

	// 5468 6973 2069 7320 7275 6e6f 6f62 2e63
	// 6f6d 0000 0000 0000 0020 4320 5072 6f67
	// 7261 6d6d 696e 6720 4c61 6e67 6175 6765


	// fseek( fp, -1, SEEK_END);
	// fputs(" C Programming Langauge", fp);
	// fclose(fp);
	// // This is runoob.co C Programming Langauge
   

	fseek( fp, 0, SEEK_END);
	fputs(" C Programming Langauge", fp);
	fclose(fp);
	// This is runoob.com C Programming Langauge

	// int fseek(FILE *stream, long int offset, int whence)
	// C 库函数 int fseek(FILE *stream, long int offset, int whence) 
	// 设置流 stream 的文件位置为给定的偏移 offset，
	// 参数 offset 意味着从给定的 whence 位置查找的字节数

	// +: from left to right;
	// -: from right to left

   return(0);
}