#ifndef APPOINTMENT_H
#define APPOINTMENT_H

// Struct for Appointment
typedef struct {
    char appointmentID[10];
    int patientID;       // Reference to Patient
    char doctorName[50];
    char department[50];
    char date[15];       // YYYY-MM-DD
    char time[10];       // HH:MM AM/PM
    char status[15];     // Completed, Pending, Cancelled
} Appointment;

// Function declarations for appointment operations
void bookAppointment();
void cancelAppointment();
void viewAppointments();

#endif
