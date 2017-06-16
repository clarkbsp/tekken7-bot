from itertools import combinations as c

directions = '123456789'
buttons = '1234'
outStrings = []
actionString = ''
#print(list(c(directions,2)))
directionsMap = {
    '1' : 'db',
    '2' : 'd',
    '3' : 'df',
    '4' : 'b',
    '5' : '',
    '6' : 'f',
    '7' : 'ub',
    '8' : 'u',
    '9' : 'uf'          
    }
for d in directions:
    actionString = directionsMap[d]
    outStrings.append(actionString)
    for i in range(1,3):         
        subsets = c(buttons,i)
        for s in subsets:
            actionString = directionsMap[d]
            s = ''.join(list(s))
            actionString += s
            outStrings.append(actionString)

        #for j uttons in range(2):

for each in outStrings:
    print("\"" + each + "\"" + ',')
# add 0 cases separately