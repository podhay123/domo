array1 = []
for _ in range(6):
    inp = input()
    array1.append(inp)
order = ["u" ,"l", "(",",",")"]

counter = 0
enabled = True
for i in array1:
    for j in range(len(i)):
        if i[j] == "m" and enabled == True:
            string_index = 1
            order_index = 0
            num1 = 0
            num2 = 0
            s1 = ""
            s2 = ""
            which_num = 1
            while True:
                if order_index < 3:
                    if i[j + string_index] == order[order_index]:
                        string_index +=1
                        order_index +=1
                    else:
                        break
                if order_index >= 3:

                    if 48<=ord(i[j + string_index]) and ord(i[j + string_index]) <=57:
                        tmp = ''
                        tmp += i[j + string_index]
                        string_index += 1
                        if which_num == 1:
                            s1 += tmp
                        elif which_num == 2:
                            s2 += tmp
                        else:
                            break
                    elif i[j + string_index] == ",":
                        string_index +=1
                        order_index +=1
                        which_num += 1
                    elif i[j + string_index] == ")":
                        if s1!= "":
                            if s2!="":
                                counter +=int(s1)*int(s2)
                        break
                    else:
                        break
        if i[j] == 'd':
            if i[j+1] == "o":
                if i[j+2] == "(":
                    if i[j+3] == ")":
                        enabled = True
                elif i[j+2] == "n":
                    if i[j+3] == "'":
                        if i[j+4] == "t":
                            if i[j+5] == "(":
                                if i[j+6] == ")":
                                    enabled = False
                
                
                            
print(counter)