def merge_sort(li):
    if len(li)<2:
        return li
    
    m=len(li)/2
    r=li[:m]
    l=li[m:]
    return merge(merge_sort(r), merge_sort(l))  

def merge(l, r):
    i=0
    j=0
    retList=[]
    while i<len(l) and j<len(r):
        if(l[i]<r[j]):
            retList.append(l[i])
            i+=1
        else:
            retList.append(r[j])
            j+=1
    retList+=l[i:]
    retList+=r[j:]
    return retList


def main():
    li=[1,2,5,3,8,4,7]
    #print merge_sort(li);
    print merge_sort(li) 

if __name__=="__main__":
    main()