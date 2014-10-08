#!/usr/bin/env python

import os
import random
from random import randint
import string
from random import randrange

#Name: Mandelynn Atkins
#Date: December 2, 2013
#Assignment: Individual Assignment 4

#Deletes file if it already exists
#so you don't have to manually delete it
#every time script is run
try:
   os.remove('comma_delimited_file.txt')
except OSError:
   pass

#Gets number of accounts from user
input_var = int(raw_input('Number of accounts: '))

#For loop that will generate information
#for the number of accounts entered by
#the user
for s in range(input_var):
   #Picks last name from last.txt
   lname = random.choice(open('last.txt').readlines()).strip()
   
   #Picks first name from first.txt
   fname = random.choice(open('first.txt').readlines()).strip()
   
   #Concatenates fname and lname to
   #create just one variable for name
   name = fname+" "+lname
   
   #Creates username from first letter 
   #of first name and full last name,
   #plus random number
   uname = fname[0][0] + lname + str(randint(2,9))
   
   #Initial password
   ipassword = ''.join(random.sample(string.letters*5,5))
   
   #Have to create empty string for 
   #phone number
   telnum = ''
   
   #Generates 10 numbers, adding each
   #one to the telnum string
   for x in range(0, 10):
      num = randrange(10)
      telnum = telnum + (str(num))
      x+=1
   
   #Picks random address from address.txt
   address = random.choice(open('address.txt').readlines()).strip()
   
   #Writes all information to file, with 
   #each variable separated by a comma
   #to create comma delimited file
   f = open('comma_delimited_file.txt','a')
   f.write(name+","+uname+","+ipassword+","+telnum+","+address.strip()+os.linesep)
   f.close()
   
   s+=1