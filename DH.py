import math
import numpy as np

def matrizAi(teta, d, a, alfa):
	A = np.matrix(
		(
			( math.cos(teta), -math.cos(alfa)*math.sin(teta), math.sin(alfa)*math.sin(teta)	, a*math.cos(teta) ),
			( math.sin(teta), math.cos(alfa)*math.cos(teta)	, -math.sin(alfa)*math.cos(teta), a*math.sin(teta) ),
			( 0				, math.sin(alfa)				, math.cos(alfa)				, d ),
			( 0				, 0								, 0								, 1 )
			)
		)
	return A

def calcularT(a, b, c):
	return a*b*c

def obtenerX(t):
	return t[0,3]

def obtenerY(t):
	return t[1,3]

def obtenerZ(t):
	return t[2,3]

#math.radians(Grados) = radianes

# Parametros obtenidos del DH

#	i 		tetai		di		ai 		alfai		
#
#	1		q1			L1		0		90
#
#	2		q2			0		L2		0
#
#	3		Q3			0		L3		0


# L1 = 6 cm
# L2 = 8 cm
# L3 = 12,5c m

A1 = matrizAi(math.radians(0), 6, 0, math.radians(90))
A2 = matrizAi(math.radians(0), 0, 8, math.radians(0))
A3 = matrizAi(math.radians(0), 0, 12.5, math.radians(0))

T = calcularT(A1,A2,A3)

X = obtenerX(T)
Y = obtenerY(T)
Z = obtenerZ(T)