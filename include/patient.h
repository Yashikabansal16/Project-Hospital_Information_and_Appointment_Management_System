#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
} Patient;

// Patient function prototypes
int generatePatientID();
void addPatient();
void searchPatient();
void viewPatients();

#endif
