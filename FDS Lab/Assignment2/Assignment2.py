class String:
    def __init__(self, str):
        self.str=str.replace(",","")
        self.str=self.str.replace(".", "")
        self.str=self.str.lower()
        self.lis=list(self.str.split())
    
    def longest_word(self):
        temp=[]
        for i in self.lis:
            temp.append([len(i), i])
        temp.sort(reverse=True)
        return f"'{temp[0][1]}' is the longest word."

    def char_freq(self, character):
        count=0
        for i in range(len(self.str)):      
            if character == self.str[i]:
                count+=1
        return (f"Character '{character}' appears {count} times in the string.")

    def is_palindrome(self):                
        n=len(self.str)
        str2=self.str[::-1] 
        if self.str==str2:
            return ("The string is a Palindrome.")
        else:
            return ("Ther string is NOT a Palindrome.")
        

    def first_appearance(self, substring):
        n=len(substring)
        first_appear=-1
        for i in range(len(self.str)-n-1):
            if self.str[i:i+n]==substring:
                first_appear=i
                break
        
        if first_appear==-1:
            return ("No occurence of substring in given string.")
        else:
            return (f"First appearance of {substring} is at index {first_appear}")

    def count_occurrences_each(self):
        checked=[]
        dictionary={}
        for i in self.lis:
            if i in checked:
                a=dictionary[i]
                a+=1
                dictionary[i]=a
            else:
                dictionary[i]=1
                checked.append(i)

        print("Words in string and their frequencies are: ")
        return (dictionary)

    def count_occurrence(self, word):
        count=0
        for i in self.lis:
            if i == word:
                count=count+1
        return (f"'{word}' occurs {count} times in string.")



print("MAIN MENU")
print("This program lets you to: \n 1. Find word with longest length in string. \n 2. Determine the frequency of given character in given string. \n 3. Check whether the string is palindrome or not. \n 4. Know the index of first appearace of given substring. \n 5. Count occurrences of each word in the string. \n 6. To count occurrences of given word in string.")
print("HAVE FUN WITH STRINGS!")
print("--------------------------------")

print("Enter the string: ")
s1=String(input())
print()
while True:
    choice=int(input("Enter a choice: "))

    if choice==1:
        print(s1.longest_word())
    elif choice==2:
        char=input("Enter a character:")
        print(s1.char_freq(char))
    elif choice==3:
        print(s1.is_palindrome())
    elif choice==4:
        substring=input("Enter a substring: ")
        print(s1.first_appearance(substring))
    elif choice==5:
        print(s1.count_occurrences_each())
    elif choice==6:
        word=input("Enter a word: ")
        print(s1.count_occurrence(word))
    else:
        print("Enter a valid choice(1 to 6).")

    print()
    cont= input("Do you want to continue(y/n): ")
    if cont=='y':
        continue
    else:
        print("Thank you for playing.")
        break