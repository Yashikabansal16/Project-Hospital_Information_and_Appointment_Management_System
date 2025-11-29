#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "appointment.h"

void showMainMenu() {
    printf("\n===== Hospital Management System =====\n");
    printf("1. Add Patient\n");
    printf("2. Search Patient\n");
    printf("3. View All Patients\n");
    printf("4. Book Appointment\n");
    printf("5. View All Appointments\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    while (1) {
        showMainMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: searchPatient(); break;
            case 3: viewPatients(); break;
            case 4: bookAppointment(); break;
            case 5: viewAppointments(); break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
