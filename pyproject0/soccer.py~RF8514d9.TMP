
 # Was a program for baseball or softball on-base percentage, by John C. Lusth, 2014
 # 
 # this program may be freely distributed and modified, as long as:
 # 
 # a) the authorship of any modifications is added
 #
  #b) the reason for modification is added
 
 # c) the comments are updated to reflect modifications
 
 # d) the original authorship and that of any previous modifiers is preserved.
 
 


#modifications by matt baird 
#modified converting this program to calculate soccer offensive production rating


# function prototypes




def main():
    
    goals,shots,corner,assists,passes,touches = getData()#converted old varable names to match soccer terms 
    #get the statistics from the user

    #converted old varable names to match soccer terms

    #compute the rating
    rating = computeRating(goals,shots,corner,assists,passes,touches) #converted old varable names to match soccer terms

    #display the statistics
    displayData(goals,shots,corner,assists,passes,touches) #converted old varable names to match soccer terms

    #display the results
    print("For these statistics, the offensive production rating is",rating) #changed the words to match soccer terms and added a limiter for the amount of decimal places to 3

    return 0
    

#changed the varable names to go with soccer terms and also the prompts
def getData():
    info = input("Enter number of goals: ")
    goals = int(info)
    info = input("Enter number of shots: ")
    shots = int(info) 
    info = input("Enter number of corner kicks: ")
    corner = int(info)
    info = input("Enter number of assists: ")
    assists= int(info)
    info = input("Enter number of passes: ")
    passes = int(info)
    info = input("Enter numer of touches: ")
    touches = int(info)
    return goals,shots,corner,assists,passes,touches
    

#changed the math equation to the one for soccer and added/  changed the varable names
def computeRating(goals,shots,corner,assists,passes,touches):
    
    return ((5 *goals) + (4 *shots) + (3 * corner) + (2 *assists) + passes) / (touches)
    

#changed varable names and added one more varable for the conversion
def displayData(goals,shots,corner,assists,passes,touches):
    print("")
    print("goals: ",goals)
    print("shots: ",shots)
    print("corner kicks: ",corner)
    print("assists: ",assists)
    print("passes: ",passes)
    print("touches: ", touches)
    return None
main()