# Lab 5

# Question 1
# Dimitri Chrysafis
# Description of Program: This program performs operations on a grade dictionary to print keys, values, key-value pairs, sorted key-value pairs, and calculate the average value.

# Given dictionary
grade = {"A": 8, "D": 3, "B": 15, "F": 2, "C": 6}

# a. Print all keys
print("Keys:", list(grade.keys()))

# b. Print all values
print("Values:", list(grade.values()))

# c. Print all key-value pairs
print("Key-Value Pairs:", list(grade.items()))

# d. Print all key-value pairs sorted by key
for key in sorted(grade):
    print(f"Key: {key}, Value: {grade[key]}")

# e. Calculate and print the average value
total = 0
count = 0
for value in grade.values():
    total += value
    count += 1
average = total / count
print("Average Value:", average)

## Test Run 1
## Keys: ['A', 'D', 'B', 'F', 'C']
## Values: [8, 3, 15, 2, 6]
## Key-Value Pairs: [('A', 8), ('D', 3), ('B', 15), ('F', 2), ('C', 6)]
## Key: A, Value: 8
## Key: B, Value: 15
## Key: C, Value: 6
## Key: D, Value: 3
## Key: F, Value: 2
## Average Value: 6.8


# Question 2
# Dimitri Chrysafis
# Description of Program: This program reads tea sales data from a file, processes it into a dictionary, calculates totals for each tea, and prints a sales report sorted by tea name.

# Open and read the file
with open("tea.txt", "r") as file:
    lines = file.readlines()

# Create dictionary for tea sales
tea_sales = {}

tea_sales = {}

for line in lines:
    tea_name = ''
    sales = []
    i = 0

    # Extract tea_name (everything before ':')
    while i < len(line) and line[i] != ':':
        tea_name += line[i]
        i += 1

    # Skip over the ':' character
    i += 1

    # Extract the sales values (everything after ':')
    value = ''
    while i < len(line):
        if line[i] == ':':  # If we find a colon, we complete the current value and start a new one
            if value:
                sales.append(float(value))
                value = ''
        elif line[i] == ' ' or i == len(line) - 1:  # Space or end of line
            if value:
                sales.append(float(value))
                value = ''
        else:
            value += line[i]  # Collect digits for the current number
        i += 1

    # Handle the case where the last value is still pending (without space after it)
    if value:
        sales.append(float(value))

    tea_sales[tea_name] = sales

# Generate report
total_store_sales = [0, 0, 0]

# Print sales report for each tea
for tea in sorted(tea_sales):
    sales = tea_sales[tea]
    total = sum(sales)
    print(f"{tea:<10} {sales[0]:10.2f} {sales[1]:10.2f} {sales[2]:10.2f} {total:10.2f}")
    for i in range(3):
        total_store_sales[i] += sales[i]

# Print total store sales
print(f"{'':<10} {total_store_sales[0]:10.2f} {total_store_sales[1]:10.2f} {total_store_sales[2]:10.2f}")
## Test Run 1
## Ceylon        6700.10    5012.45    6011.00   17723.55
## Earl Grey    10225.25    9025.00    9505.00   28755.25
## Green Tea     8580.00    7201.25    8900.00   24681.25
## Jasmine       9285.15    8276.10    8705.00   26266.25
## Mint Tea      7901.25    4267.00    7056.50   19224.75
##              42691.75   33781.80   40177.50
