# Dental Clinic Project

This project simulates a dental clinic system where patients can book appointments with dentists for various treatments.

## Tests

The following tests are performed in `main.cpp`:

### Successful Scenarios

1. Creating clinics
2. Creating patients
3. Creating dentists
4. Creating treatments
5. Adding patients to the clinics
6. Adding dentists to the clinics
7. Booking appointments
8. Printing all appointments in the clinics
9. Printing all dentists in the clinics
10. Printing all patients in the clinics
11. Removing an appointment
12. Adding the treatments to patients and dentists
13. Printing the treatments of patients
14. Printing the clinics of patients
15. Printing the treatments dentists can perform
16. Printing the clinic of a dentist

### Unsuccessful Scenarios

1. Attempt to add a patient who is already in the clinic
2. Attempt to add a dentist who is already in the clinic
3. Attempt to book an appointment at an already occupied time
4. Attempt to find a dentist who is not in the clinic
5. Attempt to find a patient who is not in the clinic
6. Attempt to book an appointment with a dentist who cannot perform the required treatment.
7. Attempt to add a treatment to a patient that cannot be performed by any of his dentists.
8. Attempt to remove an appointment that does not exist.
9. Attempt to find a treatment that does not exist.
10. Attempt to add a clinic to a patient who is already registered in that clinic.

*Orthographic issues in this document were formatted using GitHub Copilot.*