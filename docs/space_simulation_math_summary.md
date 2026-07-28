# Space Simulation Math — Beginner-Friendly Summary

## The Big Picture

A space simulation is basically this:

```text
Objects have:
- position
- movement
- mass

Gravity changes movement.
Movement changes position.
Repeat many times.
```

That repeated process creates:
- falling
- orbiting
- slingshots
- planetary systems

You are not solving giant equations analytically.
You are simulating tiny changes over time.

---

# The Core Simulation Loop

Every frame/update:

```text
1. Find direction between bodies
2. Find distance
3. Compute gravity force
4. Convert force into acceleration
5. Update velocity
6. Update position
```

That is the foundation of orbital mechanics simulation.

---

# Vectors

## What is a vector?

A vector is basically:

```text
Direction + magnitude
```

In code:

```c
{x, y, z}
```

Example:

```text
(3, 0, 0)
```

means:

```text
3 units to the right
```

---

# Why vectors are used everywhere

Physics quantities naturally have:
- direction
- strength

So all of these become vectors:

- position
- velocity
- acceleration
- force

The math is similar.
The meaning changes.

---

# Position Vector

Represents:

```text
Where is the object?
```

Example:

```text
Moon position:
(500, 0, 0)
```

Meaning:
- 500 units right
- 0 up
- 0 depth

---

# Velocity Vector

Represents:

```text
How is the object moving?
```

Example:

```text
(0, 50, 0)
```

Meaning:

```text
Move upward at speed 50
```

Velocity changes position over time.

---

# Force Vector

Represents:

```text
Push/pull direction and strength
```

Gravity creates force.

Example:

```text
(-10, 0, 0)
```

Meaning:

```text
Pull strongly to the left
```

---

# Direction Between Two Bodies

You calculate direction by subtracting positions.

## Formula

```text
Direction = EarthPosition - MoonPosition
```

Example:

```text
Earth: (150, 0, 0)
Moon:  (500, 0, 0)
```

Result:

```text
(-350, 0, 0)
```

Meaning:

```text
From moon to earth:
move 350 units left
```

---

# Vector Magnitude (Length)

Magnitude means:

```text
How long is the vector?
```

For a direction vector:

```text
It represents distance.
```

## Formula

$$
|v| = \sqrt{x^2 + y^2 + z^2}
$$

Example:

```text
(3, 4, 0)
```

Magnitude:

$$
\sqrt{3^2 + 4^2} = 5
$$

---

# Normalization

Normalization means:

```text
Keep only direction.
Remove distance.
```

Example:

```text
(-350, 0, 0)
```

becomes:

```text
(-1, 0, 0)
```

This is now:

```text
Pure left direction
```

with length exactly:

```text
1
```

This is important because:

```text
Gravity needs:
- direction
- strength
```

separately.

---

# Newtonian Gravity

## Formula

$$
F = G \frac{m_1 m_2}{r^2}
$$

Where:

- $$F$$ = gravity strength
- $$G$$ = gravitational constant
- $$m_1$$ = mass of body 1
- $$m_2$$ = mass of body 2
- $$r$$ = distance between bodies

---

# Important intuition

As distance decreases:

```text
Gravity becomes stronger.
```

Because of:

$$
\frac{1}{r^2}
$$

This is why your moon accelerates more as it gets closer.

---

# Force Magnitude vs Force Vector

The gravity formula only gives:

```text
How strong gravity is.
```

Not direction.

So:

## Step 1
Direction:

```text
(-1, 0, 0)
```

## Step 2
Gravity strength:

```text
50
```

## Step 3
Combine them:

```text
(-1,0,0) * 50
=
(-50,0,0)
```

Now you have:

```text
A force vector.
```

Meaning:

```text
Pull left with strength 50.
```

---

# Acceleration

Newton:

$$
F = ma
$$

Rearranged:

$$
a = \frac{F}{m}
$$

Meaning:

```text
Force changes movement.
```

Heavy objects accelerate less.

---

# Delta Time (dt)

Computers simulate motion in tiny steps.

`dt` means:

```text
How much simulated time passes per update.
```

Example:

```text
dt = 0.016
```

roughly means:

```text
16 milliseconds
```

---

# Velocity Update

## Formula

$$
v_{new} = v_{old} + a \cdot dt
$$

Meaning:

```text
Acceleration changes velocity over time.
```

Gravity slowly changes movement direction and speed.

---

# Position Update

## Formula

$$
p_{new} = p_{old} + v \cdot dt
$$

Meaning:

```text
Velocity changes position over time.
```

---

# The Entire Physics Chain

This is the most important thing in the entire simulation.

```text
Gravity Force
→ Acceleration
→ Velocity
→ Position
```

Repeated thousands of times:

```text
Orbit emerges.
```

---

# Why Orbit Happens

Without sideways velocity:

```text
Moon falls directly into Earth.
```

With sideways velocity:

```text
Moon keeps missing Earth while falling.
```

That curved falling motion is orbit.

---

# Why Simulations Use Approximation

Real motion is continuous.

Computers approximate it by repeatedly applying:

```text
small changes
```

This is called:

```text
Numerical integration
```

---

# Euler Integration

Your current simulation uses a simple method called:

```text
Euler integration
```

Meaning:

```text
position += velocity * dt
velocity += acceleration * dt
```

It is simple and great for learning.

But later you may notice:
- spiraling orbits
- instability
- energy drift

That is normal.

Later you can learn:
- semi-implicit Euler
- Verlet integration

which are more stable for orbital mechanics.

---

# Simplified Simulation Units

Using real astronomical values initially is difficult.

So it is common to use:

```text
Fake units
```

Example:

```text
Earth mass = 10000
Moon mass = 50
G = 5000
```

This makes debugging and learning much easier.

---

# Important Engineering Insights

## Separate simulation from rendering

Physics should only calculate:
- positions
- velocities
- forces

Rendering should only:
- draw the current state

This creates clean architecture.

---

# Why Starting in 2D Helps

3D adds:
- camera complexity
- debugging difficulty
- orientation confusion

2D already teaches:
- gravity
- vectors
- integration
- orbital motion

So:

```text
2D first is usually smarter.
```

---

# The Most Important Intuition

A simulation is not:

```text
One giant equation.
```

It is:

```text
Repeated tiny corrections over time.
```

That is why coding these systems often makes the math finally feel understandable.

You are turning abstract equations into evolving state.
