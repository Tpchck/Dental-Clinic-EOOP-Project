//
// Created by Tpshck on 3/25/2024.
//

#include "Appointment.h"
#include "DentalClinic.h"
#include "System.h"

using namespace std;

int main() {

    DentalClinic clinic;

    clinic.addTreatment("Teeth Whitening",
                        "Lightens teeth and helps to remove stains and discoloration",
                        250.00, "Dentist-Therapist");
    clinic.addTreatment("Dental Crowns",
                        "Caps placed on top of damaged teeth to restore shape, size, strength, and appearance",
                        500.00, "Dentist-Surgeon");
    clinic.addTreatment("Braces", "Used to straighten teeth and correct bite issues", 3000.00,
                        "Orthodontist");

    clinic.addDentist("Dr. Smith", "Dentist-Therapist");
    clinic.addDentist("Dr. Bruno", "Dentist-Surgeon");
    clinic.addDentist("Dr. Leopold", "Orthodontist");

    clinic.addPatient("John Doe", 30, "123-456-7890");
    clinic.addPatient("Alex Margo", 24, "510-229-1488");

    clinic.addPatientMedicalRecord(clinic.findPatient("John Doe")->getId(), {"Cavities", "Filling", "2024-01-10", "Dr Bruno"});
    clinic.addPatientMedicalRecord(clinic.findPatient("Alex Margo")->getId(), {"Deep caries", "Caries treatment", "2024-02-15", "Dr Smith"});

    //clinic.findPatient("johndoe")->printMedicalRecord();

    Appointment* successAppointment1 = clinic.bookAppointment("2024-04-01", "11:00", clinic.findDentist("dr.bruno"), clinic.findPatient("Alex Margo"), clinic.findTreatment("Dental Crowns"));
    //Appointment* successAppointment2 = clinic.bookAppointment("2024-04-01", "12:00", clinic.findDentist("Dr. Bruno"), clinic.findPatient("Alex Margo"), clinic.findTreatment("Dental Crowns"));

    ///Functionality to edit appointment
    /*    successAppointment->editDate("2024-04-02");
    successAppointment->editTime("12:00");
    successAppointment->editDentist(clinic.findDentist("Dr. Smith"));
    successAppointment->editPatient(clinic.findPatient("John Doe"));
    successAppointment->setTreatment(clinic.findTreatment("Braces"));*/

    //printAllTreatments(clinic.getTreatments());

    clinic.deleteAppointment(successAppointment1->getId());

    //Appointment *failedAppointment1 = clinic.bookAppointment("2024-04-01", "11:00", clinic.findDentist("Dr. Leopold"), clinic.findPatient("John Doe"), clinic.findTreatment("Dental Crowns"));
    //Appointment *failedAppointment2 = clinic.bookAppointment("2024-04-01", "11:00", clinic.findDentist("Dr. Bruno"), clinic.findPatient("John Doe"), clinic.findTreatment("Braces"));

    printAllAppointments(clinic.getAppointments());

    return 0;
} 