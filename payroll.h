#ifndef PAYROLL_H
#define PAYROLL_H

#include <iostream>
#include <cstdlib> // Include for exit() and EXIT_FAILURE

/**********************************************************
 * Class: PayRoll                                         *
 * -------------------------------------------------------*
 * Represents a payroll entry for a single employee.      *
 * Stores the number of hours worked, hourly rate,        *
 * and calculates total weekly gross pay.                 *
 **********************************************************/
class PayRoll {

private:

    /******************************************************
     * hourlyRate: The employee's hourly pay rate.        *
     * hoursWorked: The number of hours worked (0–60).    *
     * totalWeekPay: Gross pay = hourlyRate ? hoursWorked.*
     ******************************************************/
    double hourlyRate;
    double hoursWorked;
    double totalWeekPay;

public:

    /******************************************************
     * Constructor: PayRoll                               * 
     * ---------------------------------------------------*
     * Initializes the object with the given hours and    *
     * hourly rate (default = 20).                        *
     * Validates that hours are in the range 0–60.        *
     * Exits the program if invalid input is provided.    *
     ******************************************************/
    PayRoll(double hours, double rate = 20) {

        if (hours >= 0 && hours <= 60) {
            hoursWorked = hours;
        }
        else {
            std::cout << "Error: Hours must be between 0 and 60.\n";
            exit(EXIT_FAILURE);
        }

        hourlyRate = rate;
        totalWeekPay = 0.0;
    }

    /******************************************************
     * Function: calculatePay                             *
     * ---------------------------------------------------*
     * Calculates gross weekly pay by multiplying         *
     * hoursWorked by hourlyRate.                         *
     *****************************************************/
    void calculatePay() {
        totalWeekPay = hourlyRate * hoursWorked;
    }

    /******************************************************
     * Function: getHourlyRate                            *
     * ---------------------------------------------------*
     * Returns the hourly pay rate.                       *
     ******************************************************/
    double getHourlyRate() const {
        return hourlyRate;
    }

    /******************************************************
     * Function: getHoursWorked                           *
     * ---------------------------------------------------*
     * Returns the number of hours worked.                *
     ******************************************************/
    double getHoursWorked() const {
        return hoursWorked;
    }

    /*****************************************************
     * Function: getTotalWeekPay                         *
     * --------------------------------------------------*
     * Returns the calculated total weekly gross pay.    *
     *****************************************************/
    double getTotalWeekPay() const {
        return totalWeekPay;
    }
};

#endif
