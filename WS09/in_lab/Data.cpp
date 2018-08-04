#include "Data.h"

namespace sict {
   // Min
   template<typename T>
   T min(const T * data, int n) {
      T min = LARGEST_NUMBER;
      for (int i = 0; i < n; i++) {
         if (min > data[i]) {
            min = data[i];
         }
      }
      return min;
   }

   // Max
   template<typename T>
   T max(const T * data, int n) {
      T max = SMALLEST_NUMBER;
      for (int i = 0; i < n; i++) {
         if (max < data[i]) {
            max = data[i];
         }
      }
      return max;
   }

   // Sum
   template<typename T>
   T sum(const T* data, int n) {
      T sum = 0;
      for (int i = 0; i < n; i++) {
         sum += data[i];
      }
      return sum;
   }

   // Average
   template<typename T>
   double average(const T* data, int n) {
      T average = sum(data, n) / n;
      return average;
   }

	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
      std::cout << "Population change from " << year[0] << " to " << year[n-1] << " is " << std::fixed << std::setprecision(2) << (population[n-1] - population[0]) / 1E+6 << " million" << std::endl;

		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
      if (violentCrime[0] > violentCrime[n - 1]) {
         std::cout << "Violent Crime trend is down" << std::endl;
      }
      else {
         std::cout << "Violent Crime trend is up" << std::endl;
      }

		// Q3 print the GTA number accurate to 0 decimal places
      std::cout << std::fixed << std::setprecision(2) << "There are " << average(grandTheftAuto, n) / 1E+6 << " million Grand Theft Auto incidents on average a year" << std::endl;

		// Q4. Print the min and max violentCrime rates
      std::cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << std::endl;
      std::cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << std::endl;
	}
}