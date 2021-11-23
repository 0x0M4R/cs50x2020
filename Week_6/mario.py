from cs50 import get_int


def main():
    h = get_positive_int()
    count = 1

    # create number of rows based off inputted number
    for _ in range(h):
        
        # print spaces and add to counter
        print(" " * (h-count), "#" * count, sep="")
        count += 1

# prompt user for input and check if valid


def get_positive_int():
    while True:
        height = get_int("Height:")
        if height > 0 and height < 9:
            break
    return height


main()