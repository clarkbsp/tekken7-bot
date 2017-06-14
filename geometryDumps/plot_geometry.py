import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

points = open("claudio_1lk.txt",'r').readline().split(' ')
points = [float(x) for x in points]
points = np.asarray(points).reshape(46,4)
#print(points[:,0])
'''xyzPoints = [p for p in points if p[3]==1]
zeroPoints = [p for p in points if p[3]==0]
print(xyzPoints)
print(zeroPoints[0])'''

'''for i,p in enumerate(points):
    if p[3] == 0:
        #print(p)
        points[i] = 0
for i,p in enumerate(points):
    if sum(p) == 0:
        points = np.delete(points,p,0)'''

points = points[::2]
#points = points[::4]
fig = plt.figure()
ax = fig.add_subplot(111)#, projection='3d')
#ax = fig.add_subplot(111)
xs = -1*points[:,0]
ys = points[:,1]
zs = -1*points[:,2]
#ax.scatter(xs, zs, ys)
#ax.plot_wireframe(xs,ys,zs)
ax.scatter(xs, zs)
ax.set_xlabel('X Label')
ax.set_ylabel('Z Label')
#ax.set_zlabel('Y Label')
print(len(points))
plt.show()