import random
rock = '''
rock
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
paper
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
scissors
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''
list1=[rock,paper,scissors]
choice1=int(input("choose 0 for rock, 1 for paper, 2 for scissor.\n"))
choice2=random.randint(0,2)
print(f'your choice is {list1[choice1]}\n')
print(f'computer choice is {list1[choice2]}\n')
if choice1==choice2:
  print("Tie")
elif choice1==0 and choice2==2:
  print("You won!!!")
elif choice1==1 and choice2==0:
  print("You won!!!") 
elif choice1==2 and choice2==1:
  print("You won!!!")
else:
  print("Computer won!!")

