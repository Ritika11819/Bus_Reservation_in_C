#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SEATS 25
#define MAX_HISTORY 25
#define MAX_USERS 20

struct passengerdetails {

    int age;
    char name[50];
    char gender;
    char contact[20];
    char routeofbus[10];
    int seatnumber;
};

struct Register{

    char username[50];
    char password[13];

};

struct passengerdetails history[MAX_HISTORY];
int count1=0;

struct passengerdetails seats[MAX_SEATS];
int count2=0;
int bookedseats[6]={0};

struct Register usermax[MAX_USERS];
int count3=0;

void newregister(); 
void ticketmodification();  
void bookinghistory();  
void ticketbooking();  
void ticketcancel();   
void displayseats(); 
void routedisplay(); 
int login();

int main(){

    int a;
    int flag1=1;

    printf("-------------------------------- ONE STEP TO GO - BOOK YOUR BUS TICKET!!!------------------------\n\n\n");

    while(flag1){

    printf("1. ENROLL (NEW REGISTRATION)\n");
    printf("2. LOGIN (EXISTING USER) \n");
    printf("3. EXIT \n");

    printf("ENTER YOUR CHOICE : ");

    scanf("%d",&a);

    printf("\n\n");


    switch(a){

        case 1:
        newregister();
        break;

        case 2: 
        if(login()){

            int choose1;

            int flag = 1;

            while(flag){

            printf("*********************** FOLLOWING OPTIONS ARE AVAILABLE **********************\n\n");
            printf("1. AVAILABLE ROUTES \n");
            printf("2. AVAILABLE SEATS \n");
            printf("3. BOOK TICKETS \n");
            printf("4. CANCEL TICKET \n");
            printf("5. CHECK BOOKING HISTORY \n");
            printf("6. MODIFY PASSENGER DETAILS \n");
            printf("7. EXIT \n");
            printf("Enter your choice: ");
            scanf("%d", &choose1);

            switch(choose1){

                case 1:
                routedisplay();
                break;

                case 2:
                displayseats();
                break;

                case 3:
                ticketbooking();
                break;

                case 4:
                ticketcancel();
                break;

                case 5:
                bookinghistory();
                break;

                case 6:
                ticketmodification();
                break;

                case 7:
                printf("EXITING ...!!!!\n");
                flag=0;
                break;

                default:
                printf("!!!!!!!!!!!!!!!!!!! INVALID CHOICE ENTERED !!!!!!!!!!!!!!!!!!!!!!!\n\n");
            }
              
        }
    }
    break;

    case 3:
    printf("THANK YOU FOR USING THIS SYSTEM . HAPPY TO HELP YOU ! HOPE TO SEE YOU SOON !! SAFE TRAVELS\n\n");
    flag1=0;
    break;

    default:
    printf("PLEASE ENTER VALID OPTION ..\n");

    }

  } 
  return 0;

} 

void newregister(){

    if (count3 >= MAX_USERS) {
        printf("LIMIT REACHED . SORRY COULDN'T REGISTER YOU IN :( \n");
        return;
    }

    struct Register newuser;
    printf("ENTER A USERNAME : ");
    scanf("%s", newuser.username);

    

    for(int i=0;i<count3;i++){
        if(strcmp(usermax[i].username,newuser.username)==0){
            printf("USERNAME ALREADY EXISTS . PLEASE ENTER ANOTHER NAME \n");
            return;
        }
    }

printf("ENTER NEW PASSWORD : ");
scanf("%s", newuser.password);

printf("\n\n");

usermax[count3++] = newuser;
printf("YOU'RE NOW LOGGED IN!! \n\n");

}

int login(){

    char username[50];
    char password[13];
    
    printf("ENTER USERNAME : ");
    scanf("%s",username);

    printf("ENTER YOUR PASSWORD : ");
    scanf("%s",password);

    for(int i=0;i<count3;i++){
        if(strcmp(usermax[i].username,username)==0 && strcmp(usermax[i].password,password)==0){
            printf("SUCCESSFUL LOGIN . WELCOME PASSENGER ! \n\n");
            return 1;
        }
    }

    printf("INVALID LOGIN . TRY AGAIN \n");
    return 0;


}

void ticketmodification(){

     
    int newseatnumber;
    printf("ENTER SEAT NUMBER TO MODIFY DETAILS: ");
    scanf("%d", &newseatnumber);

    if (newseatnumber < 1 || newseatnumber > MAX_SEATS || seats[newseatnumber - 1].seatnumber == 0) {
        printf("THIS SEAT IS NOT BOOKED, UNABLE TO MODIFY.\n");
        return;
    }

    struct passengerdetails *p = &seats[newseatnumber - 1];
    printf("\nMODIFYING DETAILS FOR SEAT NUMBER: %d\n", p->seatnumber);

    
    printf("ENTER NEW PASSENGER NAME: ");
    while ((getchar()) != '\n'); 
    scanf("%[^\n]%*c", p->name);

    
    printf("ENTER NEW AGE: ");
    scanf("%d", &p->age);

    
    printf("ENTER NEW GENDER (M/F): ");
    while ((getchar()) != '\n'); 
    scanf("%c", &p->gender);

    printf("\nCURRENT ROUTE: %s\n", p->routeofbus);
    routedisplay();
    printf("ENTER NEW ROUTE NAME: ");
    while ((getchar()) != '\n'); 
    scanf("%[^\n]%*c", p->routeofbus);

    printf("\nMODIFICATION SUCCESSFUL!\n");
    printf("UPDATED DETAILS:\n");
    printf("NAME: %s\n", p->name);
    printf("AGE: %d\n", p->age);
    printf("GENDER: %c\n", p->gender);
    printf("ROUTE: %s\n", p->routeofbus);
}


void bookinghistory(){

    
    printf("============================ PASSENGER BOOKING HISTORY ===============================\n\n");

    if(count1 == 0){
        printf("BOOKING HISTORY EMPTY \n");
    }


    for (int i = 0; i < count1; i++) {
        printf("SEAT NUMBER : %d\n", history[i].seatnumber);
        printf("NAME OF PASSENGER : %s\n", history[i].name);
        printf("AGE OF PASSENGER : %d\n", history[i].age);
        printf("GENDER : %c\n", history[i].gender);
        printf("ROUTE : %s\n", history[i].routeofbus);
}


if (count1 > MAX_HISTORY){
count1 = MAX_HISTORY;
} 

}

void routedisplay(){
   printf(" ================================ AVAILABLE ROUTES ================================ \n");
   printf("ROUTE 1 : AHMEDABAD TO NADIAD :  TIME-9.00AM\n");
   printf("ROUTE 2 : AHMEDABAD TO NADIAD :  TIME-10.00AM\n");
   printf("ROUTE 3 : AHMEDABAD TO SURAT :  TIME-9.30AM\n");
   printf("ROUTE 4:  SURAT TO RAJKOT :  TIME-10.30AM\n");
   printf("ROUTE 5:  MAHESANA TO AHMEDABAD :  TIME-7.30AM\n");
   printf("ROUTE 6:  GANDHINAGAR TO KUTCH :  TIME-9.15AM\n");
   printf("\n");
}


void displayseats() {
    char routeName[50];
    int flagcheck = 0;

    routedisplay();

    printf("ENTER THE ROUTE NAME TO DISPLAY AVAILABLE SEATS: ");
    while ((getchar()) != '\n'); 
    scanf("%[^\n]%*c", routeName);

   
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].seatnumber == 0 || strcmp(seats[i].routeofbus, routeName) != 0) {
            flagcheck++;
        }
    }

    if (flagcheck == MAX_SEATS) {
        printf("ALL SEATS ARE AVAILABLE FOR ROUTE: %s\n", routeName);
    } else if (flagcheck == 0) {
        printf("NO SEATS AVAILABLE FOR ROUTE: %s\n", routeName);
    } else {
        printf("TOTAL AVAILABLE SEATS FOR ROUTE '%s': %d\n", routeName, flagcheck);
    }

    printf("\n");
}

void ticketbooking(){
  int routeno;


  struct passengerdetails p;
  printf("ENTER YOUR NAME : ");
  while ((getchar()) != '\n');
    scanf("%[^\n]%*c", p.name);

    printf("ENTER YOUR AGE : ");
    
    scanf("%d", &p.age); 


    printf("ENTER YOUR GENDER (M FOR MALE & F FOR FEMALE ): ");
    while ((getchar()) != '\n'); 
    scanf("%c", &p.gender); 

    routedisplay();

     printf("ENTER THE ROUTE NAME: "); 
    while ((getchar()) != '\n'); 
    scanf("%[^\n]%*c", p.routeofbus);

    int flag2 = 0; 
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].seatnumber == 0) { 
            p.seatnumber = i + 1;
            seats[i] = p;           
            history[count1++] = p;  
            flag2 = 1;       
            break;
        }
    }

    if (flag2) {
        printf("TICKET BOOKED SUCCESSFULLY!\n");
        printf("YOUR SEAT NUMBER IS %d FOR ROUTE: %s\n", p.seatnumber, p.routeofbus);
    } else {
        printf("NO SEATS AVAILABLE FOR THIS ROUTE.\n");
    }
}


void ticketcancel() {
    char routename[50];
    int seatnum;
    int flag3 = 0; 

    printf("ENTER YOUR ROUTE NAME: ");
    while ((getchar()) != '\n'); 
    scanf("%[^\n]%*c", routename);

    printf("ENTER THE SEAT NUMBER TO CANCEL: ");
    scanf("%d", &seatnum);

    if (seatnum < 1 || seatnum > MAX_SEATS) {
        printf(" !!!!!!!!!!!!!!!!!!!!!!!! INVALID SEAT NUMBER !!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return;
    }

    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].seatnumber == seatnum && strcmp(seats[i].routeofbus, routename) == 0) {
           
            char confirm;
            printf("ARE YOU SURE YOU WANT TO CANCEL YOUR TICKET? (Y/N): ");
            while ((getchar()) != '\n'); 
            scanf("%c", &confirm);

            if (confirm == 'Y' || confirm == 'y') {

                for (int j = i; j < MAX_SEATS - 1; j++) {
                    seats[j] = seats[j + 1];
                }
                
                seats[MAX_SEATS - 1].seatnumber = 0;
                strcpy(seats[MAX_SEATS - 1].routeofbus, "");
                printf("TICKET CANCELED SUCCESSFULLY!\n");
                flag3 = 1;
                break;
            } else {
                printf("CANCELLATION ABORTED. ENJOY YOUR JOURNEY!\n");
                return;
            }
        }
    }

    if (!flag3) {
        printf("NO BOOKING FOUND FOR SEAT NUMBER %d ON ROUTE '%s'.\n", seatnum, routename);
    }
}


