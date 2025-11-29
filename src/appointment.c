#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/appointment.h"

#define APPOINTMENT_FILE "appoint.dat"

int generateAppointmentID() {
    FILE *fp = fopen(APPOINTMENT_FILE, "rb");
    if (!fp) return 1;

    Appointment a;
    int maxID = 0;

    while (fread(&a, sizeof(Appointment), 1, fp)) {
        if (a.appointID > maxID)
            maxID = a.appointID;
    }
    fclose(fp);
    return maxID + 1;
}

void bookAppointment() {
    FILE *fp = fopen(APPOINTMENT_FILE, "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Appointment a;
    a.appointID = generateAppointmentID();
    printf("Enter Patient ID: ");
    scanf("%d", &a.patientID);
    getchar();

    printf("Enter Doctor Name: ");
    fgets(a.doctor, sizeof(a.doctor), stdin);
    a.doctor[strcspn(a.doctor, "\n")] = 0;

    printf("Enter Date (DD-MM-YYYY): ");
    fgets(a.date, sizeof(a.date), stdin);
    a.date[strcspn(a.date, "\n")] = 0;

    printf("Enter Time (HH:MM): ");
    fgets(a.time, sizeof(a.time), stdin);
    a.time[strcspn(a.time, "\n")] = 0;

    fwrite(&a, sizeof(Appointment), 1, fp);
    fclose(fp);

    printf("\nAppointment Booked Successfully! Appointment ID = %d\n", a.appointID);
}

void viewAppointments() {
    FILE *fp = fopen(APPOINTMENT_FILE, "rb");
    if (!fp) {
        printf("No appointments found.\n");
        return;
    }

    Appointment a;
    printf("\n--- Appointment List ---\n");
    while (fread(&a, sizeof(Appointment), 1, fp)) {
        printf("Appointment ID: %d | Patient ID: %d | Doctor: %s | Date: %s | Time: %s\n",
               a.appointID, a.patientID, a.doctor, a.date, a.time);
    }
    fclose(fp);
}
