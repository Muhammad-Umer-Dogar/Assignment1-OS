#include <stdio.h>
int main(int n,char** arg)
{
	char data[65535],temp;
	FILE *ptr=fopen(arg[1],"r");
	int i=0,j=0,index=0,size=0;
	while(!feof(ptr))
	{
		data[size]=fgetc(ptr);
		size++;
	}
	while(index<size-1)
	{
		if(data[index]==' ' || data[index]=='\0' || data[index]=='.' || data[index]=='\n')
		{
			i=index-1;
			while(i>j)
			{
				if(data[j]=='a' || data[j]=='A' || data[j]=='e' || data[j]=='E' || data[j]=='i' || data[j]=='I' || data[j]=='o' || data[j]=='O' || data[j]=='u' || data[j]=='U')
				{
					j++;
					continue;
				}
				if(data[i]=='a' || data[i]=='A' || data[i]=='e' || data[i]=='E' || data[i]=='i' || data[i]=='I' || data[i]=='o' || data[i]=='O' || data[i]=='u' || data[i]=='U')
				{
					i--;
					continue;
				}
				temp=data[i];
				data[i]=data[j];
				data[j]=temp;
				j++;
				i--;
			}
			j=index+1;
		}
		index++;
	}
	for(i=0;i<size-1;i++)
		printf("%c",data[i]);
	ptr=fopen(arg[1],"w");
	for(i=0;i<size-1;i++)
		fputc(data[i], ptr);
	return 0;
}