import numpy as np
import matplotlib.pyplot as plt

# Tham số
a = 0.5  # Giá trị a (|a| < 1)
omega = np.linspace(-np.pi, np.pi, 5000)  # Tần số từ -pi đến pi

# Tính phổ biên độ
magnitude = 1 / np.sqrt(1 - 2 * a * np.cos(omega) + a**2)

# Vẽ phổ biên độ
plt.figure(figsize=(8, 4))
plt.plot(omega, magnitude, label=f'a = {a}')
plt.title("Phổ biên độ |X(e^jω)|")
plt.xlabel("Tần số ω (rad/sample)")
plt.ylabel("|X(e^jω)|")
plt.grid(True)
plt.legend()
plt.show()

