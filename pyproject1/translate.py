from scanner import *
from support import *
import sys


def main():
    if len(sys.argv) != 3:
        print("need two argvs")
        sys.exit(0)
    dicount = countDic(sys.argv[1])
    dic = readArray(sys.argv[1], dicount)
    msgcount = countTokens(sys.argv[2])
    msg = readMsg(sys.argv[2], msgcount)
    print("", msg[msgcount - 1])
    print("", dic[0])
    for i in range(0, msgcount):
        translateable = translate(msg[i], dic, dicount)
        if translateable == 0:
            print(msg[i], "", end="")
        else:
            print(translateable, "", end="")
    print("\n")


main()
