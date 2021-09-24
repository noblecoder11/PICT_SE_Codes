def average_dict(gradebook):
    average={}
    for i in dict.keys(gradebook):
        name= i
        H=sum(gradebook[i][0])/3
        Q=sum(gradebook[i][1])/3
        average[name]=[H, Q]
    return average

def average_dict_weighted(gradebook, listh, listq):
    w_average={}
    for i in dict.keys(gradebook):
        name=i
        H=0
        Q=0
        H=listh[0]*gradebook[i][0][0]+listh[1]*gradebook[i][0][1]+listh[2]*gradebook[i][0][2]
        Q=listq[0]*gradebook[i][1][0]+listq[1]*gradebook[i][1][1]+listq[2]*gradebook[i][1][2]
        w_average[name]=[H, Q]
    return w_average

def average_marks(gradebook,a,b):
    average_m={}
    for i in dict.keys(gradebook):
        name= i
        am=a*sum(gradebook[i][0])/3 + b*sum(gradebook[i][1])/3
        average_m[name]= am
    return average_m

def get_letter_grade(gradebook):
    average_m=average_marks(gradebook, 0.4, 0.6)
    grade_list={}
    for i in dict.keys(average_m):
        name= i
        grade=""
        if(average_m[i]>=90):
            grade+="A"
        elif 80<=average_m[i]<90 :
            grade+="B"
        elif 70<=average_m[i]<80 :
            grade+="C"
        elif 60<=average_m[i]<70 :
            grade+="D"
        else:
            grade+="F"
        grade_list[name]=grade
    return grade_list

def get_class_average(gradebook):
    avg=0
    for i in dict.keys(gradebook):
        avg+=(sum(gradebook[i][0])+sum(gradebook[i][1]))/6
    return avg/len(gradebook)

def get_class_average_grade(gradebook):
    average=get_class_average(gradebook)
    grade=""
    if(average>=90):
        grade+="A"
    elif 80<=average<90 :
        grade+="B"
    elif 70<=average<80 :
        grade+="C"
    elif 60<=average<70 :
        grade+="D"
    else:
        grade+="F"
        
    return grade



gradebook = {'Shreya':[[82,75,68],[33,15,74]],'Varun':[[82,25,67],[91,66,82]],
'Tapan':[[57,62,78],[0,0,0]] }

print(average_dict(gradebook))
print(average_dict_weighted(gradebook,[0.2,0.7,0.1],[0,0.5,0.5]))
print(average_marks(gradebook,0.4,0.6))
print(get_letter_grade(gradebook))
print(get_class_average(gradebook))
print(get_class_average_grade(gradebook))