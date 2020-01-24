#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//----------------------------------------------------------------------------------------------------------//
struct Hall {
	int code;
	char name[30];
	int floor;
	int capacity;
};
//----------------------------------------------------------------------------------------------------------//
struct Sans {
	int sansNumber;
	int hallCode;
	int filmCode;
	char startDate[8];
	char startTime[4];
	char endTime[4];
	int capacity;
	int remain;
};
//----------------------------------------------------------------------------------------------------------//
struct Film {
	int code;//movie code
	char name[30];//movie name
	char director[20];
	int proYear;
	int duration;
	char genre[20];
	char actorsName[200];
	char summary[500];
};
//----------------------------------------------------------------------------------------------------------//
struct Booking {
	int code;
	char fullName[35];
	int sansNumber;
	int numberOfTickets;
};
//----------------------------------------------------------------------------------------------------------//
struct Hall halls[1000];
int hallsCount=0;

struct Film films[1000];
int filmsCount=0;

struct Sans sanses[1000];
int sansesCount=0;

struct Booking bookings[2000];
int bookingsCount=0;
//----------------------------------------------------------------------------------------------------------//
//functions used - begin
void getHallName(int  hallcode);
 void getFilmName(int filmcode);
bool existsHall();
void cancelBooking();
int findFirstInterferSans();


int showMainMenu();
void showHallsMenu();
void showFilmsMenu();
void showSansesMenu();
void showBookingsMenu();

void showHallsList();
void showFilmsList();
void showSansesList();
void showBookingsList();

int newHall();
int newFilm();
int editFilm();
int newSans();
int newBooking();

void readHallsFromFile();
void readFilmsFromFile();
void readSansesFromFile();
void readBookingsFromFile();

void writeHallsToFile();
void writeFilmsToFile();
void writeSansesToFile();
void writeBookingsToFile();

//functions used - end
//----------------------------------------------------------------------------------------------------------//






//----------------------------------------------------------------------------------------------------------//

int main() {
	showMainMenu();
	return 0;
}
//----------------------------------------------------------------------------------------------------------//
//---------------------Show menus Section begin
int showMainMenu() {
	system("@cls||clear");
//	printf("%s\n",getHallName(1));
	printf("**************** Welcome To My Cinema***************************\n");
	printf("Hint:\n\n");
	printf("1)Halls\n\n");
	printf("2)Films\n\n");
	printf("3)Sanses\n\n");
	printf("4)Bookings\n\n");
	printf("0)Exit\n\n");
	int choice=0;
	while (1==1) {
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				printf("\n\nBye!!!\n\n");
				exit(0);
				break;
			case 1:
				showHallsMenu();
				break;
			case 2:
				showFilmsMenu();
				break;
			case 3:
				showSansesMenu();
				break;
			case 4:
				showBookingsMenu();
				break;
			default:
				showMainMenu();
				break;
		}
	}
	return;
}
//----------------------------------------------------------------------------------------------------------//
void showHallsMenu() {
	system("@cls||clear");
	printf("**************** Halls Menu *************************\n");
	printf("Hint:\n\n");
	printf("1)View Halls\n\n");
	printf("2)Add New Hall\n\n");
	printf("0)Back to main menu\n\n");

//	readHallsFromFile();

	int choice=0;
	while (1==1) {
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				showMainMenu();
				break;
			case 1:
		
				showHallsList();
				break;
			case 2:
				newHall();
				break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------//
void showFilmsMenu() {
	system("@cls||clear");
	printf("****************** Halls Menu *************************\n");
	printf("Hint:\n\n");
	printf("1)View Films\n\n");
	printf("2)Add New Film\n\n");
	printf("0)Back to main menu\n\n");

	int choice=0;
	while (1==1) {
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				showMainMenu();
				break;
			case 1:
				showFilmsList();
				break;
			case 2:
				newFilm();
				break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------//
void showSansesMenu() {
	system("@cls||clear");
	printf("****************** Sanses Menu *************************\n");
	printf("Hint:\n\n");
	printf("1)View Sanses\n\n");
	printf("2)Add New Sans\n\n");
	printf("0)Back to main menu\n\n");

	//readHallsFromFile();
	


	int choice=0;
	while (1==1) {
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				showMainMenu();
				break;
			case 1:
				showSansesList(1);
				break;
			case 2:
				newSans();
				break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------//
void showBookingsMenu() {
	system("@cls||clear");

	printf("****************** Bookings Menu ***************************\n");
	printf("Hint:\n\n");
	printf("1)View Bookings\n\n");
	printf("2)Add New Booking\n\n");
	printf("3)Cancel Exising Booking\n\n");
	printf("0)Back to main menu\n\n");

	int choice=0;
	while (1==1) {
		scanf("%d",&choice);
		switch(choice) {
			case 0:
				showMainMenu();
				break;
			case 1:
				showBookingsList();
				break;
			case 2:
				newBooking();
				break
				;
			case 3:
				cancelBooking();
				break;
		}
	}
}
//---------------------Show menus Section end
//----------------------------------------------------------------------------------------------------------//
//read data section - begin
void readHallsFromFile() {
int cha;
	hallsCount=0;
	struct Hall hall;
	FILE* infile;
	infile = fopen ("halls.dat", "rb");
	if (infile == NULL) {
		printf("error opening file");
		printf("\nplease Enter any Key to Continue\n");
		scanf("%c" ,&cha);
		scanf("%c" ,&cha);
		showMainMenu(); 
		
	}
	while(fread(&hall, sizeof(struct Hall), 1, infile)) {
		halls[hallsCount]=hall;
		hallsCount++;
	}
	fclose(infile);
}
//----------------------------------------------------------------------------------------------------------//
void readFilmsFromFile() {
	filmsCount=0;
	char cha;
	struct Film film;
	FILE* infile;
	infile = fopen ("films.dat", "rb");
	if (infile == NULL) {
		printf("error opening file");
		printf("\nplease Enter any Key to Continue\n");
		scanf("%c" ,&cha);
		scanf("%c" ,&cha);
		showMainMenu(); 
		
		}
	while(fread(&film, sizeof(struct Film), 1, infile)) {
		films[filmsCount]=film;
		filmsCount++;
	}
	fclose(infile);
}
//----------------------------------------------------------------------------------------------------------//
void readSansesFromFile() {
	sansesCount=0;
	char cha;
	struct Sans sans;
	FILE* infile;
	infile = fopen ("sanses.dat", "rb");
	if (infile == NULL) {
		printf("\nerror oppening file\n");
		printf("\nplease Enter any Key to Continue\n");
		scanf("%c" ,&cha);
		scanf("%c" ,&cha);
		showMainMenu(); 
	}
	while(fread(&sans, sizeof(struct Sans), 1, infile)) {
		sanses[sansesCount]=sans;
		sansesCount++;
	}
	fclose(infile);
}
//----------------------------------------------------------------------------------------------------------//
void readBookingsFromFile() {
    char cha;
	bookingsCount=0;
	struct Booking booking;
	FILE* infile;
	infile = fopen ("bookings.dat", "rb");
	if (infile == NULL) {
printf("\nerror oppening file\n");
		printf("\nplease Enter any Key to Continue\n");
		scanf("%c" ,&cha);
		scanf("%c" ,&cha);
		showMainMenu(); 

		
	}
	while(fread(&booking, sizeof(struct Booking), 1, infile)) {
		bookings[bookingsCount]=booking;
		bookingsCount++;
	}
	fclose(infile);
}
//read data section - end
//write data section - begin
//----------------------------------------------------------------------------------------------------------//
void writeHallsToFile() {

	FILE* p;
	p=fopen("halls.dat","wb");
	int i=0;
	for(i=0; i<hallsCount; i++) {
		fwrite(&halls[i],sizeof(struct Hall),1,p);
	}
	fclose(p);
}
//----------------------------------------------------------------------------------------------------------//
void writeFilmsToFile() {
	FILE* p;
	p=fopen("films.dat","wb");
	int i=0;
	for(i=0; i<filmsCount; i++) {
		fwrite(&films[i],sizeof(struct Film),1,p);
	}
	fclose(p);
}
//----------------------------------------------------------------------------------------------------------//
void writeBookingsToFile() {


	FILE* p;
	p=fopen("bookings.dat","wb");
	int i=0;
	for(i=0; i<bookingsCount; i++) {
		if (bookings[i].code!=-1) {
			fwrite(&bookings[i],sizeof(struct Booking),1,p);
		}
	}
	fclose(p);

}
//----------------------------------------------------------------------------------------------------------//
void writeSansesToFile() {
	FILE* p;
	p=fopen("sanses.dat","wb");
	int i=0;
	for(i=0; i<sansesCount; i++) {
		fwrite(&sanses[i],sizeof(struct Sans),1,p);
	}
	fclose(p);
}
//write data section - end
//----------------------------------------------------------------------------------------------------------//
//show data section - begin
void showHallsList() {
		readHallsFromFile();
	system("@cls||clear");
	printf("******************** Halls List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	FILE *infile;
	infile=fopen("halls.dat" , "rb");
	printf("Row   Hall Code     Hall Name    Floor    Capacity\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0; i<hallsCount && fread(&halls[i],sizeof(struct Hall),1,infile); i++) {
		printf("%d",i+1);
		printf("      ");
		char snum[10];
		printf("%-5s",itoa(halls[i].code,snum,10));
		printf("      ");
		printf("%-10s",halls[i].name);
		printf("       ");
		printf("%-5s",itoa(halls[i].floor,snum,10));
		printf("      ");
		printf("%-5s",itoa(halls[i].capacity,snum,10));
		printf("\n\n");
	}
	printf("-------------------------------------------------------------------------\n");
	printf("Press a key to continue...");
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	showHallsMenu();
	return;
}
//----------------------------------------------------------------------------------------------------------//
void showFilmsList() {
	readFilmsFromFile();
	system("@cls||clear");
	printf("******************** Films List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	printf("Row   Film Code     Film Name    Director    Production Year   Duration    Actors     Summary\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0; i<filmsCount; i++) {

		printf("%d",i+1);
		printf("      ");
		char snum[10];
		printf("%-5s",itoa(films[i].code,snum,10));
		printf("    ");
		printf("%-10s",films[i].name);
		printf("     ");
		printf("%s" ,films[i].director);
		printf("     ");
		printf("%d" ,films[i].proYear);
		printf("     ");
		printf("%d" ,films[i].duration);
		printf("     ");
		printf("%s" ,films[i].actorsName);
		printf("     ");
		printf("%s" ,films[i].summary);
		printf("\n\n");
	}
	printf("-------------------------------------------------------------------------\n");
	printf("Press a key to continue...");
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	showFilmsMenu();
	return;
}
//----------------------------------------------------------------------------------------------------------//
void showSansesList(int purpose) {  //purpose : 1= only show and exit , 2=show to booking
	system("@cls||clear");
	readFilmsFromFile();
	readSansesFromFile();
	printf("******************** Sanses List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	printf("Row - Sans No - Hall Code - Film Code -Film Name  -  Start Date     Start Time    End Time    Capacity    Remain Capacity\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0; i<sansesCount; i++) {
		printf("%d",i+1);
		printf("     ");
		printf("%d" ,sanses[i].sansNumber);
		printf("       ");
		printf("%d" ,sanses[i].hallCode);
		printf("        ");
		printf("%d      " ,sanses[i].filmCode);
		getFilmName(sanses[i].filmCode);
		printf("       ");
		
		
		
		printf("%s---" ,sanses[i].startDate);
		printf("%s to " ,sanses[i].startTime);
		printf("%s     " ,sanses[i].endTime);
		printf("%d" ,sanses[i].capacity);
		printf("      ");
		printf("%d\n\n" ,sanses[i].remain);

	}
	printf("-------------------------------------------------------------------------\n");
	if (purpose==1) {

		printf("Press a key to continue...");
		char ch;
		scanf("%c" ,&ch);
		scanf("%c" ,&ch);
		showSansesMenu();
	}
}
//----------------------------------------------------------------------------------------------------------//
void showBookingsList() {
	system("@cls||clear");
	readBookingsFromFile();
	printf("******************** Bookings List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	printf("Row   Booking Code     Full Name    Sans Number     Number Of Tickets\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0; i<bookingsCount; i++) {
		printf("%d",i+1);
		printf("      ");
		printf("%d" ,bookings[i].code);
		printf("      ");
		printf("%-10s" ,bookings[i].fullName);
		printf("      ");
		printf("%d" ,bookings[i].sansNumber);
		printf("      ");

		int ii=0;
		int jj=0;
		for(ii=0; ii<sansesCount; ii++) {
			if (sanses[ii].sansNumber  ==bookings[i].sansNumber) {
				for(jj=0; jj<filmsCount; jj++) {
					if (films[jj].code  ==sanses[ii].filmCode ) {
						printf("%-10s",films[jj].name);
						break;
					}
				}
			}
		}
		printf("    %d" ,bookings[i].numberOfTickets);
		printf("\n");
	}
	printf("\n-------------------------------------------------------------------------\n");
	printf("Press a key to continue...");
	char ch;
	scanf("%c" ,&ch);
	scanf("%c" ,&ch);
	showBookingsMenu();

}
//show data section - end
//----------------------------------------------------------------------------------------------------------//
//create data section - begin
int newHall() {

	char ch;
	struct Hall hall;
	system("@cls||clear");
	printf("******************** New Hall***************************\n");
	printf("Plaese enter following information for new Hall:\n");
	printf("\nHall Code:") ;
	scanf("%d" ,&hall.code);

	if (existsHall(hall.code)) {
		printf("The Code Exists!!!!\n");
		printf("Press a key to continue!!!!\n");
		scanf("%c",&ch);
		scanf("%c",&ch);
		showHallsMenu();
		return 0;
	}



	printf("\nHall Name :");
	scanf("%c",&ch);
	scanf("%[^\n]",hall.name);
	printf("\nHall Floor :");
	scanf("%d",&hall.floor);
	printf("\nHall Capacity :");
	scanf("%d",&hall.capacity);
	halls[hallsCount]=hall;
	hallsCount=hallsCount+1;
	writeHallsToFile();

	printf("\n !!! New Hall Info Saved Successfuly !!! \n");
	scanf("%c",&ch);
	scanf("%c",&ch);
	showHallsMenu();
	return 0;
}
//----------------------------------------------------------------------------------------------------------//
int newFilm() {
	int key;
	struct Film film;
	system("@cls||clear");
	printf("******************** New Film***************************\n");
	printf("Plaese enter following information for new film:\n");
	printf("\nFilm Code :");
	scanf("%d",&film.code);
	printf("\nFilm Name :");
	scanf("%s",film.name);
	printf("\nDirector :");
	scanf("%s" ,film.director);
	printf("\nProduction Year :");
	scanf("%d",&film.proYear);
	printf("\nDuration(in minuets) :");
	scanf("%d" ,&film.duration);
	printf("\nGenre :");
	scanf("%s" ,film.genre);
	printf("\nActors :");
	scanf("%s" ,film.actorsName);
	printf("\nSummary :");
	scanf("%s" ,film.summary);
	films[filmsCount]=film;
	filmsCount=filmsCount+1;
	printf("1)save\n2)cancel\n?");
	scanf("%d" ,&key);
	if(key==1) {
		writeFilmsToFile();
		printf("\n !!! New Film Info Saved Successfuly !!! ");
	} else {
		showFilmsMenu();
	}
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	showFilmsMenu();
	return 0;
}
	
	
//----------------------------------------------------------------------------------------------------------//
int newSans() {
	char ch;	
	system("@cls||clear");
	int key;
	struct Sans sans;
	sans.sansNumber=sansesCount+1;
	printf("Sans Number %d" ,sans.sansNumber);
	printf("\nHall Code:");
	scanf("%d" ,&sans.hallCode);
	printf("\n");
getHallName(sans.hallCode);
	printf("\nFilm Code:" );
	scanf("%d" ,&sans.filmCode);

getFilmName(sans.filmCode);
	
	printf("/nStart Date( in format YYYYMMNN):");
	scanf("%s",sans.startDate);
	while(strlen(sans.startDate)!=8 && strcmp(sans.startDate,"-1")!=0)
	{
		printf("date should be in correct format (YYYYMMDD) \n");
		printf("Start Date:");
		scanf("%s" ,sans.startDate);
	}
	
	if (strcmp(sans.startDate,"-1")==0) 
	{
		showSansesMenu();
	}
	
	
	printf("Start Time (HHMM) :");
	scanf("%s" ,sans.startTime);

	while(strlen(sans.startTime)!=4 && strcmp(sans.startDate,"-1")!=0)
	{
		printf("Start time should be in correct format (HHMM) \n");
		printf("Start Time:");
		scanf("%s" ,sans.startDate);
	}
	if (strcmp(sans.startTime,"-1")==0) 
	{
		showSansesMenu();
		return 0;
	}

	int interferSansCode=-1;
	interferSansCode=findFirstInterferSans(sans.hallCode,sans.startDate,sans.startTime);
	if (interferSansCode!=-1)
	{
		printf("This sans has interference with sans no :%d  \n",interferSansCode);
		scanf("%c" ,&ch);
		showSansesMenu();
		return 0;
	}
	
	
	printf("End Time (HHMM) :");
	scanf("%s" ,sans.endTime);

	while(strlen(sans.endTime)!=4 && strcmp(sans.endTime,"-1")!=0)
	{
		printf("End time should be in correct format (HHMM) \n");
		printf("End Time:");
		scanf("%s" ,sans.endTime);
	}
	
	if (strcmp(sans.endTime,"-1")==0) 
	{
		showSansesMenu();
		return 0;
	}
	
	printf("Capacity:");
	scanf("%d" ,&sans.capacity);
	sans.remain=sans.capacity;
	printf("\n\n1)Record\n2)cancel\n?");
	scanf("%d" ,&key);
	if(key==1) {
		sanses[sansesCount]=sans;
		sansesCount++;
		writeSansesToFile();
		printf("\n\n !!! New Sans Info Saved Successfuly !!! ");
		printf("\nPress any Key To continue...");
		char ch;
		scanf("%c" ,&ch);
		scanf("%c" ,&ch);
		showSansesMenu();
	}

	else {
		showSansesMenu();
	}
}
//----------------------------------------------------------------------------------------------------------//
int newBooking() {
	int key;
	char ch;
	system("@cls||clear");
	showSansesList(2);
	struct Booking booking;
	


	printf("******************** New Booking***************************\n");
	printf("Plaese enter following information for new booking:\n");
	booking.code=bookingsCount+1;
	printf("code:%d" ,booking.code);
	printf("\nFull Name:");
	scanf("%s" ,booking.fullName);
	printf("Sans Number:");
	scanf("%d" ,&booking.sansNumber);
	int foundSans=-1;
	int j=0;
	for(j=0; j<sansesCount; j++)  
	{
		if(sanses[j].sansNumber==booking.sansNumber)
		 {
			foundSans=j;
		 }
	}

	if (foundSans==-1) {
		printf("Not Found any Sanses!! ");
		printf("\nPress any Key To continue...");
		scanf("%c",&ch);
		scanf("%c",&ch);
		showBookingsMenu();
	}

	printf("Remain Capacity: %d" ,sanses[foundSans].remain);
	printf("\nNumber Of Tickets:");
	scanf("%d" ,&booking.numberOfTickets);
	if(booking.numberOfTickets>sanses[foundSans].remain) {
		printf("Capacity is Full!!");
		printf("\nPress any Key To continue...");
		scanf("%c",&ch);
		scanf("%c",&ch);
		showBookingsMenu();
	}
	printf("\n\n1)Record\n2)cancel\n?");
	scanf("%d" ,&key);
	if(key==1) {
		bookings[bookingsCount]=booking;
		bookingsCount++;
		writeBookingsToFile();

		sanses[foundSans].remain-=booking.numberOfTickets;
		writeSansesToFile();


		printf("Recorded Successfully!!!");
		printf("\nPress any Key To continue...");
		scanf("%c",&ch);
		scanf("%c",&ch);
		showBookingsMenu();
	}
	 else 
	{
		showBookingsMenu();
	}
}
//create data section - end
//----------------------------------------------------------------------------------------------------------//
//Control section begin
bool existsFilm(int filmCode) {
	int i=0;
	for(i=0; i<filmsCount; i++) {
		if(films[i].code==filmCode ) {
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------------------------------------------//
bool existsHall(int hallCode) {

	int i=0;
	for(i=0; i<hallsCount; i++) {
		if(halls[i].code==hallCode ) {
			return true;
		}
	}
	return false;
}
//----------------------------------------------------------------------------------------------------------//
void cancelBooking() {
	int foundcode;
	printf("Enter the Booking No:");
	scanf("%d" ,&foundcode);
	int i=0;
	int j=0;
	for(i=0; i<bookingsCount; i++) {
		if(foundcode==bookings[i].code) {
			bookings[i].code =-1;

			for (j=0; j<sansesCount; j++) {
				if(sanses[j].sansNumber==bookings[i].sansNumber) {
					sanses[j].remain+=bookings[i].numberOfTickets;
				}
			}



			writeBookingsToFile();
			writeSansesToFile();
			readBookingsFromFile();
			readSansesFromFile();



			printf("Successed Canceling!!!!");

			printf("\nPress any Key To continue...");
			char ch;
			scanf("%c",&ch);
			scanf("%c",&ch);
			showBookingsMenu();

		}
	}


	
}
//Control section end
//----------------------------------------------------------------------------------------------------------//
//other operations begin
void getHallName(int hallCode) 
{
	readHallsFromFile();
	int i=0,flag=0;
	char ch;
	for(i=0; i<hallsCount; i++) {
		if(halls[i].code==hallCode) {
			 flag=1;
			 break;
		}
}
if(flag==1)
{
	printf("%s" ,halls[i].name);
}
else{
		printf("\nNo Hall Found");
		printf("\nPress any Key To continue...");
		scanf("%c" ,&ch);	
		scanf("%c" ,&ch);
		showSansesMenu();
	}
}
//----------------------------------------------------------------------------------------------------------//

void getFilmName(int filmCode) {
	int i=0,flag=0;
	readFilmsFromFile();
	for(i=0; i<filmsCount; i++) {
		if(films[i].code==filmCode) {
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
	
		printf("%s" ,films[i].name);
	}
	else
	{
			printf("\nNo Film Found");
		printf("\nPress any Key To continue...");
		char ch;
		scanf("%c" ,&ch);
		scanf("%c" ,&ch);
		showSansesMenu();
	
	}

}
//----------------------------------------------------------------------------------------------------------//
int  findFirstInterferSans(int hallCode,char startDate[10],char startTime[5])
{
	int i=0;
	for(i=0;i<sansesCount;i++)
	{
		if (sanses[i].hallCode==hallCode && strcmp(sanses[i].startDate,startDate)==0 &&  strcmp(startTime,sanses[i].startTime)>=0  && strcmp(startTime,sanses[i].endTime)<0 )
		{
			return sanses[i].sansNumber;
			break;
		}
	}
	return -1;
}
//other operations end
//----------------------------------------------------------------------------------------------------------//

