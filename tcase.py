import json
x=input()
z=json.loads(x)
# for i in z:
#     print(i)
for i in z:
    for j in i:
        print(j,end="")
        print(" ",end="")
    print("\n",end="")