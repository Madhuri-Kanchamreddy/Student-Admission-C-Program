/*
Author name : K.Madhuri
Registration number : 201046022
Branch : Big Data and Data Analytics
Date : 04-11-2020
Description: This file contains function definitions for the program.
*/
#include <string.h>
#include "student.h"
#include <assert.h>
#include <stdio.h>

static int32_t application_count = 0;

void initialise_program_seats() {
    Program pg = program_seats(50, 50, 50);
    total_seats = pg.big_data_seats + pg.embedded_systems_seats + pg.machine_learning_seats;
    display_total_seats(pg);
}

Program program_seats(int32_t bda, int32_t ml, int32_t es){
    Program pg = {bda, ml, es};
    return pg;
}

void student_new(Student *st){
    int32_t appno, marks, stat;
    printf("Enter the application number:\n");
    scanf("%d",&appno);
    printf("Enter the name of the student:\n");
    scanf("%s",st[appno].name);
    printf("Enter email id of the student:\n");
    scanf("%s",st[appno].email);
    printf("Enter the ug marks:\n");
    scanf("%d",&st[appno].ug_marks);
    marks = st[appno].ug_marks;
    if(marks > 5 && marks <= 10)
        strcpy(st[appno].application_status,"Accepted");
    else if(marks <= 5){
        strcpy(st[appno].application_status,"Rejected");
        application_count += 1;
        return;
    }
    printf("Enter the program name in capital letters:\n");
    scanf("%s",st[appno].program);
    stat = update_status(st[appno].program);
    if (stat == 1){
        strcpy(st[appno].application_status,"Alloted");
        st[appno].regnumber += 1;
        printf("Seat is alloted\n");
    }
    else{
        strcpy(st[appno].application_status,"Waiting");
        printf("Seats are filled in this program\n");
    }
    application_count += 1;
}

int32_t update_status(char program_name[]){
    if(!strcmp(program_name,"BDA")){
        if(filled_bda_seats < 50){
            filled_bda_seats += 1;
            total_filled_seats = filled_bda_seats + filled_es_seats + filled_ml_seats;
            return 1;
        }
        else
            return 0;
    }
    else if(!strcmp(program_name,"ES")){
        if(filled_es_seats < 50){
            filled_es_seats += 1;
            total_filled_seats = filled_bda_seats + filled_es_seats + filled_ml_seats;
            return 1;
        }
        else
            return 0;
    }
    else if(!strcmp(program_name,"ML")){
        if(filled_ml_seats < 50){
            filled_ml_seats += 1;
            total_filled_seats = filled_bda_seats + filled_es_seats + filled_ml_seats;
            return 1;
        }
        else
            return 0;
    }
    else{
        printf("Invalid program name\n");
        return 0;
    }
}

void display_filled_seats(){
    printf("Total number of seats filled in all the programs collectively: %d\n", total_filled_seats);
    printf("Total number of seats filled in BDA program: %d\n", filled_bda_seats);
    printf("Total number of seats filled in ES program: %d\n",filled_es_seats);
    printf("Total number of seats filled in ML program: %d\n",filled_ml_seats);
}

void display(Student *st){
    int i;
    for(i=1; i<=application_count; i++){
        printf("Name: %s\n",st[i].name);
        printf("Registration Number: %d\n",st[i].regnumber);
        printf("Email id: %s\n",st[i].email);
        printf("Marks: %d\n",st[i].ug_marks);
        printf("Program: %s\n",st[i].program);
        printf("Application status: %s\n",st[i].application_status);
    }
}

void waiting_list(Student *st){
    int i, count=0, stat;
    for(i=0; i<=application_count; i++){
        if(!strcmp(st[i].application_status,"Waiting")){
            printf("Enter any other program name:\n");
            scanf("%s",st[i].program);
            count += 1;
            stat = update_status(st[i].program);
            if(stat == 1){
                strcpy(st[i].application_status,"Alloted");
                st[i].regnumber += 1;
            }
            else{
                printf("Enter any other program name:\n");
                scanf("%s",st[i].program);
                count += 1;
                stat = update_status(st[i].program);
                if(stat == 1){
                    strcpy(st[i].application_status,"Alloted");
                    st[i].regnumber += 1;
                }
                else{
                    if(count == 2)
                        return;
                }
            }
        }
    }
}

void display_waiting_list(Student *st){
    int i;
    for(i=1; i <= application_count; i++){
        if(!strcmp(st[i].application_status,"Waiting")){
            printf("Name: %s\n",st[i].name);
            printf("Registration Number: %d\n",st[i].regnumber);
            printf("Email id: %s\n",st[i].email);
            printf("Marks: %d\n",st[i].ug_marks);
            printf("Program: %s\n",st[i].program);
        }
    }
}

void display_total_seats(Program pg){
    printf("Total number of seats in bda: %d\n", pg.big_data_seats);
    printf("Total number of seats in es: %d\n",pg.embedded_systems_seats);
    printf("Total number of seats in ml: %d\n",pg.machine_learning_seats);
    printf("Total number of seats collectively: %d\n",total_seats);
}

void menu(){
    printf("Below is the menu for admission process\n");
    printf("1.Initialise the total number of seats for each program\n");
    printf("2.Register new student details\n");
    printf("3.Display the total number of seats filled for each program\n");
    printf("4.Display the list of students\n");
    printf("5.Display waiting list students\n");
    printf("6.Manage seats for the students in waiting list\n");
}
