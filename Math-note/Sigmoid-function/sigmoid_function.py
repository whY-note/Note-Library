import numpy as np
import matplotlib.pyplot as plt

def sigmoid_func(x):
    return 1.0/(1+np.exp(-x))

def der_sigmoid_func(x):
    return sigmoid_func(x)*sigmoid_func(-x)

x = np.linspace(-10,10,1000)
y = sigmoid_func(x)

dy = der_sigmoid_func(x)

plt.plot(x, y, color="blue",label="$\sigma(x)$")
plt.plot(x, dy, color="red",label="$\sigma^\prime(x)$")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid()

plt.savefig("./Sigmoid_function.assets/Sigmoid_function.png", dpi = 300)
