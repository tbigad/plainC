#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define  FALSE 0
#define  TRUE 1
#define NAMELEN 30
#define PHONELEN 13
#define ADDRLEN 50
#define PREFERENCELEN 128
#define MALE 1
#define FEMALE 0
#define  MAXREC 100

const char* const dBName = "./db.dat";
const char* const dBArchiv = "./dbArch.dat";

typedef struct _client
{
	int sex;
	char name[NAMELEN];
	char addr[ADDRLEN];
	char phone[PHONELEN];
	time_t RegDate;
	long ID;
	char preference[PREFERENCELEN];
}Client;



/* ������� ����� ���� ������. 0 = �����, -1 = ������� */ 
int CreateDB(const char *path);

/* ��������� ���� ������. ���������� FILE * ��� NULL */ 
FILE *OpenDBForAppend(const char *path);

FILE *OpenDBforRead(const char *path);

/*��������� ���� ������. ��������� fp*/
void CloseDB(FILE *fp);

/*������ ������ � ������� recnum � rec. ���������� TRUE/FALSE*/
int ReadRecord(FILE *fp, long recnum, Client *rec);

/* ���������� ������ � ������� recnum �� rec. ���������� TRUE/FALSE */  
int WriteRecord(FILE *fp, long recnum, Client *rec);

/* ��������� ������ � ����� �����. ���������� TRUE/FALSE */
int AppendRecord(FILE *fp, Client *rec); 

/*������� ����������� (label) � ������ �������� ���� long */ 
void ReadLong(const char *label, long *lp); 

/* ������� ����������� � ������ ������ */ 
void ReadChar(const char *label, char *cp, int len); 

/* ������� ����������� � ������ �������� ���� double */ 
void ReadDouble(const char *label, double *dp); 

/*������z  FileExists(), ���������� �������, ���� �������� ����, ������������ �������  path, ����������. */
int CheckFileExist(const char *path);

/*���������� ������ � ���������*/
void FillRecord(Client *rec);

/*����� ����, ����� ��� WriteRecord()*/
int SelectSex();

/*������� ������ �� �����*/
int PrintRecord(FILE *fp, int ID);

/*�������� ���*/
void MakePair(FILE *fp);

/*�������� ��������*/
void DeleteRecord(FILE *fd, int IdDel);

/*������ �������� ���������*/
void PrintStruct(Client *stuct);