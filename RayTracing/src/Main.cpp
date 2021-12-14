#include <iostream>

#define print(x) std::cout << x 
#define println(x) std::cout << x << std::endl
int main()
{

	const int image_height = 1000;
	const int image_width = 1000; 

	println("P3");
	print(image_height);
	print(" ");
	println(image_width);
	println("255");


	for (int r = 0; r < image_width; r++)
	{
		std::cerr << "\rScanlines progress: " << (float)100*r/image_width << '%' << std::flush;
		for (int c = 0; c < image_height; c++)
		{
			print(255 * r / image_width);
			print(" ");
			print(255 * c / image_height);
			print(" ");
			println(125);

		
		}

	}

	std::cerr << "\nDone.\n";


}
