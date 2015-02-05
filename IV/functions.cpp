#include "main.h"
#include <stdlib.h>
#include <string.h>


int CreateDB(const char *path)
{
	if(CheckFileExist(path))
	{
		printf("%s already exists.\nDelete file and try again.\n", path);
		return FALSE;
	}
	else
	{
		FILE *fp = NULL;
		fp = fopen(path, "wb");
		fclose(fp);
	}
	return TRUE;
}

int ReadRecord(FILE *fp, long offset, Client *rec)
{
	/*�������  ReadRecord()  ��������� ������ ������ � 
	�������  ID �� �����  fp  � ���������, ���������� ����������  rec. 
	�������� ��������, ��� ������������ �������  fseek()  ��� ����������� 
	����������� ��������� ��������� � �������, ������� � ������� ������� 
	fread() ��������� ����� ������ � �����.*/
	fseek(fp, offset*sizeof(Client), SEEK_SET);
	if (feof(fp))
	{
		puts("There is no such record!");
		return FALSE;
	}
	return(fread(rec, sizeof(Client), 1, fp) == 1);
}

int PrintRecord(FILE *fp, int offset)
{
	Client rec;
	if (ReadRecord(fp, offset, &rec)!=FALSE)
	{		
	printf("\nID: %d", rec.ID);
	printf("\n Name: %s", rec.name);
	printf("\n Phone: %d", rec.phone);
	printf("\n Adress: %s", rec.addr);
	printf("\n Registration Date: %s", asctime(localtime(&rec.RegDate)));
	printf("\n Preference: %s", rec.preference);
		if (rec.sex == MALE)
		{
			printf("\n Sex: Male");
		} 
		else
		{
			printf("\n Sex: Female");
		}
		return TRUE;
	}
	return FALSE;
}



/*������� OpenDBForAppend() ��������� ���� ��� ������. ������� ���������� �������� ���� 
	FILE *, �������� ������� fopen(), ����� ������� ������������ ���� ��� 
	������ ��� ������. ������� ����� ��������� ������ �������������� 
	������ �����, �������� ��������� ���������� ���������� ������������ � 
	����� �������.*/
FILE *OpenDBForAppend(const char *path)
{
	FILE *fp = fopen(path, "a+b");
	if(fp)
	return fp;
	else
	return FALSE;
}

FILE *OpenDBforRead(const char *path)
{
	FILE *fp = fopen(path, "rb");
	if(fp)
	return fp;
	else
	return FALSE;
}

void CloseDB(FILE *fp)
{
	if (!fp)
	{
		fclose(fp);
	}
	
}

/*�������  InputLong(),  InputChar()  �  InputDouble()  (������ 55-80) 
�������� �������� ���������� ��� ��������� ������ � ����������. ��� 
������� �������� �� �������, ����� �� �������� �������� � ���� �������. 
����� ������� ��������� ������� ��� ������ �������� ������� 
����������� �������������� � �������� �������� ������. */

void ReadLong(const char *label, long *lp)
{
	char buffer[128]; 
	printf(label); 
	gets(buffer); 
	*lp = atol(buffer); 
}

void ReadChar(const char *label, char *cp, int len)
{	
	char buffer[128]; 
	printf(label); 
	gets(buffer); 
	strncpy(cp, buffer, len - 1); 
}

void ReadDouble(const char *label, double *dp)
{
	char buffer[128]; 
	printf(label); 
	gets(buffer); 
	*dp = atof(buffer); 
}

int CheckFileExist(const char *path)
{
	/*�������� �� �������� �����*/
	FILE *fp = fopen(path, "r");
	if (!fp)
	{
		return FALSE;
	} 
	else
	{
		fclose(fp);
		return TRUE;
	}
}


void FillRecord(Client *rec)	
{
	/*��������� ������ � ���� ���������*/
	memset(rec,0,sizeof(Client));
	printf("\n ID: ");
	scanf("%d", &rec->ID);
	rec->RegDate = time(NULL);
	printf("\n Assigned time: %s", asctime(localtime(&rec->RegDate))); 
	printf("\n Name: ");
	scanf("%s", &rec->name);
	printf("\n Address : ");
	scanf("%s", &rec->addr);
	printf("\n Telephone : ");
	scanf("%s", &rec->phone);
	printf("\n Preference : ");
	scanf("%s", &rec->preference);
	puts("\n Choice sex of client. 1 for male, 2 female.");
	rec->sex = SelectSex();
}

int SelectSex()
{
	int i = 0;
	scanf("%d",&i);
	if(i == MALE || i == FEMALE) 
		return i;
	else
	{
		printf("Error Input error. Enter 0 to specify female or 1 that-be male. Please try again:");
		return SelectSex();
	}
}

int WriteRecord(FILE *fp, long offset, Client *rec)
{
	/*������� WriteRecord() ����� �� �� ���������, ��� � 
	������� ReadRecord(), �� ��� ���������� �� ���� ���������, ���������� 
	����������  rec. � ����� �������  fseek()  ������������� ���������� 
	��������� �����. ����� ������� fwrite() ��������� �������������� ������ � 
	���� �������.*/
	if (offset > MAXREC*sizeof(Client))
	{
		return FALSE;
	}
	if (fseek(fp, offset, SEEK_SET) !=0)
	{
		return FALSE;
	}
	return (fwrite(rec, sizeof(Client), 1, fp) == 1);
}

int AppendRecord(FILE *fp, Client *rec)
{
	/*�������  AppendRecord() ��������� ������. �������� �������  fseek(), 
	������������ �����  SEEK_END, ��� ���������������� ����������� 
	��������� ��� ��� �� ������  �����. ������ 51 �������� �������  ftell(), 
	������� ���������� ���������� ��������� �����. �������� �� ������ ����� 
	������, ��� �������� ����� ������ ����������� ������. ������ 52 �������� 
	������� WriteRecord(), ����� ������������ ����� ������ � ����� �����. */
	
	if (fseek(fp, 0, SEEK_END)!=0)
	{
		return FALSE;
	}
	return WriteRecord(fp, ftell(fp), rec); 
}

void DeleteRecord(FILE *fd, int IdDel)
{
	/*��������� ������ � �����. �������� ID ���������� ����� ���������� �������. ���� ���������� ���������� �������� � ������� ID,
	� �������� ��������� IdDel �������� NULL*/
	fseek(fd, 0,SEEK_END);
	int	amount = ftell(fd)/sizeof(Client);
	int i=0;
	Client ClientArray[MAXREC];
	while (i<amount)
	{
		PrintRecord(fd,i);
		ReadRecord(fd,i,&ClientArray[i]);
		i++;
	}	
		if (IdDel == NULL)
		{
		puts("\n \n Please enter the client ID that want to move to archive: \n");
		IdDel=0;
		scanf("%d",&IdDel);
		}
	FILE* fdArch = OpenDBForAppend(dBArchiv);
	for (i = 0; i < amount; i++)
	{
		if (ClientArray[i].ID == IdDel)
		{
			AppendRecord(fdArch, &ClientArray[i]);
			ClientArray[i] = ClientArray[amount-1];
			memset(&ClientArray[amount-1],0,sizeof(ClientArray[0]));
			amount--;
		}
	}
	CloseDB(fd);
	fd = fopen(dBName,"wb+");
	for (i = 0; i < amount; i++)
	{
		AppendRecord(fd,&ClientArray[i]);
	}
	CloseDB(fd);
}

void MakePair(FILE *fd)
{
	fseek(fd, 0,SEEK_END);
	int	amount = ftell(fd)/sizeof(Client);
	Client ClientArray[MAXREC];
	int i=0;
	while (i<amount)
	{
		PrintRecord(fd,i);
		ReadRecord(fd,i,&ClientArray[i]);
		i++;
	}

	puts("\n Write a Customer ID in order to find a pair: \n");
	int IdForPair;
	scanf("%2d",&IdForPair);
	Client FirsClientPair;
	Client SecondClientPair;
	for (i = 0; i < amount; i++)
	{
		if (ClientArray[i].ID == IdForPair)
		{
			FirsClientPair=ClientArray[i];
		}
	}
	for (i = 0; i < amount; i++)
	{
		if (FirsClientPair.sex!=ClientArray[i].sex&&strcmp(FirsClientPair.preference,ClientArray[i].preference)!=0)
		{
			SecondClientPair = ClientArray[i];
		}
	}
	printf("\nDone! Client ID: %d and compatible ID %d\n",FirsClientPair.ID,SecondClientPair.ID);
	PrintStruct(&FirsClientPair);
	PrintStruct(&SecondClientPair);
	puts("\n Move to archive? [y\n]");
	char choise[1];
	gets(choise);
	if (!strcmp(choise,"y"))
	{
		DeleteRecord(fd,FirsClientPair.ID);
		DeleteRecord(fd,SecondClientPair.ID);
	}
}

void PrintStruct(Client *rec)
{
	printf("\nID: %d", rec->ID);
	printf("\n Name: %s", rec->name);
	printf("\n Phone: %d", rec->phone);
	printf("\n Adress: %s", rec->addr);
	printf("\n Registration Date: %s", asctime(localtime(&rec->RegDate)));
	printf("\n Preference: %s", rec->preference);
	if (rec->sex == MALE)
	{
		printf("\n Sex: Male");
	} 
	else
	{
		printf("\n Sex: Female");
	}
}

