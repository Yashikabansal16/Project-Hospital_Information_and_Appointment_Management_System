#include <stdio.h>
#include <stdlib.h>
#include "../include/patient.h"
#include "../include/appointment.h"
#include "../include/file_utils.h"

void showMainMenu() {
    printf("\n===== Hospital Management System =====\n");
    printf("1. Manage Patients\n");
    printf("2. Manage Appointments\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void showPatientMenu() {
    printf("\n--- Patient Menu ---\n");
    printf("1. Add Patient\n");
    printf("2. Search Patient\n");
    printf("3. Update Patient\n");
    printf("4. Delete Patient\n");
    printf("5. Back to Main Menu\n");
    printf("Enter your choice: ");
}

void showAppointmentMenu() {
    printf("\n--- Appointment Menu ---\n");
    printf("1. Book Appointment\n");
    printf("2. Cancel Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Back to Main Menu\n");
    printf("Enter your choice: ");
}

int main() {
    int mainChoice, patientChoice, appointmentChoice;
    
    while (1) {
        showMainMenu();
        scanf("%d", &mainChoice);
        
        switch (mainChoice) {
            case 1:
                do {
                    showPatientMenu();
                    scanf("%d", &patientChoice);
                    switch (patientChoice) {
                        case 1: addPatient(); break;
                        case 2: searchPatient(); break;
                        case 3: updatePatient(); break;
                        case 4: deletePatient(); break;
                        case 5: break;
                        default: printf("Invalid choice!\n");
                    }
                } while (patientChoice != 5);
                break;

            case 2:
                do {
                    showAppointmentMenu();
                    scanf("%d", &appointmentChoice);
                    switch (appointmentChoice) {
                        case 1: bookAppointment(); break;
                        case 2: cancelAppointment(); break;
                        case 3: viewAppointments(); break;
                        case 4: break;
                        default: printf("Invalid choice!\n");
                    }
                } while (appointmentChoice != 4);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
