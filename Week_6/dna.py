from sys import argv, exit
import re
import csv
# check if correct number of command-line arguements
if len(argv) != 3:
    print("missing command-line argument")
    exit(1)

# open CSV and read conents to memory
with open(argv[1], 'r') as file:
    database = csv.reader(file)
    for lineNum, line in enumerate(database):
        
        # when first row get the STR headers and compute
        if lineNum == 0:
            ','.join(line)
            
            # make array which will contain max STR values
            count = [0] * len(line)
            
            # open txt and read to memory
            with open(argv[2], "r") as sequence:
                data = sequence.read()
                    
                # compute max consecutive STR for each STR
                for a in range(1, len(line)):
                    groups = re.findall('((?:' + re.escape(line[a]) + ')*)', data)
                    count[a] = len(max(groups, key=len))//len(line[a])
        else:
            ','.join(line)
            
            # make array which will contain CSV STR values
            value = [0] * len(line)
            
            # for every column in CSV record the STR value
            for a in range(1, len(line)):
                value[a] = int(line[a])
            
            # check if value equal to count and print match 
            if value == count:
                print(f"{line[0]}")
                exit()
# if no match found already then there is no match
print(f"no match")