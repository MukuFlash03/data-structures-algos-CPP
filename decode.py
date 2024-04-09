def getLastNumbers(lastNumber):
    # Last number n = i * (i + 1) / 2
    # Hence, i = (-1 + (1 + 8 * n)**0.5) / 2 by solving quadratic equation
    numRows = int((-1 + (1 + 8 * lastNumber)**0.5) / 2)
    rowLastNumbers = []
    rowStartNumber = 1

    for i in range(1, numRows + 1):
        rowLastNumbers.append(rowStartNumber + i - 1)
        rowStartNumber += i

    return rowLastNumbers

def decode(encodedMessage):
    with open(encodedMessage, "r") as f:
        lines = f.readlines()

    # Storing the words in a dictionary
    wordMap = {}
    for line in lines:
        number, word = line.strip().split()
        wordMap[int(number)] = word

    # Sorting the keys to form pyramid and fetch last numbers of each row
    numbers = sorted(wordMap.keys())
    lastNumbers = getLastNumbers(numbers[-1])

    message = []
    for index in lastNumbers:
        message.append(wordMap[index])

    return " ".join(message)

print(decode("message.txt"))