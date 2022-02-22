import csv

reader = csv.reader(open("databases/small.csv"))
print(reader.next())