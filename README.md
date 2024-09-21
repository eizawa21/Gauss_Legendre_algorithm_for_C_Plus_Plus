# Gauss_Legendre_algorithm_for_C-
Iterative mathematical algorithm used to calculate pi

$$
a_{n+1} = \frac{a_n + b_n}{2}
$$

$$
b_{n+1} = \sqrt{a_n b_n}
$$

$$
t_{n+1} = t_n - p_n (a_n - a_{n+1})^2
$$

$$
p_{n+1} = 2 p_n
$$

$$
\pi_{n+1} = \frac{(a_{n+1} + b_{n+1})^2}{4 t_{n+1}}
$$
