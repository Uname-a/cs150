from scanner import *
from support import *
import sys


def main():
    if len(sys.argv) != 3:
        print("need two argvs")
        sys.exit(0)
    arrayone = readMovieRecordsList(sys.argv[1], countone)
    arraytwo = readMovieRecordsList(sys.argv[2], counttwo)
    finalarray = mergeAllArrays(arrayone, countone, arraytwo, counttwo)
    query(finalarray, countone + counttwo)

main()
