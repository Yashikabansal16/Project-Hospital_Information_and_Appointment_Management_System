#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/patient.h"

#define PATIENT_FILE "patient.dat"

int generatePatientID() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    if (!fp) return 1;

    Patient p;
    int maxID = 0;

    while (fread(&p, sizeof(Patient), 1, fp)) {
        if (p.id > maxID)
            maxID = p.id;
    }
    fclose(fp);
    return maxID + 1;
}

void addPatient() {
    FILE *fp = fopen(PATIENT_FILE, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Patient p;
    p.id = generatePatientID();
    getchar(); // clear buffer

    printf("Enter Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &p.age);
    getchar();

    printf("Enter Gender: ");
    fgets(p.gender, sizeof(p.gender), stdin);
    p.gender[strcspn(p.gender, "\n")] = 0;

    printf("Enter Disease: ");
    fgets(p.disease, sizeof(p.disease), stdin);
    p.disease[strcspn(p.disease, "\n")] = 0;

    fwrite(&p, sizeof(Patient), 1, fp);
    fclose(fp);

    printf("\nPatient Added Successfully! ID = %d\n", p.id);
}

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

void viewPatients() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    Patient p;
    printf("\n--- Patient List ---\n");
    while (fread(&p, sizeof(Patient), 1, fp)) {
        printf("ID: %d | Name: %s | Age: %d | Gender: %s | Disease: %s\n",
               p.id, p.name, p.age, p.gender, p.disease);
    }
    fclose(fp);
}
