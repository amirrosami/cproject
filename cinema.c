#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hall
{
	int code;
	char name[30];
	int floor;
	int capacity;
};
struct Sans
{
	int sansNumber;
	int hallCode;
	 int filmCode;
	char startDate[10];
	char startTime[10];
	char endTime[10];
	int capacity;
	int remain;
};
struct Film
{
	int code;//movie code
	char name[30];//movie name
	char director[20];
	int proYear;
	int duration;
	char genre[20];
	char actorsName[200];
	char summary[500];
};
struct Booking
{
	int code;
	char fullName[35];
	int sansNumber;
	int numberOfTickets;
};
struct Hall halls[1000];
int hallsCount=0;

struct Film films[1000];
int filmsCount=0;

struct Sans sanses[1000];
int sansesCount=0;

struct Booking bookings[2000];
int bookingsCount=0;


char tmpFilmName[30]="";



int main()
{
	
	showMainMenu();
	return 0;
}
int showMainMenu() {
  system("@cls||clear");
  printf("**************** Welcome To My Cinema***************************\n");
  printf("Hint:\n\n");
  printf("1)Halls\n\n");
  printf("2)Fims\n\n");
  printf("3)Sanses\n\n");
  printf("4)Bookings\n\n");
  printf("0)Exit\n\n");
  int choice=0;
  while (1==1) {
    scanf("%d",&choice);
    switch(choice) {
      case 0:
        printf("\n\nBye!!!\n\n");
        return 0;
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

readHallsFromFile()
{
	hallsCount=0;
    struct Hall hall;
	FILE* infile;
    infile = fopen ("halls.dat", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    while(fread(&hall, sizeof(struct Hall), 1, infile))
    {
        halls[hallsCount]=hall;
        hallsCount++;
	}
	fclose(infile);
}
writeHallsToFile() {
	FILE* p;
	p=fopen("halls.dat","wb");
	int i=0;
	for(i=0; i<hallsCount; i++) {
		fwrite(&halls[i],sizeof(struct Hall),1,p);
	}
	fclose(p);
}
showHallsList()
{
	system("@cls||clear");
	printf("******************** Halls List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	FILE *infile;
	infile=fopen("halls.dat" , "rb");
	printf("Row   Hall Code     Hall Name    Floor    Capacity\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0;i<hallsCount && fread(&halls[i],sizeof(struct Hall),1,infile);i++)
	{
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
	return 0;
}
int NewHall() {
	struct Hall hall;
	system("@cls||clear");
	printf("******************** New Hall***************************\n");
	printf("Plaese enter following information for new Hall:\n");
	hall.code=hallsCount+1;
	printf("\nHall Code :%d" ,hallsCount+1);
	printf("\nHall Name :");
	scanf("%s",hall.name);
	printf("\nHall Floor :");
	scanf("%d",&hall.floor);
	printf("\nHall Capacity :");
	scanf("%d",&hall.capacity);
	halls[hallsCount]=hall;
	hallsCount=hallsCount+1;
	writeHallsToFile();

	printf("\n !!! New Hall Info Saved Successfuly !!! \n");
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	showHallsMenu();
	return 0;
}

showHallsMenu() {
  system("@cls||clear");
  printf("**************** Halls Menu *************************\n");
  printf("Hint:\n\n");
  printf("1)View Halls\n\n");
  printf("2)Add New Hall\n\n");
  printf("0)Back to main menu\n\n");

  int choice=0;
  while (1==1) {
    scanf("%d",&choice);
    switch(choice) {
      case 0:
        showMainMenu();
        break;
      case 1:
        readHallsFromFile();
        showHallsList();
        break;
      case 2:
        NewHall();
        break;
    }
  }
}
showFilmsMenu() {
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
      	NewFilm();
        break;
    }
  }
}
showSansesMenu() {
  system("@cls||clear");
  printf("****************** Sanses Menu *************************\n");
  printf("Hint:\n\n");
  printf("1)View Sanses\n\n");
  printf("2)Add New Sans\n\n");
  printf("0)Back to main menu\n\n");

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
showBookingsMenu() {
  system("@cls||clear");
  
  readHallsFromFile();
  readFilmsFromFile();
  readSansesFromFile();
  readBookingsFromFile();
  
  
  
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

cancelBooking()
{
	int foundcode;
	printf("Enter the Booking No:");
	scanf("%d" ,&foundcode);
	int i=0;
	int j=0;
	for(i=0;i<bookingsCount;i++)
	{
		if(foundcode==bookings[i].code)
		{
		bookings[i].code =-1;
		
		for (j=0;j<sansesCount;j++)
		{
			if(sanses[j].sansNumber==bookings[i].sansNumber)
				{
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
	
	
	//edameh bedeh
}


readBookingsFromFile() 
{
	bookingsCount=0;
    struct Booking booking;
	FILE* infile;
    infile = fopen ("bookings.dat", "rb");
    if (infile == NULL)
    {
        printf("\nError opening file\n");
        exit (1);
    }
    while(fread(&booking, sizeof(struct Booking), 1, infile))
    {
        bookings[bookingsCount]=booking;
        bookingsCount++;
	}
	fclose(infile);
}
 newBooking()
{   int key;
    char ch;
	system("@cls||clear");
	showSansesList(2);
	struct Booking booking;
	readBookingsFromFile();
	
	
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
	for(j=0;j<sansesCount;j++)
	{
		if(sanses[j].sansNumber==booking.sansNumber)
		{
			foundSans=j;
		}
	}
	
	if (foundSans==-1)
	{
		printf("Not Found any Sanses!! ");
		printf("\nPress any Key To continue...");
	scanf("%c",&ch);
	scanf("%c",&ch);
	showBookingsMenu();
	}
	
	printf("Remain Capacity: %d" ,sanses[foundSans].remain);
	printf("\nNumber Of Tickets:");
	scanf("%d" ,&booking.numberOfTickets);
	if(booking.numberOfTickets>sanses[foundSans].remain)
	{
		printf("Capacity is Full!!");
		printf("\nPress any Key To continue...");
	scanf("%c",&ch);
	scanf("%c",&ch);
	showBookingsMenu();
    }
	printf("\n\n1)Record\n2)cancel\n?");
	scanf("%d" ,&key);
	if(key==1)
	{
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

writeBookingsToFile() {
	FILE* p;
	p=fopen("bookings.dat","wb");
	int i=0;
	for(i=0;i<bookingsCount;i++) 
	{
		if (bookings[i].code!=-1)
	{
				fwrite(&bookings[i],sizeof(struct Booking),1,p);
	}
	}
	fclose(p);

}
void showBookingsList()
{
	system("@cls||clear");
	readBookingsFromFile();
	printf("******************** Bookings List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	printf("Row   Booking Code     Full Name    Sans Number     Number Of Tickets\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0;i<bookingsCount;i++)
	{   
        printf("%d",i+1);
		printf("      ");
		printf("%d" ,bookings[i].code);
		printf("      ");
		printf("%s" ,bookings[i].fullName);
		printf("      ");
		printf("%d" ,bookings[i].sansNumber);
        printf("      ");
        
int ii=0;
int jj=0;
 for(ii=0;ii<sansesCount;ii++)
 {
 	if (sanses[ii].sansNumber  ==bookings[i].sansNumber)
 	{
		 for(jj=0;jj<filmsCount;jj++)
		 {
		 	if (films[jj].code  ==sanses[ii].filmCode )
		 	{
		 		printf("%s",films[jj].name);
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
//*********************************************** Films Source***************************************************************
int NewFilm()
{	
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
	if(key==1)
	{
	writeFilmsToFile();
    printf("\n !!! New Film Info Saved Successfuly !!! ");
	}
	else
	{
		showFilmsMenu();
	}
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	showFilmsMenu();
	return 0;
}

   readFilmsFromFile() 
{
	filmsCount=0;
    struct Film film;
	FILE* infile;
    infile = fopen ("films.dat", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
    while(fread(&film, sizeof(struct Film), 1, infile))
    {
        films[filmsCount]=film;
        filmsCount++;
	}
	fclose(infile);
}

writeFilmsToFile() {
	FILE* p;
	p=fopen("films.dat","wb");
	int i=0;
	for(i=0;i<filmsCount;i++) {
		fwrite(&films[i],sizeof(struct Film),1,p);
	}
	fclose(p);
}


showFilmsList()
{
	readFilmsFromFile();
	system("@cls||clear");
	printf("******************** Films List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	printf("Row   Film Code     Film Name    Director    Production Year   Duration    Actors     Summary\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0;i<filmsCount;i++)
	{   
	
		printf("%d",i+1);
		printf("      ");
		char snum[10];
		printf("%-5s",itoa(films[i].code,snum,10));
		printf("      ");
		printf("%-10s",films[i].name);
		printf("       ");
		printf("%s" ,films[i].director);
		printf("       ");
		printf("%d" ,films[i].proYear);
		printf("       ");
		printf("%d" ,films[i].duration);
		printf("       ");
		printf("%s" ,films[i].actorsName);
		printf("       ");
		printf("%s" ,films[i].summary);
		printf("\n\n");
	}
	printf("-------------------------------------------------------------------------\n");
	printf("Press a key to continue...");
	char ch;
	scanf("%c",&ch);
	scanf("%c",&ch);
	showFilmsMenu();
	return 0;
	}
	
writeSansesToFile() {
	FILE* p;
	p=fopen("sanses.dat","wb");
	int i=0;
	for(i=0;i<sansesCount;i++) {
		fwrite(&sanses[i],sizeof(struct Sans),1,p);
	}
	fclose(p);
}

 newSans()
{
	system("@cls||clear");
	int key;
	struct Sans sans;
	sans.sansNumber=sansesCount+1;
	printf("Sans Number %d" ,sans.sansNumber);
	printf("\nHall Code:");
	scanf("%d" ,&sans.hallCode);
	printf("Film Code:" );
	scanf("%d" ,&sans.filmCode);
	printf("Start Date:");
	scanf("%s" ,sans.startDate);
	printf("Start Time:");
	scanf("%s" ,sans.startTime);
	printf("End Time:");
	scanf("%s" ,sans.endTime);
	printf("Capacity:");
	scanf("%d" ,&sans.capacity);
	sans.remain=sans.capacity;	
	
printf("\n\n1)Record\n2)cancel\n?");
	scanf("%d" ,&key);
	if(key==1)
	{
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
	    
    else
    {
    		showSansesMenu();
	}	
	}

 showSansesList(int purpose)   //purpose : 1= only show and exit , 2=show to booking
{
	system("@cls||clear");
	readFilmsFromFile();
	readSansesFromFile();
	printf("******************** Sanses List Of My Cinema***************************\n");
	printf("***********************************************************************\n");
	int i=0;
	 printf("Row   Sans Number     Hall Code    Film Code     Start Date     Start Time    End Time    Capacity    Remain Capacity\n");
	printf("-------------------------------------------------------------------------\n");
	for (i=0;i<sansesCount;i++)
	{   
        printf("%d",i+1);
		printf("      ");
		printf("%d" ,sanses[i].sansNumber);
		printf("      ");
		printf("%d" ,sanses[i].hallCode);
		printf("      ");
		printf("%d" ,sanses[i].filmCode);
	 //getFilmName(sanses[i].filmCode);
	 
int ii=0;
 for(ii=0;ii<filmsCount;ii++)
 {
 	if (films[ii].code==sanses[i].filmCode)
 	{
 		printf("%s",films[ii].name);
 		break;
	 }
 }
	 
	 
	    
		printf("      ");
		printf("%s" ,sanses[i].startDate);
		printf("      ");
		printf("%s" ,sanses[i].startTime);
		printf("      ");
		printf("%s" ,sanses[i].endTime);
		printf("      ");
		printf("%d" ,sanses[i].capacity);
		printf("      ");
		printf("%d\n\n" ,sanses[i].remain);
		
	}
	printf("-------------------------------------------------------------------------\n");
	if (purpose==1)
	{

	printf("Press a key to continue...");
	char ch;
	scanf("%c" ,&ch);
	scanf("%c" ,&ch);
	showSansesMenu();
	}
}



 getFilmName(int filmCode)
{
int i=0;
 for(i=0;i<filmsCount;i++)
 {
 	if (films[i].code==filmCode)
 	{
 		strcpy(tmpFilmName,films[i].name);
	 }
 }
}
	
	
readSansesFromFile()
{
	sansesCount=0;
    struct Sans sans;
	FILE* infile;
    infile = fopen ("sanses.dat", "rb");
    if (infile == NULL)
    {
    printf("error oppening file");
        exit (1);
    }
    while(fread(&sans, sizeof(struct Sans), 1, infile))
    {
        sanses[sansesCount]=sans;
        sansesCount++;
	}
	fclose(infile);
}	
