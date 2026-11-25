#include"header.h"
int main (int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage: ./a.out filename\n");
		return 0;
	}
	FILE *fp=fopen(argv[1],"r");
	FILE *fs=fopen("temp.txt","w");
	if(fp==0)
	{
		printf("no such file presented\n");
		return 0;
	}
	comment(fp,fs);
	fclose(fp);
	fclose(fs);

	fp=fopen("temp.txt","r");
	fs=fopen("temp1.txt","w");
	if(fp==0)
	{
		printf("no such file present\n");
		return 0;
	}
	macro(fp,fs);
	fclose(fp);
	fclose(fs);

	fp=fopen("temp1.txt","r");
	fs=fopen("outputfile.i","w");
	if(fp==0)
	{
		printf("no such file\n");
		return 0;
	}
	header(fp,fs);
	fclose(fp);
	fclose(fs);

}
