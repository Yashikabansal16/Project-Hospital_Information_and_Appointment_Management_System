#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/appointment.h"

#define APPOINTMENT_FILE "appoint.dat"   // Binary file to store appointment records

// Generate a unique appointment ID automatically
int generateAppointmentID() {
    FILE *fp = fopen(APPOINTMENT_FILE, "rb");
    if (!fp) return 1;     // If file doesn't exist → start ID from 1

    Appointment a;
    int maxID = 0;

    // Read all appointments and track highest ID
    while (fread(&a, sizeof(Appointment), 1, fp)) {
        if (a.appointID > maxID)
            maxID = a.appointID;
    }

    fclose(fp);
    return maxID + 1;       // New unique appointment ID
}

// Take input for appointment and save it to file
void bookAppointment() {
    FILE *fp = fopen(APPOINTMENT_FILE, "ab");  // Open file in append mode
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    Appointment a;
    a.appointID = generateAppointmentID();   // Auto-generate appointment ID

    // Input: Patient ID
    printf("Enter Patient ID: ");
    scanf("%d", &a.patientID);
    getchar();     // Clear leftover newline from input buffer

    // Input: Doctor Name
    printf("Enter Doctor Name: ");
    fgets(a.doctor, sizeof(a.doctor), stdin);
    a.doctor[strcspn(a.doctor, "\n")] = 0;   // Remove newline

    // Input: Appointment Date
    printf("Enter Date (DD-MM-YYYY): ");
    fgets(a.date, sizeof(a.date), stdin);
    a.date[strcspn(a.date, "\n")] = 0;

    // Input: Appointment Time
    printf("Enter Time (HH:MM): ");
    fgets(a.time, sizeof(a.time), stdin);
    a.time[strcspn(a.time, "\n")] = 0;

    // Write appointment to file
    fwrite(&a, sizeof(Appointment), 1, fp);
    fclose(fp);

    printf("\nAppointment Booked Successfully! Appointment ID = %d\n", a.appointID);
}

// Display all appointments stored in the file
void viewAppointments() {
    FILE *fp = fopen(APPOINTMENT_FILE, "rb");   // Open file in read mode
    if (!fp) {
        printf("No appointments found.\n");
        return;
    }

    Appointment a;
    printf("\n--- Appointment List ---\n");

    // Read and print each appointment
    while (fread(&a, sizeof(Appointment), 1, fp)) {
        printf("Appointment ID: %d | Patient ID: %d | Doctor: %s | Date: %s | Time: %s\n",
               a.appointID, a.patientID, a.doctor, a.date, a.time);
    }

    fclose(fp);
}
