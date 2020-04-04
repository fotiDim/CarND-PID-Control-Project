#ifndef PID_H
#define PID_H
#include <iostream>

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

  /**
   * Calculate the optimal PID coefficients using the Twiddle algorithm.
   * @output The current sum of dp
   */
  double Twiddle(double tolerance);

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;

 private:
  /**
   * PID Errors
   */
  double p_error = 0;
  double i_error = 0;
  double d_error = 0;
  
  // Twiddle params
  // double best_err = std::numeric_limits<double>::max();
  // double dp[3] = { 1, 1, 1 };
  // double accum_err2 = 0.0;
  // int iteration = 0;
  
  // void OptimizeCoefficient(double &coefficient, double &deltaCoefficient);
};

#endif  // PID_H
