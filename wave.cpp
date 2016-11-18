#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES


int main() {
    using namespace std;
    // the size of array
    const int n = 1000;

    double cycle = 2*M_PI;
    double arr[n];
    int input;
    cout << "choose one wave for input, one for sine, two for triangle, three for rectangle" << endl;
    cin >> input;

    // sine wave
    if(input == 1)
    {
    	for(int i  = 0; i < n; i++)
    	{
			arr[i] = abs(sin(10*i*cycle/n));
    		cout << arr[i] << endl;
    	}
	}

	// triangle wave
	else if(input == 2)
	{
		arr[0] = 0;
		arr[1] = 4.0/n;
		for(int i = 1; i < n - 1; i++)
			{
				if(arr[i] < 1 && arr[i] > 0 && arr[i] > arr[i-1])
					arr[i+1] = arr[i]+40.0/n;
				else if(arr[i] >= 1)
				{
					arr[i] = 1;
					arr[i+1] = arr[i]-40.0/n;
				}
				else if(arr[i] < 1 && arr[i] > 0 && arr[i] < arr[i-1])
					arr[i+1] = arr[i]-40.0/n;
				else if(arr[i] <= 0)
				{
					arr[i] = 0;
					arr[i+1] = arr[i]+40.0/n;
				}
				else
					arr[i+1] = 500;

				cout << arr[i] << endl;
			}
	}

	// rectangle wave
	// else if(input ==3)
	// {
	// 	for(int i = 1; i < n; i++)
	// 	{
	// 		if((20*i/n) % 2 == 0)
	// 			arr[i] = 1;
	// 		else
	// 			arr[i] = -1;
	// 		cout << arr[i] << endl;
	// 	}
	// }
	else
		cout << "wrong input"<< endl;

    return 0;
}
