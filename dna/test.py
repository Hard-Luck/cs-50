import csv

reader = csv.reader("dna/databases/small.csv")
titles = [reader(next)]
print(titles)