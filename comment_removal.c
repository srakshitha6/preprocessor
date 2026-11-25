#include"header.h"
void comment(FILE *fp,FILE *fs)
{
	char ch[1000];
	int i=0,t;
	while(fgets(ch,sizeof(ch),fp)!=NULL)
	{
	i=0;
		while(ch[i]!='\0')//
		{
			if(ch[i]=='/'&&ch[i+1]=='/')
			break;
			else if(ch[i]=='/'&&ch[i+1]=='*')
			{
			t=0;
				for(i;ch[i]!='\0'&&ch[i]!='\n';i++)
					if(ch[i]=='*'&&ch[i+1]=='/')
					{
					t=1;
						i+=2;
						break;

					}
			 if(t==0)
			{
			while(fgets(ch,sizeof(ch),fp)!=NULL)
			{
				for(i=0;ch[i]!='\0'&&ch[i]!='\n';i++)
					if(ch[i]=='*'&&ch[i+1]=='/')
					{
					t=1;
						i+=2;
						break;

			}
			if(t==1)
			break;
			}
			}
			}
			else
			fputc(ch[i],fs);
			i++;
		}
	}
}
