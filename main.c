#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
#define Highlight 0X70
#define Normal 0X07
#define UpArrow 72
#define DownArrow 80
#define RightArrow 67
#define LeftArrow 68
#define PageUp 73
#define PageDown 81
#define HomeKey 71
#define EndKey 79
#define Enter 13
#define BackKey 8
#define EscKey 27
#define TabKey 9

struct Employees{
int id;
char name[100];
int salary;
int bonus;
int deduction;
int state;
}emps[100];

int pos=0;

void add_single_emp(){
    gotoxy(0,4);
    printf("Employee ID : ");

    gotoxy(50,4);
    printf("Employee Name : ");

    gotoxy(0,6);
    printf("Employee Salary : ");

    gotoxy(50,6);
    printf("Employee Bonus : ");

    gotoxy(0,8);
    printf("Employee Deduction : ");


    gotoxy(14,4);
    fflush(stdin);
    scanf("%i" , &emps[pos].id);

    gotoxy(66,4);
    fflush(stdin);
    gets(emps[pos].name);

    gotoxy(18,6);
    fflush(stdin);
    scanf("%i" , &emps[pos].salary);

    gotoxy(68,6);
    fflush(stdin);
    scanf("%i" , &emps[pos].bonus);

    gotoxy(21,8);
    fflush(stdin);
    scanf("%i" , &emps[pos].deduction);

    emps[pos].state = 1;

    pos++;

    gotoxy(0,11);
    printf("################  SUCCESS  ################\n");

}

void add_muli_emp(){
    int emp_num;
    printf("How Many Employees Yow Want To Add ?    ");
    scanf("%i" , &emp_num );
    printf("\n");
    for(int i=0 ; i<emp_num ;i++){
        printf("--------------Add Employee Number %i ------------ \n ",i+1);
        add_single_emp();
        clrscr();
    }
    gotoxy(10,10);
    printf("################  ALL EMPLOYEES ADDED  ################\n");
}

void display_single_emp(){
    int id;
    int flag = 0;
    printf("Enter Employee ID :  ");
    scanf("%i" , &id);

    for(int i=0 ; i<pos ;i++){
        if(emps[i].id == id && emps[i].state == 1){
            flag=1;
            gotoxy(0,4);
            printf("Employee ID : %i" ,emps[i].id );

            gotoxy(50,4);
            printf("Employee Name : %s",emps[i].name);

            gotoxy(0,6);
            printf("Employee Salary : %i",emps[i].salary);

            gotoxy(50,6);
            printf("Employee Bonus : %i",emps[i].bonus);

            gotoxy(0,8);
            printf("Employee Deduction : %i \n",emps[i].deduction);
        }
    }
    if(flag == 0){
        printf("################### Employee Does not Exist ################## \n");
    }

}

void display_all_emp(){
    for(int indx=0 ; indx<pos ;indx++){
        if(emps[indx].state == 1){
            printf("\n-------Employee Number %i ---------- \n" , indx+1);
            gotoxy(0,4+indx*8);
            printf("Employee ID : %i" ,emps[indx].id );

            gotoxy(50,4+indx*8);
            printf("Employee Name : %s",emps[indx].name);

            gotoxy(0,6+indx*8);
            printf("Employee Salary : %i",emps[indx].salary);

            gotoxy(50,6+indx*8);
            printf("Employee Bonus : %i",emps[indx].bonus);

            gotoxy(0,8+indx*8);
            printf("Employee Deduction : %i \n",emps[indx].deduction);
        }


    }
}

void Auto_emp(){
    char ss[50] = "Test Employee";
    int emp_num;
    printf("How Many Employees You Want To Auto Add :  ");
    scanf("%i" , &emp_num);
    printf("\n");

    for(int i=0 ;i<emp_num ;i++){

        printf("######### AUTO ADD NUMBER %i ############## \n \n" ,i+1);
        emps[pos].id = (i+100)*10;
        strcpy(emps[pos].name,ss);
        emps[pos].salary = 1000+(i*10);
        emps[pos].bonus = 100 +(i*10);
        emps[pos].deduction = 50*i;
        emps[pos].state = 1;
        pos++;
    }
    printf("########################## Done ############################## \n ");
}

void delete_single_emp(){
    int id;
    int flag=0;
    printf("Enter Employee ID That You Want To Delete :  ");
    scanf("%i" , &id);
    printf("\n");

    for(int i=0 ; i<pos ;i++){
        if(emps[i].id == id){
            emps[i].state=0;
            printf("######### Employee Deleted ############### \n");
            flag=1;
            break;
        }
    }
    if(flag == 0 )
        printf("################# Employee Not Found! ################## \n");

}

void display_many_emp(){
    int emps_indx[50];
    int emps_num;
    printf("How Many Employees You Want To Display ?  ");
    scanf("%i" , &emps_num);

    for(int i=0 ;i<emps_num ;i++){
        printf("Enter Employee Number %i ID : " , i+1);
        scanf("%i" , &emps_indx[i]);
    }

    clrscr();

    for(int i=0 ; i<emps_num ;i++){
            for(int y=0 ;y<pos;y++){
                if(emps[y].id == emps_indx[i]){
                    printf("\n-------Employee With ID %i ---------- \n" , emps_indx[i]);
                    gotoxy(0,4+i*8);
                    printf("Employee ID : %i" ,emps[y].id );

                    gotoxy(50,4+i*8);
                    printf("Employee Name : %s",emps[y].name);

                    gotoxy(0,6+i*8);
                    printf("Employee Salary : %i",emps[y].salary);

                    gotoxy(50,6+i*8);
                    printf("Employee Bonus : %i",emps[y].bonus);

                    gotoxy(0,8+i*8);
                    printf("Employee Deduction : %i \n",emps[y].deduction);

                    break;
                }
            }
}
}
void delete_all_emps(){
    char choice;
    printf("Are You Sure You Want To Delete All Employees ?  y/n \n");
    fflush(stdin);
    scanf("%c" , &choice);

    if(choice == 'y'){
        pos=0;
        printf("################### All Employees Deleted ############### \n");
    }
}

void delete_many_emps(){
    int emps_indx[50];
    int emps_num;
    printf("How Many Employees You Want To Delete ?  ");
    scanf("%i" , &emps_num);

    for(int i=0 ;i<emps_num ;i++){
        printf("Enter Employee Number %i ID : " , i+1);
        scanf("%i" , &emps_indx[i]);
    }

    clrscr();

    for(int i=0 ; i<emps_num ;i++){
            int flag=0;
            for(int y=0 ;y<pos;y++){
                if(emps[y].id == emps_indx[i] && emps[y].state == 1){
                    emps[y].state =0;
                    printf("\n-------Employee With ID %i Deleted ---------- \n" , emps_indx[i]);
                    flag=1;
                    break;
                }
            }
            if(flag==0) printf("\n-------Employee With ID %i Not Found ---------- \n" , emps_indx[i]);
}

}

void main_menu(){
    char items[15][50] = {"Add Single Employee" ,
                        "Add Many Employees",
                        "Display Single Employee",
                        "Display Many Employees",
                        "Display All Employees",
                        "Delete Single Employee",
                        "Delete Many Employees",
                        "Delete All Employees",
                        "Automatically Add Employees",
                        "Exit"};
    int cursor = 0;
    int flag = 1;
    char inp;
    do{
        textattr(Normal);
        clrscr();
        for(int i=0 ; i<10 ;i++){
            if(i==cursor){
                textattr(Highlight);
                gotoxy(2,2+i*2);
                printf("%s :" , items[i]);
            }
            else{
                textattr(Normal);
                gotoxy(2,2+i*2);
                printf("%s :" , items[i]);
            }
        }

    inp=getch();

    switch(inp){
        case 224:
        case -32:
        case 0:
            inp = getch();
            switch(inp){
                case UpArrow:
                case PageUp:
                    cursor--;
                    if(cursor<0) cursor=9;
                    break;

                case DownArrow:
                case PageDown:
                    cursor++;
                    if(cursor>9) cursor=0;
                    break;

                case HomeKey:
                    cursor=0;
                    break;

                case EndKey:
                    cursor=9;
                    break;
                        }
            break;

        case Enter:
            switch(cursor){
                case 0:
                    clrscr();
                    add_single_emp();
                    getch();
                    break;

                case 1:
                    clrscr();
                    add_muli_emp();
                    getch();

                    break;
                case 2:
                    clrscr();
                    display_single_emp();
                    getch();
                    break;
                case 3:
                    clrscr();
                    display_many_emp();
                    getch();
                    break;
                case 4:
                    clrscr();
                    display_all_emp();
                    getch();
                    break;
                case 5:
                    clrscr();
                    delete_single_emp();
                    getch();
                    break;
                case 6:
                    clrscr();
                    delete_many_emps();
                    getch();
                    break;
                case 7:
                    clrscr();
                    delete_all_emps();
                    getch();
                    break;
                case 8:
                    clrscr();
                    Auto_emp();
                    getch();
                    break;

                    break;
                case 9:
                    break;
            }
            break;

        case BackKey:
            clrscr();
            break;

        case EscKey:
            flag=0;
            break;

        case TabKey:
            cursor++;
            if(cursor > 9) cursor=0;
            break;

    }

    }while(flag);
}


int main()
{
    main_menu();
    return 0;
}
