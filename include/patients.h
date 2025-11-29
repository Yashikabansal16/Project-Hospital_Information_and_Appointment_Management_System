#ifndef PATIENT_H
#define PATIENT_H

// Struct for Patient
typedef struct {
    int patientID;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
} Patient;

// Function declarations for patient operations
void addPatient();
void searchPatient();
void updatePatient();
void deletePatient();

#endif
