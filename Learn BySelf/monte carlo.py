import random, math

def estimate_pi(N=100000, r=1.0, seed=42):
    random.seed(seed)
    M = 0
    for _ in range(N):
        x = random.uniform(-r, r)
        y = random.uniform(-r, r)
        if x * x + y * y <= r*r:
            M += 1
    return 4 * M / N

# print(f"{estimate_pi():.3f}")

import random

def f(x, a, b, c):
    return a*x*x + b*x + c

def fitness(x, a, b, c):
    return 1 / (1 + abs(f(x, a, b, c)))

def genetic_solve(a, b, c, pop_size=50, generations=100, mutation_rate=0.1):
    # Step 1: initialize population (range -100..100)
    population = [random.uniform(-100, 100) for _ in range(pop_size)]

    for gen in range(generations):
        # Step 2: evaluate fitness
        scores = [fitness(x, a, b, c) for x in population]

        # Step 3: select top 50%
        sorted_pairs = sorted(zip(scores, population), reverse=True)
        population = [x for _, x in sorted_pairs[:pop_size // 2]]

        # Step 4: crossover
        children = []
        while len(children) < pop_size // 2:
            p1, p2 = random.sample(population, 2)
            child = (p1 + p2) / 2
            children.append(child)

        # Step 5: mutation
        for i in range(len(children)):
            if random.random() < mutation_rate:
                children[i] += random.uniform(-1, 1)

        population += children  # new generation

    # Step 6: best result
    best_x = max(population, key=lambda x: fitness(x, a, b, c))
    return best_x

# Example: solve 2x^2 + 3x - 2 = 0
a, b, c = 2, 3, -2
x_ga = genetic_solve(a, b, c)
print(f"Genetic solution ≈ {x_ga:.4f}")
print(f"Check: f(x) = {f(x_ga, a, b, c):.6f}")


    