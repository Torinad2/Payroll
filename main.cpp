#include <iostream>
#include <iomanip>
#include "payroll.h"
using namespace std;

/**********************************************************
 * Function: main                                         *
 * -------------------------------------------------------*
 * Main driver function for the payroll program.          *
 * Collects input for hours worked by 7 employees,        *
 * calculates weekly pay using a fixed hourly rate,       *
 * and displays a payroll summary.                        *
 **********************************************************/
int main() {
    const int NUM_EMPLOYEES = 7;

    /******************************************************
     * Create an array of 7 PayRoll objects initialized   *
     * with 0 hours. These will be reassigned after       *
     * collecting valid user input.                       *
     ******************************************************/
    PayRoll employees[NUM_EMPLOYEES] = { PayRoll(0), PayRoll(0), PayRoll(0),
                                         PayRoll(0), PayRoll(0), PayRoll(0), PayRoll(0) };

    /******************************************************
     * Loop to collect valid input for hours worked.      *
     * Input is validated to ensure it is numeric and     *
     * between 0 and 60 inclusive.                        *
     *****************************************************/
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        double hours;
        cout << "Enter hours worked for employee " << (i + 1) << ": ";
        cin >> hours;

        // Validate input: ensure number and within range
        while (cin.fail() || hours < 0 || hours > 60) {
            cin.clear();              // Clear error flag
            cin.ignore(1000, '\n');   // Discard invalid input
            cout << "Error: Please enter hours between 0 and 60 (Number only): ";
            cin >> hours;
        }

        /*************************************************
         * Reassign employee object with validated hours.*
         * Default rate of 20 is used via constructor.   *
         *************************************************/
        employees[i] = PayRoll(hours);
    }

    /*****************************************************
     * Loop to calculate weekly pay for each employee.   *
     *****************************************************/
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        employees[i].calculatePay();
    }

    /*****************************************************
     * Display payroll summary in formatted table.       *
     *****************************************************/
    cout << fixed << showpoint << setprecision(2);
    cout << "\nPayroll Summary:\n";

    /*****************************************************
     * Output each employee's hours, rate, and gross pay.*
     *****************************************************/
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Employee " << (i + 1)
            << " - Hours: " << employees[i].getHoursWorked()
            << ", Rate: $" << employees[i].getHourlyRate()
            << ", Weekly Pay: $" << employees[i].getTotalWeekPay() << endl;
    }


    // Developer credit
    cout << "----------------------------------------" << endl;
    cout << "Developed by: Nikita Baiborodov" << endl;
    cout << "----------------------------------------" << endl;

    return 0; // Indicate successful program termination
}


