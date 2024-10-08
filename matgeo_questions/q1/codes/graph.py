import sys                                          #for path to external scripts
sys.path.insert(0, './CoordGeo')        #path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#Enter the points here for manual entring
A = np.array(([1,3])).reshape(-1,1) 
B = np.array(([-1,2])).reshape(-1,1) 
C = np.array(([2,5])).reshape(-1,1) 
D = np.array(([4,6])).reshape(-1,1) 

#Direction Matrices
M1= np.block([[B-A,C-D]])
M2= np.block([[C-B,D-A]])
M3= np.block([[B-A,C-B]])
M4= np.block([[C-B,D-C]])

R1 = np.linalg.matrix_rank(M1)
R2 = np.linalg.matrix_rank(M2)
R3 = np.linalg.matrix_rank(M3)
R4 = np.linalg.matrix_rank(M4)

#orthogonality of sides
orth1 = (B-A).T@(C-B)
orth2 = (C-A).T@(D-B)

#Type of Quadilateral
if R1 == 1 and R2 == 1:
    if orth1 == 0:
        if orth2 == 0:
            print("Square")
        else:
            print("Rectangle")
    elif orth1 != 0 and orth2 == 0:
        print("Rhombus")
    else:
        print("parallelogram")
elif R1==0 or R2==0:
    print("Trapezium")
elif R3==1 or R2 == 1:
    print("Quadilateral cannot be formed")
else:      
    print("irregular quadilateral")      
 

#line generation
x_AB = line_gen(A,B)
x_BC = line_gen(B,C)
x_CD = line_gen(C,D)
x_DA = line_gen(D,A)

k1 = -4
k2 = 6
n = np.array(([0, 1])).reshape(-1,1) 
c = 4
x_ref = line_norm(n,c,k1,k2)

#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:],label='$AB$')
plt.plot(x_BC[0,:],x_BC[1,:],label='$BC$')
plt.plot(x_CD[0,:],x_CD[1,:],label='$CD$')
plt.plot(x_DA[0,:],x_DA[1,:],label='$DA$')
plt.plot(x_ref[0,:],x_ref[1,:], label="$(0 \quad 1)\mathbf{x} = 4$")

#Labeling the coordinates
tri_coords = np.block([[A,B,C,D]])
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','B','C','D']
for i, txt in enumerate(vert_labels):
    #plt.annotate(txt, # this is the text
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.0f}, {tri_coords[1,i]:.0f})',
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(20,0), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

# use set_position
ax = plt.gca()
ax.spines['left'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['bottom'].set_visible(False)
'''
ax.spines['top'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')
'''
#plt.xlabel('$x$')
#plt.ylabel('$y$')
#plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.savefig('../figs/graph.png')
plt.show()
