import numpy as np
from scipy.integrate import odeint
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# parameters
alpha = 15.395
beta = 28
R = -1.143
C_2 = -0.714

def chua(u, t):
    x, y, z = u  
    # electrical response of the nonlinear resistor
    f_x = C_2*x + 0.5*(R-C_2)*(abs(x+1)-abs(x-1))
    dudt = [alpha*(y-x-f_x), x - y + z, -beta * y]
    return dudt

# time discretization
t_0 = 0
dt = 1e-3
t_final = 10
t = np.arange(t_0, t_final, dt)

# initial conditions
u0 = [0.1,0,0]
# integrate ode system
sol = odeint(chua, u0, t)

# 3d-plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')

ax.plot(sol[:,0],sol[:,1],sol[:,2])

plt.savefig("chua2.png")


x_values = sol[:, 0]

# Convert x values to random bits (0 or 1)
random_bits = [int(value >= np.mean(x_values)) for value in x_values]
np.random.shuffle(random_bits)

# Random Number Output: Save to a .dat File
output_file_path = "random_numbers.dat"

with open(output_file_path, "w") as file:
    i = 0
    for bit in random_bits:
        if (i < 8):
            file.write(str(bit))
            i+=1
        else: 
            i = 0
            file.write("\n")

print("Random numbers have been saved to:", output_file_path)


'''
# Simulated values of x, y, and z from Chua's ODEs
# Replace these with your actual simulation results
# Extract x, y, and z from the solution
x_values = sol[:, 0]
y_values = sol[:, 1]
z_values = sol[:, 2]

# Save the values in separate NumPy arrays
x_np_array = np.array(x_values)
y_np_array = np.array(y_values)
z_np_array = np.array(z_values)

# Data Preprocessing: Normalize values to the range [0, 1]
x_normalized = (x_np_array - np.min(x_np_array)) / (np.max(x_np_array) - np.min(x_np_array))
y_normalized = (y_np_array - np.min(y_np_array)) / (np.max(y_np_array) - np.min(y_np_array))
z_normalized = (z_np_array - np.min(z_np_array)) / (np.max(z_np_array) - np.min(z_np_array))

# Combine Data: Concatenate the normalized values
combined_data = np.concatenate([x_normalized, y_normalized, z_normalized])

# Randomness Extraction from Chaotic Data (Symbolic Dynamics)
threshold_low = 0.4  # Lower threshold for discretization
threshold_high = 0.6  # Upper threshold for discretization

symbolic_sequence = []

for value in combined_data:
    if value < threshold_low:
        symbolic_sequence.append(0)
    elif value >= threshold_high:
        symbolic_sequence.append(2)
    else:
        symbolic_sequence.append(1)

# Convert symbolic sequence into random-like bits
random_bits = []
for i in range(len(symbolic_sequence) - 1):
    if symbolic_sequence[i] != symbolic_sequence[i + 1]:
        random_bits.append(1)
    else:
        random_bits.append(0)

# Random Number Output: Save to a .dat File
output_file_path = "random_numbers.dat"

with open(output_file_path, "w") as file:
    for bit in random_bits:
        file.write(str(bit) + "\n")

print("Random numbers have been saved to:", output_file_path)
'''
