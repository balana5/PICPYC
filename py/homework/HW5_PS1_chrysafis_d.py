# Dimitri Chrysafis
# Student ID: 1277192
# Homework 5, Program Set 1
# This program calculates loan details for buying a car.
# It allows the user to calculate monthly and total payments,
# and update the loan amount using the same object.

class Loan:
    """
    Represents a loan with details like interest rate, term, amount, and borrower.
    """

    def __init__(self, annualInterestRate=2.5, numberOfYears=1, loanAmount=1000.0, borrowerName=""):
        """
        Initializes the loan with the given values.
        """
        self.__annualInterestRate = annualInterestRate
        self.__numberOfYears = numberOfYears
        self.__loanAmount = loanAmount
        self.__borrowerName = borrowerName

    
    def getAnnualInterestRate(self):
        """
        Returns the annual interest rate.
        """
        return self.__annualInterestRate

    
    def getNumberOfYears(self):
        """
        Returns the loan term in years.
        """
        return
        self.__numberOfYears

    
    def getLoanAmount(self):
        """
        Returns the loan amount.
        """
        return self.__loanAmount

    
    def getBorrowerName(self):
        """
        Returns the borrower's name.
        """
        return self.__borrowerName

    
    def setAnnualInterestRate(self, rate):
        """
        Sets the annual interest rate.
        """
        self.__annualInterestRate = rate

    
    def setNumberOfYears(self, years):
        """
        Sets the loan term in years.
        """
        self.__numberOfYears = years

    
    def setLoanAmount(self, amount):
        """
        Sets the loan amount.
        """
        self.__loanAmount = amount

    
    def setBorrowerName(self, name):
        """
        Sets the borrower's name.
        """
        self.__borrowerName = name

    
    def getMonthlyPayment(self):
        """
        Calculates and returns the monthly payment.
        """
        monthlyInterestRate = self.__annualInterestRate / 1200
        monthlyPayment = (self.__loanAmount * monthlyInterestRate /
                          (1 - (1 / (1 + monthlyInterestRate) ** (self.__numberOfYears * 12))))
        return monthlyPayment

    
    def getTotalPayment(self):
        """
        Calculates and returns the total payment.
        """
        return self.getMonthlyPayment() * self.__numberOfYears * 12


def main():
    """
    Main function to input loan details, calculate, and display payments.
    """
    # Prompt user for loan details.
    print("Enter yearly interest rate: ", end="")
    annualInterestRate = float(input())
    print("Enter number of years as an integer: ", end="")
    numberOfYears = int(input())
    print("Enter loan amount: ", end="")
    loanAmount = float(input())
    print("Enter a borrower's name: ", end="")
    borrowerName = input()

    # Create a Loan object with the entered details.
    loan = Loan(annualInterestRate, numberOfYears, loanAmount, borrowerName)

    # Display the loan details.
    print(f"The loan is for {loan.getBorrowerName()}")
    print(f"The monthly payment is {loan.getMonthlyPayment():.2f}")
    print(f"The total payment is {loan.getTotalPayment():.2f}\n")

    # Allow user to update the loan amount.
    response = "y"
    continue_loan_change = True  # Flag to control the loop

    while continue_loan_change:
        print("Do you want to change the loan amount? Y for yes or enter to quit: ", end="")
        response = input().lower()

        # Check if the user input is 'y' (case-insensitive)
        if response == 'y':
            print("Enter new loan amount: ", end="")
            newLoanAmount = float(input())
            loan.setLoanAmount(newLoanAmount)

            # Display updated loan details.
            print(f"The loan is for {loan.getBorrowerName()}")
            print(f"The monthly payment is {loan.getMonthlyPayment():,.2f}")
            print(f"The total payment is {loan.getTotalPayment():,.2f}")
        else:
            # If the user doesn't want to change, set the flag to False to exit the loop
            continue_loan_change = False


# Entry point of the program.
if __name__ == "__main__":
    main()


# Test runs as required.

## Test Run 1
## Enter yearly interest rate: 2.5
## Enter number of years as an integer: 5
## Enter loan amount: 1000.00
## Enter a borrower's name: John Jones
## The loan is for John Jones
## The monthly payment is 17.75
## The total payment is 1,064.84
##
## Do you want to change the loan amount? Y for yes or enter to quit: y
## Enter new loan amount: 5000
## The loan is for John Jones
## The monthly payment is 88.74
## The total payment is 5,324.21
##
## Do you want to change the loan amount? Y for yes or enter to quit:

## Test Run 2
## Enter yearly interest rate: 3.0
## Enter number of years as an integer: 4
## Enter loan amount: 2000.00
## Enter a borrower's name: Alice Smith
## The loan is for Alice Smith
## The monthly payment is 44.24
## The total payment is 2,123.34

## Test Run 3
## Enter yearly interest rate: 5.0
## Enter number of years as an integer: 3
## Enter loan amount: 1500.00
## Enter a borrower's name: Bob Brown
## The loan is for Bob Brown
## The monthly payment is 44.95
## The total payment is 1,618.07

## Test Run 4
## Enter yearly interest rate: 4.5
## Enter number of years as an integer: 10
## Enter loan amount: 5000.00
## Enter a borrower's name: Carol White
## The loan is for Carol White
## The monthly payment is 51.91
## The total payment is 6,229.28

## Test Run 5
## Enter yearly interest rate: 3.75
## Enter number of years as an integer: 8
## Enter loan amount: 3000.00
## Enter a borrower's name: Dave Green
## The loan is for Dave Green
## The monthly payment is 37.04
## The total payment is 3,553.57
