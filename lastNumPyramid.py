def get_last_numbers(last_number):
    # Calculate the number of rows
    num_rows = int((-1 + (1 + 8 * last_number)**0.5) / 2)

    # Initialize a list to store the last number on each row
    last_numbers = []

    # Loop to find the last number on each row
    current_number = 1
    for i in range(1, num_rows + 1):
        # Store the last number for the current row
        last_numbers.append(current_number + i - 1)

        # Update the current number for the next row
        current_number += i

    return last_numbers

# Example usage:
last_number = 300
result = get_last_numbers(last_number)
print(result)
