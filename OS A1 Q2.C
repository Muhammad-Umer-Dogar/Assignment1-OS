#include <stdio.h>
struct record
{
	char name[255];
	char roll[255];
	char email[255];
};
int main()
{
	int j=0,i=0,check,index;
	FILE *ptr;
	record records[3];
	for(i=0;i<3;i++)
	{
		records[i].name[0]='\0';
		records[i].roll[0]='\0';
		records[i].email[0]='\0';
	}
	char temp[255],fname[255];
	printf("%s", "Enter records file name (if not enter 0): ");
	scanf("%s",fname);
	if(fname[0]!='0')
	{
		char character;
		ptr=fopen(fname,"r");
		if(ptr)
		{
			for(int i=0;i<3;i++)
			{
				j=0;
				while(character!='\n' && !feof(ptr))
				{
					character=fgetc(ptr);
					records[i].name[j]=character;
					j++;
				}
				character='\0';
				records[i].name[j-1]=character;
				j=0;
				while(character!='\n' && !feof(ptr))
				{
					character=fgetc(ptr);
					records[i].roll[j]=character;
					j++;
				}
				character='\0';
				records[i].roll[j-1]=character;
				j=0;
				while(character!='\n' && !feof(ptr))
				{
					character=fgetc(ptr);
					records[i].email[j]=character;
					j++;
				}
				character='\0';
				records[i].email[j-1]=character;
			}
		printf("%s", "File loaded\n");
		}
		else
			printf("%s", "File not found\n");
	}
	while(1)
	{
		printf("%s", "Enter 1 to add record\n");
		printf("%s", "Enter 2 to read record\n");
		printf("%s", "Enter 3 to delete record\n");
		printf("%s", "Enter 0 to exit\n");
		printf("%s", "Select any option: ");
		scanf("%d", &check);
		if(check==0)
		{
			if(fname[0]!='0')
				ptr = fopen(fname,"w");
			else
			{
				printf("%s", "Enter file name to store data: ");
				scanf("%s",fname);
				ptr = fopen(fname,"w");
			}
			for(i=0;i<3;i++)
			{
				j=0;
				while(records[i].name[j]!='\0')
				{
					fputc(records[i].name[j], ptr);
					j++;
				}
				fputc('\0', ptr);
				fputc('\n', ptr);
				j=0;
				while(records[i].roll[j]!='\0')
				{
					fputc(records[i].roll[j], ptr);
					j++;
				}
				fputc('\0', ptr);
				fputc('\n', ptr);
				j=0;
				while(records[i].email[j]!='\0')
				{
					fputc(records[i].email[j], ptr);
					j++;
				}
				fputc('\0', ptr);
				fputc('\n', ptr);
			}
			printf("%s", "Records saved in the file\n");
			break;
		}
		if(check==1)
		{
			printf("%s", "Record number: ");
			scanf("%d",&index);
			printf("%s", "Enter Name: ");
			scanf("%s", &records[index].name);
			printf("%s", "Enter Roll number: ");
			scanf("%s", &records[index].roll);
			printf("%s", "Enter Email: ");
			scanf("%s", &records[index].email);
		}
		if(check==2)
		{
			printf("%s", "Record number: ");
			scanf("%d",&index);
			printf("%s","NAME: ");
			printf("%s\n",records[index].name);				
			printf("%s","Roll number: ");
			printf("%s\n",records[index].roll);
			printf("%s","Email: ");
			printf("%s\n",records[index].email);
		}
		if(check==3)
		{
			printf("%s", "Record number: ");
			scanf("%d",&index);
			records[index].name[0]='\0';
			records[index].roll[0]='\0';
			records[index].email[0]='\0';
		}
	}
	return 0;
}