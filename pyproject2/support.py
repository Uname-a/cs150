
def displayMenu():

    print("Welcome to the Movie Database!")
    print("Main menu: ")
    print("    1:  display all movies")
    print("    2:  display shortest movie")
    print("    3:  display longest movie")
    print("    4:  display older movies")
    print("    5:  display newer movies")
    print("    6:  display movies by rating")
    print("    7:  add movie (CHALLENGE)")
    print("    8:  delete movie (CHALLEGE)")
    print("    9:  save database (CHALLENGE)")
    print("    0:  quit the program")
    print("Enter an Option: ")


def query(db, count):

    displayMenu()

    option =
    while (option != 0):

        if (option == 1):

            printMovies(db, count)
            print("Enter an option: ")

        elif (option == 2):

            result = shortestMovie(db, count)
            print(db[result].MOVIE_NAME, db[result].DESCRIPTION, db[result].YEAR, db[result].LENGTH, db[result].RATING, dresult].CAST, db[result].DIRECTOR)
            print("Enter an option: ")

        elif (option == 3):

            result = longestMovie(db, count)
            print(db[result].MOVIE_NAME, db[result].DESCRIPTION, db[result].YEAR, db[result].LENGTH, db[result].RATING, db[result].CAST, db[result].DIRECTOR)
            print("Enter an option: ")

        elif (option == 4):

            print("Display movies older than what year? ")
            before = readInt(stdin)
            moviesBefore(db, count, before)
            print("Enter an option: ")

        elif (option == 5):

            print("Display movies newer than what year? ")
            before = readInt(stdin)
            moviesAfter(db, count, before)
            print("Enter an option: ")

        elif (option == 6):

            print("Display movies with what rating? ")
            rating = readToken(stdin)
            moviesRating(db, count, rating)
            print("Enter an option: ")

        elif (option == 7):

            print("Option 7 has not been implemented\n")
            print("Enter an option: ")

        elif (option == 8):

            print("Option 8 has not been implemented\n")
            print("Enter an option: ")

        elif (option == 9):

            print("Option 9 has not been implemented\n")
            print("Enter an option: ")

        else:
            print(" Option Not Understood ")
            displayMenu()

        option = readOption(stdin)
