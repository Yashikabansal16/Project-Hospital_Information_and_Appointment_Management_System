#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "patient.h"
#include "appointment.h"

// Function declarations for file handling
void savePatientToFile(Patient p);
void loadPatientsFromFile();
void saveAppointmentToFile(Appointment a);
void loadAppointmentsFromFile();

#endif
