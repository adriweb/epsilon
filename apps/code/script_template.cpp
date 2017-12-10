#include "script_template.h"

namespace Code {

constexpr ScriptTemplate emptyScriptTemplate(".py", R"(from math import *
)");

constexpr ScriptTemplate factorialScriptTemplate("factorial.py", R"(def factorial(n):
  if n == 0:
    return 1
  else:
    return n * factorial(n-1))");

constexpr ScriptTemplate fibonacciScriptTemplate("fibonacci.py", R"(def fibo(n):
  a=0
  b=1
  for i in range(1,n+1):
    c=a+b
    a=b
    b=c
  return a

def fibo2(n):
  if n==0:
    return 0
  elif n==1 or n==2:
    return 1
  return fibo2(n-1)+fibo2(n-2))");

constexpr ScriptTemplate mandelbrotScriptTemplate("mandelbrot.py", R"(from kandinsky import set_pixel
@micropython.viper
def mandelbrot(W,H,N) :
 w=2.7/(W-1)
 h=1.87/(H-1)
 n=255.0/N
 for x in range(W):
  for y in range(H):
   z=complex(0,0)
   c=complex(w*x-2.1,.935-h*y)
   for j in range(N):
    z=z*z+c
    if abs(z)>2:
     break
   set_pixel(x,y,255*20*j+256))");

constexpr ScriptTemplate polynomialScriptTemplate("polynomial.py", R"(from math import *
# roots(a,b,c) computes the solutions of the equation a*x**2+b*x+c=0
def roots(a,b,c):
  delta = b*b-4*a*c
  if delta == 0:
    return -b/(2*a)
  elif delta > 0:
    x_1 = (-b-sqrt(delta))/(2*a)
    x_2 = (-b+sqrt(delta))/(2*a)
    return x_1, x_2
  else:
    return None)");

const ScriptTemplate * ScriptTemplate::Empty() {
  return &emptyScriptTemplate;
}

const ScriptTemplate * ScriptTemplate::Factorial() {
  return &factorialScriptTemplate;
}

const ScriptTemplate * ScriptTemplate::Fibonacci() {
  return &fibonacciScriptTemplate;
}

const ScriptTemplate * ScriptTemplate::Mandelbrot() {
  return &mandelbrotScriptTemplate;
}

const ScriptTemplate * ScriptTemplate::Polynomial() {
  return &polynomialScriptTemplate;
}

}


