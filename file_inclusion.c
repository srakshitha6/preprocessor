#include"header.h"
void header(FILE *fp,FILE *fs)
{
	char ch[1000],s[100],path[50]="/usr/include/",t[100],d[10]="#include",a[1000];
	int i,j,flag;
	while(fgets(ch,sizeof(ch),fp)!=NULL)
	{
		j=0;
		flag=0;
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]!=' ')
			{
				t[j++]=ch[i];
				t[j]='\0';
				if(strcmp(t,d)==0)
				{
				flag=1;
				i++;
				while(ch[i]==' '||ch[i]=='\t')
				i++;
					if(ch[i]=='<')
					{
						i++;
						j=0;
						while(ch[i]!='>'&&ch[i]!='\0')
							s[j++]=ch[i++];
						s[j]='\0';
							strcat(path,s);
							FILE *fd=fopen(path,"r");
							if(fd==0)
							{
								printf("no such headerfile\n");
								return;
							}
							while(fgets(a,sizeof(a),fd)!=NULL)
								fputs(a,fs);
								fclose(fd);
							strcpy(path,"/usr/include/");
						}
					else if(ch[i]=='"')
					{
						i++;
						j=0;
						while(ch[i]!='"'&&ch[i]!='\0')
							s[j++]=ch[i++];
						s[j]='\0';
							FILE *fd=fopen(s,"r");
							if(fd==0)
							{
							strcat(path,s);
							fd=fopen(path,"r");
							strcpy(path,"/usr/include");
							if(fd==0)
							{
								printf("no such headerfile\n");
								return;
							}
							}
							while(fgets(a,sizeof(a),fd)!=NULL)
								fputs(a,fs);
								fclose(fd);
							strcpy(path,"/usr/include/");
						}
						else
							fprintf(fs,"%s",s);
					break;
				}
			}
			}
			if(flag==0)
			fputs(ch,fs);
		}
	
	}
