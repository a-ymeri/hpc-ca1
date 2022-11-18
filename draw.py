import matplotlib.pyplot as plt
import numpy as np


x = [0,1/4,1/2, 1, 2, 4]
#let y be 13 times x
y = [100*i for i in x]
#plot x and y in log scale
plt.loglog(x,y, basex=2, basey=2)
plt.grid(True)
#hard define the x and y axis
plt.axis([1/4,4, 1/4, 4])

#show the ticks as decimal
plt.xticks(x, [str(i) for i in x])
plt.yticks(y, [str(i) for i in y])


plt.show()
