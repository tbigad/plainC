/*Бюро знакомств. База потенциальных женихов и невест: пол, регистрационный номер, дата регистрации, сведения о себе,
требования к партнеру. Выбор подмножества подходящих кандидатур, подготовка встреч (формирование приглашения для знакомства).
Перенос в архив пар, решивших свои семейные проблемы, удаление клиентов, отказавшихся от услуг. */

#include "main.h"

//UI
int MainMenu()
{
	printf("\n 1. Add person\n");
	printf(" 2. Make a pair\n");
	printf(" 3. Delete person\n");
	printf(" 4. Exit\n");
	int result;
	puts("Enter: ");
	scanf("%1d", &result);
	if (result < 1 || result > 4)
	{
		printf("Wrong selection, please try again. \n");
		return MainMenu();
	}
	else if(result == 4)
	{
		exit(0);
	}
	return result;
}

//

//Engine

//

int main()
{
	FILE* fd = OpenDBForAppend(dBName);//open if exists or create and open
	int i = 0;
	for(;;) {
		int mainMenuResult = MainMenu();
		switch(mainMenuResult) {
		case 1: 
			/* Добавить персону.*/
			Client newPerson;
			FillRecord(&newPerson);
			if (AppendRecord(fd, &newPerson) == FALSE)//add new record at the End of the db file
			{
				printf("Failed to appends record");
				CloseDB(fd);
				exit(-1);
			}
			CloseDB(fd);
			break;
		case 2: 
		/*
		//Select partners
		FILE* fd = OpenDBforRead(NULL);
		size_t recordCount = GetRecornCount(fd);// 1)seek(end of the file)2) size_t fileSize = tellp(); - get file size 3) return fileSize/sizeof(Client)
		Client* clientArray = (Client*)malloc(sizeof(Client) * recordCount);
		ReadRecords(fd, clientArray);
		
		//Print all persons and ask for target person
		PrintPersones(clientArray);
		int targetPersoneId = SelectTargetPersone();//Get suitable pair for person with Id=12

		arrayOfSutiablePersons = SearchForPair(clientArray, targetPersoneId);
		PrintPersones(arrayOfSutiablePersons);
		free(clientArray);*/

			break;;
		case 3:
			DeleteRecord(fd,NULL);
			break;
		case 4: 
			CloseDB(fd);
				exit(0);
		case 5: 
				exit(0);
		case 6: 
				exit(0);
		}
	}
	return 0;
}