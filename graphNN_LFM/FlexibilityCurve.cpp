#include <iostream>
#include <vector>
#include <algorithm>

class FlexibilityCurve {

private:
	std::vector<int> values;

public:

	FlexibilityCurve(const std::vector<int>& values) : values(values) {}

	int ramp_up(int interval) const {
		return std::max(values[interval], 0);
	}

	int ramp_down(int interval) const {
		return std::max(-values[interval], 0);
	}

	int total_ramp_up() const {
		int total = 0;
		for (int value : values) {
			total += std::max(value, 0);
		}
		return total;
	}

	int total_ramp_down() const {
		int total = 0;
		for (int value : values) {
			total += std::max(-value, 0);
		}
		return total;
	}

	void print() const {
		std::cout << "FlexibilityCurve(";
		for (size_t i = 0; i < values.size(); ++i) {
			std::cout << values[i];
			if (i != values.size() - 1) {
				std::cout << ", ";
			}
		}
		std::cout << ")" << std::endl;
	}
};