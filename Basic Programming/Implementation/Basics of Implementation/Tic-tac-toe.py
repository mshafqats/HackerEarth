'''
=====================
|  ID: mshafqats    |
|  LANG: Python     |
=====================
Mohammad Shafqat Siddiqui
'''

x=input()
y=input()
z=input()
c=flag=0
m='0'
O=x.count('O')+y.count('O')+z.count('O')
ex=x.count('X')+y.count('X')+z.count('X')
 
if O>ex or O+1<ex:
   print('Wait, what?')
else:
   if(x[0]==y[0]==z[0] or x[0]==x[1]==x[2]) and (x[0]=='X' or x[0]=='O'):
       m=x[0]
       c+=1
   if(x[0]==y[1]==z[2] or x[2]==y[1]==z[0] or x[1]==y[1]==z[1] or y[0]==y[1]==y[2]) and (y[1]=='X'or y[1]=='O'):
       if(m=='0') or (m==y[1]=='X'):
          m=y[1]
       elif(m!=y[1])and(m!='0'):
           flag=1
       c+=1
   if(x[2]==y[2]==z[2] or z[0]==z[1]==z[2]) and (z[2]=='X' or z[2]=='O'):
       if(c==2) or (m!=z[2])and(m!='0'):
           flag=1
       elif(m==z[2]=='X')and(c==1)or(c==0):
           m=z[2]
       c+=1
   if(((c==3)or(flag==1)) or ((O==ex)and(m=='X')) or ((ex>O)and(m=='O'))):
       print('Wait, what?')
   elif(m=='0'):
    if(O+ex<9):
       print("X's turn.") if(O==ex) else print("O's turn.")
    else:
       print("It's a draw.")
   else:
       print(m , 'won.')
