#include <poincare/tofrac.h>

extern "C" {
#include <assert.h>
}
#include <cmath>
#include <string>
#include <math.h>
#include <poincare/src/layout/fraction_layout.h>

namespace Poincare {

ToFrac::ToFrac() :
  Function("tofrac")
{
}

static Expression* numer = nullptr;
static Expression* denom = nullptr;

Expression::Type ToFrac::type() const {
  return Type::ToFrac;
}

Expression * ToFrac::cloneWithDifferentOperands(Expression** newOperands,
        int numberOfOperands, bool cloneOperands) const {
  assert(newOperands != nullptr);
  ToFrac * tf = new ToFrac();
  tf->setArgument(newOperands, numberOfOperands, cloneOperands);
  return tf;
}

// Adapted from http://stackoverflow.com/a/32903747/378298
void dec2frac(double num, int* numer_p, int* denom_p, double err = 1e-8)
{
  if (err <= 0.0 || err >= 1.0)
  {
    err = 0.001;
  }

  int sign = ( num > 0 ) ? 1 : ( ( num < 0 ) ? -1 : 0 );

  if (sign == -1)
  {
    num = fabs(num);
  }

  if (sign != 0)
  {
    // err is the maximum relative err; convert to absolute
    err *= num;
  }

  int n = (int) floor(num);
  num -= n;

  if (num < err)
  {
    *numer_p = sign * n;
    return;
  }

  if (1 - err < num)
  {
    *numer_p = sign * (n + 1);
    return;
  }

  // The lower fraction is 0/1
  int lower_n = 0;
  int lower_d = 1;

  // The upper fraction is 1/1
  int upper_n = 1;
  int upper_d = 1;

  while (true)
  {
    // The middle fraction is (lower_n + upper_n) / (lower_d + upper_d)
    int middle_n = lower_n + upper_n;
    int middle_d = lower_d + upper_d;

    if (middle_d * (num + err) < middle_n)
    {
      // real + err < middle : middle is our new upper
      upper_n = middle_n;
      upper_d = middle_d;
    }
    else if (middle_n < (num - err) * middle_d)
    {
      // middle < real - err : middle is our new lower
      lower_n = middle_n;
      lower_d = middle_d;
    } else {
      // Middle is our best fraction
      *numer_p = (n * middle_d + middle_n) * sign;
      *denom_p = middle_d;
      return;
    }
  }
}


#define INT_DIGITS 19		/* enough for 64 bit integer */
static char *itoa(int i)
{
  /* Room for INT_DIGITS digits, - and '\0' */
  static char buf[INT_DIGITS + 2];
  char *p = buf + INT_DIGITS + 1;  /* points to terminating '\0' */
  if (i >= 0) {
    do {
      *--p = '0' + (i % 10);
      i /= 10;
    } while (i != 0);
    return p;
  } else {      /* i < 0 */
    do {
      *--p = '0' - (i % 10);
      i /= 10;
    } while (i != 0);
    *--p = '-';
  }
  return p;
}

template<typename T>
Complex<T> ToFrac::templatedComputeComplex(const Complex<T> c) const {
  int num, dec;
  dec2frac(c.a(), &num, &dec);
  numer = Expression::parse(itoa(num));
  denom = Expression::parse(itoa(dec));
  return c;
}

ExpressionLayout * ToFrac::createLayout(Expression::FloatDisplayMode floatDisplayMode, Expression::ComplexFormat complexFormat) const {
  return new FractionLayout(numer->createLayout(floatDisplayMode, complexFormat), denom->createLayout(floatDisplayMode, complexFormat));
}

}


