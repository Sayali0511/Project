def LenBuild(arr, n, p): 

	result = [] 
	X =[]
# distance of each point from sun 
	for i in range(len(arr)): 
		
		dist= pow((p[0] - arr[i][0]), 2)+ pow((p[1] - arr[i][1]), 2) 
		
		result.append([dist,[arr[i][0],arr[i][1]]]) 
		
	# Sorting the result array with respect to its distance 
	result.sort()
		
	for i in range(0,len(result)-1):
	    for j in range(1,2):
	        X.append( abs((arr[i][0]-arr[j][0]) + (arr[i][1] - arr[j][1])))
	
	# Output
	length = 0.0
	for i in range(len(X)):
	    length = length + X[i]
	print(length)
	

# Driver code 
arr = [[4, 0],[4, -5],[7, -5],[7,0]] 
n = 1  					#no of buildings
p = [1, 1] 

# Length of building 
LenBuild(arr, n, p) 

