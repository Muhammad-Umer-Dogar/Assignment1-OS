#include <stdio.h>
int find_occurances(char fname[],char subString[])
{
	FILE *ptr=fopen(fname,"r");
	if(ptr)
	{
		char character;
		int i=0,counter=0;
		while(!feof(ptr))
		{
			character = fgetc(ptr);
			i=0;
			while(subString[i]!='\0')
			{
				if(subString[i]!=character)
					break;
				else
				{
					i++;
					character = fgetc(ptr);	
				}
			}
			if(subString[i]=='\0')
			{
				counter++;
				character = fgetc(ptr);
			}
			else
			{
				while(character!=' ' && !feof(ptr))
					character = fgetc(ptr);
			}
		}
		return counter;
	}
	else
		return -1;
}
int main(int n,char** arg)
{
	int occurances=find_occurances(arg[1],arg[2]);
	if(occurances==-1)
		printf("%s", "FIle not Found\n");
	else
		printf("Number of occurances of substring: %d", occurances);
	return 0;
}