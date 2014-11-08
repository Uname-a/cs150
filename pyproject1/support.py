from scanner import *


def countDic(fileName):
    s = Scanner(fileName)
    count = 0
    token = s.readtoken()
    line = s.readstring()
    while (token != "") and(line != ""):
        count += 1
        token = s.readtoken()
        line = s.readstring()
    s.close()
    return count


def countTokens(fileName):
    s = Scanner(fileName)
    count = 0
    token = s.readtoken()
    while (token != ""):
        count += 1
        token = s.readtoken()
    s.close()
    return count


def readArray(fileName, count):
    s = Scanner(fileName)
    array = [0] * count * 2
    count = count * 2
    i = 0
    token = s.readtoken()
    line = s.readstring()
    while (i < count):
        array[i] = token
        i += 1
        array[i] = line
        i += 1
        token = s.readtoken()
        line = s.readstring()
    s.close()
    return array


def readMsg(fileName, count):
    s = Scanner(fileName)
    array = [0] * count
    i = 0
    token = s.readtoken()
    while (i < count):
        array[i] = token
        i += 1
        token = s.readtoken()
    s.close()
    return array


def translate(msg, dic, count):
    for j in range(0, count):
        if msg == dic[j]:
            word = dic[j + 1]
            result = ""
            for i in range(0, len(word), 1):  # remove the "" from the strings
                if (word[i] == '\"'):            # it matches!
                    result = result + ''  # so add in the replacement
                else:                            # it doesn't match
                    result = result + word[i]
            return result
        else:
            word = 0

    return 0
