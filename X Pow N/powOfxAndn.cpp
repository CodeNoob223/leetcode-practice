#include<iostream>

class Solution {
public:
    double myPow(double x, int n) {
        return myPowHelper(x, n);
    }
private:
    double myPowHelper(double x, int n) {
        if (x == 0) return x;
        if (n == 0) return 1;

        double res = myPowHelper(x, n/2);
        res *= res;

        if (n % 2 != 0) {
            if (n > 0) {
                return res * x;
            } else {
                return res / x;
            }
        } else {
            return res;
        }
    }
};

int main() {
  std::cout << 3 / 2 << std::endl;

  return 0;
}