#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Kd = Kd_;
  Ki = Ki_;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;

  // accum_err2 += cte*cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
   
  //  "Total Error" means that you need to sum up the `cte`, `difference of cte`, and `integral of cte`.
  //  `cte` helps to remove the error quickly, `difference of cte` prevents the car from overshoting the central line, and `integral of cte` can eliminate system error. When you sum all these terms up, you can get a stable PID controller.
  return -Kp * p_error - Ki * i_error - Kd * d_error;  // TODO: Add your total error calc here!
}

// double PID::Twiddle(double tolerance) {
  // double dp[3] = { 1, 1, 1 };
  // msg = "42[\"reset\",{}]"; //reset car
  // x_trajectory, y_trajectory, best_err = run(robot, p)

  // Twiddle loop here
//   if (dp[0] + dp[1] + dp[2] > tolerance) {
//     OptimizeCoefficient(Kp, dp[0]);
//     std::cout << Kp << ", " << dp[0] << std::endl;
//     OptimizeCoefficient(Ki, dp[1]);
//     OptimizeCoefficient(Kd, dp[2]);
    // msg = "42[\"reset\",{}]";
//   }
//   ++iteration;
//   return dp[0] + dp[1] + dp[2];
// }

// void PID::OptimizeCoefficient(double &coefficient, double &deltaCoefficient) {
//   double err = accum_err2 / iteration;
//   coefficient += deltaCoefficient;

//   if (err / iteration < best_err) {
//       best_err = err;
//       deltaCoefficient *= 1.1;
//   }
//   else {
//       coefficient -= 2 * deltaCoefficient;
//       if (err / iteration < best_err) {
//           best_err = err;
//           deltaCoefficient *= 1.1;
//       }
//       else {
//           coefficient += deltaCoefficient;
//           deltaCoefficient *= 0.9;
//       }
//   }
// }
