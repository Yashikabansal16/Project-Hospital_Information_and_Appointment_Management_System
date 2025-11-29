#ifndef APPOINTMENT_H
#define APPOINTMENT_H

typedef struct {
    int appointID;
    int patientID;
    char doctor[50];
    char date[15];
    char time[10];
} Appointment;

// Appointment function prototypes
int generateAppointmentID();
void bookAppointment();
void viewAppointments();

#endif
