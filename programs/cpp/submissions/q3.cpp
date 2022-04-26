#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	// create chrono start time
	for (int i = 0; i <= 5; i++) {
		auto startTime = std::chrono::system_clock::now();
	
		//Some more functions which are not important
	
		// get elapsed time
		auto elapsedTime = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = elapsedTime - startTime;
	
		// check if duration expires
		auto numSeconds = elapsed_seconds.count();
		float tMax = 3.5;
		while (numSeconds < tMax)
		{
	    	// Do different functions
	    	// check again
	    	elapsedTime = std::chrono::system_clock::now();
	    	elapsed_seconds = elapsedTime - startTime;
	    	numSeconds = elapsed_seconds.count();
				cout << numSeconds << endl;
		}
 	}	
}	
