# 4.3 Odkształcenie sprężyste

$$ -\frac{d}{dx}\left(E(x)\frac{du(x)}{dx}\right) = 0 $$

$$ u(2) = 0 $$

$$ \frac{du(0)}{dx} + u(0) = 10 $$

$$ E(x) = \begin{cases}
3 & \text{dla } x \in [0, 1) \\
5 & \text{dla } x \in [1, 2]
\end{cases} $$

$$ \text{Gdzie } u \text{ to poszukiwana funkcja} \\
[0, 2] \ni x \rightarrow u(x) \in \mathbb{R} $$

# Wyprowadzenie sformułowania wariancyjnego

$$ -\frac{d}{dx}\left(E(x)\frac{du(x)}{dx}\right) = 0 \quad \Omega = [0, 2] $$
$$ E(x) = \begin{cases}
3 & \text{dla } x \in [0, 1) \\
5 & \text{dla } x \in [1, 2]
\end{cases} $$

$$ u'(0) + u(0) = 10 \quad u(2) = 0 $$

Prawostronny zerowy warunek brzegowy Dirichleta
$$ V = \{ v(x) : v(2) = 0 \} $$

$$ \int_{0}^{2} -\frac{d}{dx} \left( E(x) u'(x) \right) v(x) dx = \int_{0}^{2} 0 v(x) dx $$

$$ -\int_{0}^{2} \left(E'(x) u'(x) + E(x) u''(x)\right) v(x) dx = 0 $$

$$ \int_{0}^{2} \left(0 \cdot u'(x) + E(x) u''(x)\right) v(x) dx = 0 $$

$$ \int_{0}^{2} E(x) u''(x) v(x) dx = 0 $$

$$ \left[ E(x) u'(x) v(x) \right]_{0}^{2} - \int_{0}^{2} E(x) u'(x) v'(x) dx = 0 $$

$$ E(2) u'(2) v(2) - E(0) u'(0) v(0) - \int_{0}^{2} E(x) u'(x) v'(x) dx = 0 $$

Z warunków brzegowych

$$ E(2) u'(2) \cdot 0 - E(0) \left( 10 - u(0) \right) v(0) - \int_{0}^{2} E(x) u'(x) v'(x) dx = 0 $$

$$ E(0) u(0) v(0) - \int_{0}^{2} E(x) u'(x) v'(x) dx = 10 E(0) v(0) $$

$$ \int_{0}^{2} E(x) u'(x) v'(x) dx - E(0) u(0) v(0) = -10 E(0) v(0) $$

Ostatecznie

$$ B(u, v) = \int_{0}^{2} E(x) u'(x) v'(x) dx - E(0) u(0) v(0) \\
L(v) = -10 E(0) v(0) $$
