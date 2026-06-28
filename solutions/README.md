# Definitions
- Count the number of FP in a binade. Verify that it is the same for two different binades
- Compute the ULP for some FPs. How it depends on the binade?
- Convert some number (0.1, e, pi, 31.5,  …) between various representations (including decimal). See what happens and explain it

# Arithmetic
- Sum T(0.1) 10000 times in binary32, binary64, decimal2, decimal5. (Google for “patriot failure”)
- Sum 10^9 positive random numbers (in range   10^-n, 10^+n )
- Compute the average age of all humans on earth
- Compute π as the integral of 4/(1+x2) between 0 and 1 (use float, double, simd, int, mixed)
- Solve the equation x2 – 2bx +1 = 0 using the “high-school” formula
What is the smallest value of b (single precision) for which one of the solution becomes 0?
What is instead the correct result? (use only single precision computations)

# Elementary Functions
- Range reduction for log, exp, trig
- Approximate sin(x) in [0, π/4) with polynomials of increasing order (Taylor, Chebyshev, Pade).
Plot the absolute and relative error w/r/t a high precision result
- Test  rsqrt precision in the interval [0.5, 4) 
use “quake magic” and/or x86_64 intrinsics plus multiple NR iterations
Try to reach faithful (or even correct) rounding.

- Compute sin(0x1.e64002p-2) using Taylor expansion:
How many terms are needed to reach faithful rounding in single precision?
How many more terms to reach correct rounding (in single precision)?
Use double precision to compute, then round to single   

                                         
# Code pitfalls and opportunity for optimization



                                         
