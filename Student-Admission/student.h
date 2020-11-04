/*
Author name : K.Madhuri
Registration number : 201046022
Branch : Big Data and Data Analytics
Date : 04-11-2020
Description: This file contains function declarations, structure declarations and some variable declarations.
*/
#include <stdint.h>
#include <stdio.h>
#include "appconstt.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

struct _student_ {
    char name[STUDENT_NAME_LEN];
    int32_t regnumber;
    char program[PROGRAM_NAME_LEN];
    char email[EMAIL_LEN];
    char application_status[STATUS_LEN];
    int32_t ug_marks;
};
typedef struct _student_ Student;

struct _program_ {
    int32_t big_data_seats;
    int32_t machine_learning_seats;
    int32_t embedded_systems_seats;
};

typedef struct _program_ Program;

static int32_t filled_bda_seats = 0;
static int32_t filled_ml_seats = 0;
static int32_t filled_es_seats = 0;
static int32_t total_filled_seats = 0;
static int32_t total_seats = 0;

void initialise_program_seats();
Program program_seats(int32_t bda, int32_t ml, int32_t es);
void student_new(Student *st);
int32_t update_status(char program_name[]);
void display_total_seats(Program pg);
void display_filled_seats();
void display(Student *st);
void waiting_list(Student *st);
void display_waiting_list(Student *st);
void menu();
#endif // STUDENT_H_INCLUDED
