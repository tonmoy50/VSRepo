#x = int (input ("Enter X: ") )
#y = int (input ("Enter Y: ") )
#z = int (input ("Enter Z: ") )
#N = int (input ("Enter N: ") )

#lst = [ [i, j, k] for i in range(x+1) for j in range(y+1) for k in range(z+1) if (i + j + k)!= N ]
#print(lst)

lst1 = [i**2 for i in range(10) if i**2 > 20]
print(*lst1)

matrix = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12]
    ]
length = len(matrix[1])
transposed = [ [row[i] for row in matrix] for i in range(4) ]

#print(transposed)

s = {"tonmoy", "tonmoy", "tnmoy"}
#print (s)
s.remove("tnmoy")
#print (s)
s2 = {}
my_dict = {1 : 'Tonmoy', 2: 'Halder'}
#print(type(s2))
#print(type(my_dict))

#s2 = my_dict
#print(s2)

#print (dir(s))

#for i in my_dict.values():
#    print (i)

#new_dict = {k + k:v + v for k,v in my_dict.items()}
#print (new_dict)
string = "Chotto Bondhu"
#print(dir(string))

str1 = "Boob"
str1.upper()
str2 = str1

#print(str1 is str2)

sentence = "A python program to sort words in a sentence"
sorted_word = sentence.split()
sorted_word.sort()
new_word = ""
for i in sorted_word:
    new_word += i + ' '

#print (new_word)

a = 10
b = 20
print (a if a > b else b)
print ([ i for i in range(10) ])

docu = open("test.txt", "w")
docu.write("This is a dummy line\n")
docu.close
fucku = open("test.txt", "r")

for line in fucku:
    print(line)