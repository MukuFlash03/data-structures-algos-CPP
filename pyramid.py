def print_pyramid(last_number):
    # Calculate the number of rows
    num_rows = int((-1 + (1 + 8 * last_number)**0.5) / 2)

    # Loop to print the pyramid
    current_number = 1
    for i in range(1, num_rows + 1):
        # Print spaces to align the numbers
        print(" " * (num_rows - i), end=" ")

        # Print numbers for the current row
        for j in range(i):
            print(current_number, end=" ")
            current_number += 1

        # Move to the next line for the next row
        print()

# Example usage:
last_number = 300
print_pyramid(last_number)