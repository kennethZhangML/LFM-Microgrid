#include <vector>
#include "FlexibilityCurve.h"
#include <iostream>


class Bid {
private:
    int aggregator_id;
    std::vector<std::pair<int, int>> flexibility_resources;
    int valuation;

public:
    // Constructor
    Bid(int aggregator_id, const std::vector<std::pair<int, int>>& flexibility_resources, int valuation)
        : aggregator_id(aggregator_id), flexibility_resources(flexibility_resources), valuation(valuation) {}

    // Check how well the bid matches the flexibility curve
    int match_with_curve(const FlexibilityCurve& curve) const {
        int total_match = 0;
        for (const auto& resource : flexibility_resources) {
            int interval = resource.first;
            int offered_value = resource.second;
            int required_value = curve.get_value(interval);

            // Calculate how well the bid matches the requirement for this interval
            total_match += std::min(std::abs(offered_value), std::abs(required_value));
        }
        return total_match;
    }

    // Print the bid details
    void print() const {
        std::cout << "Bid by Aggregator " << aggregator_id << " with valuation " << valuation << ": ";
        for (const auto& resource : flexibility_resources) {
            std::cout << "(" << resource.first << ", " << resource.second << ") ";
        }
        std::cout << std::endl;
    }
};