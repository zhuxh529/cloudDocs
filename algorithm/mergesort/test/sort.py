def sortt(listt):
	if len(listt)<2:
		return listt
	m=len(listt)/2
	l=listt[:m]
	r=listt[m:]
	return merge(sortt(l), sortt(r))

def merge(l,r):
	retlist=[]
	i=0
	j=0
	while i<len(r) and j<len(l):
		if r[i]<l[j]:
			retlist.append(r[i])
			i+=1
		else:
			retlist.append(l[j])
			j+=1
	retlist+=r[i:]
	retlist+=l[j:]
	return retlist




def main():
	li=[9,8,5,3,1,4,7]
	print sortt(li)

if __name__=="__main__":
	main()