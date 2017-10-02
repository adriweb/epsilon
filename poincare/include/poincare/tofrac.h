#ifndef POINCARE_TOFRAC_H
#define POINCARE_TOFRAC_H

#include <poincare/function.h>

namespace Poincare {

class ToFrac : public Function {
public:
    ToFrac();
  Type type() const override;
  Expression * cloneWithDifferentOperands(Expression ** newOperands,
    int numberOfOperands, bool cloneOperands = true) const override;

    ExpressionLayout *createLayout(FloatDisplayMode floatDisplayMode, ComplexFormat complexFormat) const override;

private:
  Complex<float> computeComplex(const Complex<float> c, AngleUnit angleUnit) const override {
    return templatedComputeComplex(c);
  }
  Complex<double> computeComplex(const Complex<double> c, AngleUnit angleUnit) const override {
    return templatedComputeComplex(c);
  }
  template<typename T> Complex<T> templatedComputeComplex(const Complex<T> c) const;

};

}

#endif


