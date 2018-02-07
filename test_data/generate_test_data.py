import numpy as np
import matplotlib.pyplot as plt
from matplotlib import colors, ticker, cm

size = 1000

x = np.arange(0.0, np.pi, np.pi/size)
y = np.arange(0.0, np.pi, np.pi/size)
X, Y = np.meshgrid(x, y)
result=np.zeros((size,size))

result_out = np.zeros(size*size);
x_out = np.zeros(size*size);
y_out = np.zeros(size*size);

count =0;
for i in range(np.size(x)):
    for j in range(np.size(y)):
        result[i][j] = np.sin(x[i])*np.sin(y[j])
        x_out[count] = x[j]
        y_out[count] = y[i]
        result_out[count] = result[i][j]
        count=count+1
        

#x=np.transpose(x)
#ny=np.transpose(y)
#result=np.transpose(result)

np.savetxt("test.dat", np.transpose([x_out, y_out, result_out]), delimiter=' ')
fig, ax = plt.subplots()
cs = ax.contourf(X, Y, result, cmap=cm.gist_rainbow)
cbar = fig.colorbar(cs)

plt.show()

