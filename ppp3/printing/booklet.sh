pdftk $1 cat 12 13 14 11 10 15 16 9 8 17 18 7 6 19 20 5 4 21 22 3 2 23 24 1 output $2
mv $1 old.pdf
pdftk old.pdf cat 25-end output $1
trash old.pdf
