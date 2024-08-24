import sys                                          #for path to external scripts
sys.path.insert(0, './CoordGeo')        #path to my scripts
import numpy as np
import mpmath as mp
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#Given Points
A = np.array(([1, 2])).reshape(-1,1) 
B = np.array(([7, 0])).reshape(-1,1) 

#Line parameters
n = np.array(([3, 1])).reshape(-1,1) 
c = 8

#Generating Lines
k1 = -3
k2 = 3
x_C = line_norm(n,c,k1,k2)

#Plotting all lines
plt.plot(x_C[0,:],x_C[1,:],label='$(3 ~ 1)\mathbf{x}=8$')

#Labeling the coordinates
tri_coords = np.block([A, B])
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A', 'B']
for i, txt in enumerate(vert_labels):
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.0f}, {tri_coords[1,i]:.0f})',
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(-10,-5), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

# use set_position
ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')
'''
ax.spines['left'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['bottom'].set_visible(False)
plt.xlabel('$x$')
plt.ylabel('$y$')
'''
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.savefig('../figs/graph.png')
plt.show()