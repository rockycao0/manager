#include<stdio.h>
#include<stdlib.h>

struct product
{
	int id;
	int num;
};

void option();
void inport(struct product *a);
void export(struct product *a);
void display();
int getline();
void find();

int main()
{
	int i;
	i = 0;
	struct product goods;
	FILE *fp;
	if ((fp = fopen("manager.txt", "w")) == NULL)
	{
		printf("fail to open the file\n");
		exit(1);
	}
	printf("enrter the ID\n");
	scanf("%d",&goods.id);
	fclose(fp);
	goods.num = 0;
	do
	{
		
		option();
		scanf_s("%d", &i);
		switch (i)
		{
		case 1:inport(&goods);
			break;
		case 2:export(&goods);
			break;
		case 3:display();
			break;
		case 4:find();
			break;
		default:;
		}
		int getline();
		system("cls");
	}while (i != 5);
	system("pause");
	return 0;
}

void option()
{
	printf("Product Storage Management\n");
	printf("-------------------------------\n");
	printf("1.Import product.\n");
	printf("2.Export product.\n");
	printf("3.display the information.\n");
	printf("4.find date.\n");
}
void inport(struct product *a)
{
	int i;
	FILE *fp;
	if ((fp = fopen("manager.txt", "a")) == NULL)
	{
		printf("fail to open the file\n");
		exit(1);
	}
	printf("please enter the number\n");
	scanf_s("%d", &i);
	a->num += i;
	fprintf(fp, "%d\t%d\n",a->id,a->num);
	fclose(fp);
}
void export(struct product *a)
{
	int i;
	FILE *fp;
	if ((fp = fopen("manager.txt", "a")) == NULL)
	{
		printf("fail to open the file\n");
		exit(1);
	}
	printf("please enter the number\n");
	scanf_s("%d", &i);
	a->num -= i;
	fprintf(fp, "%d\t%d\n",a->id, a->num);
	fclose(fp);
}
void display()
{
	FILE *fp;
	int number;
	char name[80];
	if ((fp = fopen("manager.txt", "r")) == NULL)
	{
		printf("fail to open the file\n");
		exit(1);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%s%d",name,&number);
		printf("%s\t%d\n", name, number);
	}
	system("pause");
	fclose(fp);
}
int getline()
{
	FILE *fp;
	int i = 0;
	int number;
	int id;
	if ((fp = fopen("manager.txt", "r")) == NULL)
	{
		printf("fail to open the file\n");
		exit(1);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d%d",&id, &number);
		i++;
	}
	return i;
}
void find()
{
	int i;
	int ID;
	int number;
	printf("enter the date\n");
	scanf("%d", &i);
	FILE *fp;
	if ((fp = fopen("manager.txt", "r")) == NULL)
	{
		printf("wrong\n");
		exit(1);
	}
	while (!feof(fp))
	{
		scanf("%d%d", &ID, &number);
		if (i == number)
		{
			printf("ID is %d", ID);
		}
	}
	fclose(fp);
}