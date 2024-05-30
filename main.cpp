//
// Created by Tpshck on 3/25/2024.
//

#include "DentalClinic.h"
#include "Appointment.h"
#include "Patient.h"
#include "Dentist.h"
#include "Treatment.h"

using namespace std;

int main() {
    // Successful scenarios
    // 0. Creating clinics
    DentalClinic clinic1("Brave Teeth Med");
    DentalClinic clinic2("Dental Express");
    // 1. Creating patients
    Patient patient1("Mike Wood", 30, "1234567890");
    Patient patient2("John Dowel", 46, "0987654321");
    // 2. Creating dentists
    Dentist dentist1("Dr. Leopold", "Orthodontics");
    Dentist dentist2("Dr. Bruno", "Surgery");
    // 3. Creating treatments
    Treatment treatment1("Teeth Cleaning", "", 100.0, "Orthodontics");
    Treatment treatment2("Caries Treatment", "", 200.0, "Surgery");
    // 4 Adding patients to the clinics
    clinic1.addPatient(&patient1);
    clinic2.addPatient(&patient1);
    clinic2.addPatient(&patient2);
    // 5 Adding dentists to the clinics
    clinic1.addDentist(&dentist1);
    clinic2.addDentist(&dentist1);
    clinic2.addDentist(&dentist2);
    // 6.1 Booking appointments
    Appointment* appointment1 = clinic1.bookAppointment("2024-04-01", "10:00", &dentist1, &patient1, &treatment1);
    Appointment* appointment2 = clinic1.bookAppointment("2024-04-02", "11:00", &dentist2, &patient1, &treatment2);
    Appointment* appointment3 = clinic2.bookAppointment("2024-04-01", "12:00", &dentist1, &patient2, &treatment1);
    Appointment* appointment4 = clinic2.bookAppointment("2024-04-02", "13:00", &dentist2, &patient2, &treatment2);
    // 6.2 Printing all appointments in the clinics
    cout<<"Appointments in Brave Teeth Med Clinic:"<<endl;
    clinic1.printAllAppointments();
    cout<<"---------------------------------------------"<<endl;
    cout<<"Appointments in Dental Express Clinic:"<<endl;
    clinic2.printAllAppointments();
    // 7. Printing all dentists in the clinics
    clinic1.printAllDentists();
    // 8. Printing all patients in the clinics
    clinic1.printAllPatients();
    // 9. Printing all appointments in the clinics
    clinic1.printAllAppointments();
    // 10. Removing an appointment
    clinic1.removeAppointment("2024-04-01", "10:00", &patient1);
    // 11.1 Add the treatments to patients and dentists
    patient1.addTreatment(&treatment1);
    patient2.addTreatment(&treatment2);
    dentist1.addTreatment(&treatment1);
    dentist2.addTreatment(&treatment2);
    // 11.2 Print the treatments of patients
    patient1.printTreatments();
    // 12. Print the clinics of patients
    patient1.printClinics();
    patient2.printClinics();
    // 13. Print the treatments dentists can perform
    dentist1.printTreatments();
    dentist2.printTreatments();
    // 14. Print the clinic of a dentist
    dentist1.printClinics();


    // Unsuccessful scenarios
    // 1. Attempt to add a patient who is already in the clinic
    clinic1.addPatient(&patient1);
    // 2. Attempt to add a dentist who is already in the clinic
    clinic1.addDentist(&dentist1);
    // 3. Attempt to book an appointment at an already occupied time
    if (clinic1.isDentistAvailable(&dentist1, "2024-04-01", "10:00") && clinic1.canDentistPerformTreatment(&dentist1, &treatment1)) {
        Appointment* appointment2 = clinic1.bookAppointment("2024-04-01", "10:00", &dentist1, &patient1, &treatment1);
    }
    // 4. Attempt to find a dentist who is not in the clinic
    Dentist* dentist3 = clinic1.findDentist("Dr. Nonexistent");
    // 5. Attempt to find a patient who is not in the clinic
    Patient* patient3 = clinic1.findPatient("Markis Nonexistent");
    return 0;
}
