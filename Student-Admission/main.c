/*
Author name : K.Madhuri
Registration number : 201046022
Branch : Big Data and Data Analytics
Date : 04-11-2020

Description : Develop an application for student admission process using C language.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "student.h"

int main()
{
    int choice;
    Student stu[MAX_STUDENTS];
    menu();
    do{
        printf("Choose one option from the above list of options\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            initialise_program_seats();
            break;
        case 2:
            student_new(stu);
            break;
        case 3:
            display_filled_seats();
            break;
        case 4:
            display(stu);
            break;
        case 5:
            display_waiting_list(stu);
            break;
        case 6:
            waiting_list(stu);
            break;
        default:
            assert(choice <= 6);
        }
    }while(choice > 0);
    return 0;
}
