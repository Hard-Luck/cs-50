import csv

reader = csv.reader(open("databases/small.csv"))
titles = (next(reader))
print(titles)
print(next(reader))