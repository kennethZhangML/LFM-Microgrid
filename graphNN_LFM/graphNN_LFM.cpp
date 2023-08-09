#include <torch/torch.h>
#include <iostream>

#include <vector>
#include <algorithm>

#include <FlexibilityCurve.h>


int main() {
	FlexibilityCurve curve({ 25, 10, 15, 0, -30, -10 });
	curve.print();
	std::cout << "Ramp-up at interval 0: " << curve.ramp_up(0) << std::endl;
	std::cout << "Ramp-down at interval 4: " << curve.ramp_down(4) << std::endl;
	std::cout << "Total ramp-up: " << curve.total_ramp_up() << std::endl;
	std::cout << "Total ramp-down: " << curve.total_ramp_down() << std::endl;

	return 0;
}

