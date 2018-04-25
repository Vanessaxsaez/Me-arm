import math
import numpy as np

PI = math.pi

x = np.array([1,5,2])
y = np.array([7,4,1])

suma = x + y

A = np.matrix( 
	( 	
		(2,3),
		(3,5) 
		) 
	)
B = np.matrix( ( (1,2),(5,-1) ) )

#############

def matrizAi(teta, d, a, alfa):

	#math.radians(Grados) = radianes

	A = np.matrix(
		(
			( math.cos(teta), -math.cos(alfa)*math.sin(teta), math.sin(alfa)*math.sin(teta)	, a*math.cos(teta) ),
			( math.sin(teta), math.cos(alfa)*math.cos(teta)	, -math.sin(alfa)*math.cos(teta), a*math.sin(teta) ),
			( 0				, math.sin(alfa)				, math.cos(alfa)				, d ),
			( 0				, 0								, 0								, 1 )
			)

		)
	return A

A1 = matrizAi(math.radians(0), 10, 0, math.radians(90))
A2 = matrizAi(math.radians(0), 0, 10, math.radians(0))
A3 = matrizAi(math.radians(0), 0, 10, math.radians(0))

T = A1*A2*A3

X = T[0,3]
Y = T[1,3]
Z = T[2,3]

