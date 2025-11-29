#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/patient.h"

#define PATIENT_FILE "patient.dat"   // File where all patient records are stored

// Generates a unique Patient ID
int generatePatientID() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    if (!fp) return 1;   // If file doesn't exist → first patient ID = 1

    Patient p;
    int maxID = 0;

    // Read each patient record
    while (fread(&p, sizeof(Patient), 1, fp)) {
        if (p.id > maxID)
            maxID = p.id;    // Track highest ID
    }
    fclose(fp);

    return maxID + 1;        // New patient ID
}
//Adds a new patient record to the file
void addPatient() {
    FILE *fp = fopen(PATIENT_FILE, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Patient p;
    p.id = generatePatientID();   // Auto generate new ID
    getchar();                    // Clear buffer after previous input

    // Get patient name
    printf("Enter Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;   // Remove trailing newline

    // Get age
    printf("Enter Age: ");
    scanf("%d", &p.age);
    getchar();

    // Get gender
    printf("Enter Gender: ");
    fgets(p.gender, sizeof(p.gender), stdin);
    p.gender[strcspn(p.gender, "\n")] = 0;

    // Get disease
    printf("Enter Disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);
    p.disease[strcspn(p.disease, "\n")] = 0;

    // Write record to file
    fwrite(&p, sizeof(Patient), 1, fp);
    fclose(fp);

    printf("\nPatient Added Successfully! ID = %d\n", p.id);
}
// Searches for a patient by ID
void searchPatient() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    Patient p;

    // Linear search through file
    while (fread(&p, sizeof(Patient), 1, fp)) {
        if (p.id == id) {
            printf("\n--- Patient Found ---\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\n",
                   p.id, p.name, p.age, p.gender, p.disease);
            found = 1;
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("\nPatient not found.\n");
}
// Displays all patients from the file
void viewPatients() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    Patient p;
    printf("\n--- Patient List ---\n");

    // Print each patient's details
    while (fread(&p, sizeof(Patient), 1, fp)) {
        printf("ID: %d | Name: %s | Age: %d | Gender: %s | Disease: %s\n",
               p.id, p.name, p.age, p.gender, p.disease);
    }

    fclose(fp);
}
