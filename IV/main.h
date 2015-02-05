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



/* Создает новую базу данных. 0 = успех, -1 = неудача */ 
int CreateDB(const char *path);

/* Открывает базу данных. Возвращает FILE * или NULL */ 
FILE *OpenDBForAppend(const char *path);

FILE *OpenDBforRead(const char *path);

/*Закрывает базу данных. Принимает fp*/
void CloseDB(FILE *fp);

/*Читает запись с номером recnum в rec. Возвращает TRUE/FALSE*/
int ReadRecord(FILE *fp, long recnum, Client *rec);

/* Записывает запись с номером recnum из rec. Возвращает TRUE/FALSE */  
int WriteRecord(FILE *fp, long recnum, Client *rec);

/* Добавляет запись в конец файла. Возвращает TRUE/FALSE */
int AppendRecord(FILE *fp, Client *rec); 

/*Выводит приглашение (label) и вводит значение типа long */ 
void ReadLong(const char *label, long *lp); 

/* Выводит приглашение и вводит строку */ 
void ReadChar(const char *label, char *cp, int len); 

/* Выводит приглашение и вводит значение типа double */ 
void ReadDouble(const char *label, double *dp); 

/*функциz  FileExists(), возвращает «истину», если заданный файл, определяемый строкой  path, существует. */
int CheckFileExist(const char *path);

/*записывает данные в структуру*/
void FillRecord(Client *rec);

/*Выбор пола, нужно для WriteRecord()*/
int SelectSex();

/*Выводит данные на экран*/
int PrintRecord(FILE *fp, int ID);

/*создание пар*/
void MakePair(FILE *fp);

/*Удаление клиентов*/
void DeleteRecord(FILE *fd, int IdDel);

/*Просто печатает структуру*/
void PrintStruct(Client *stuct);