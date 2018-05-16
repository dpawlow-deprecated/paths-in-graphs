//
// Created by dante on 16.05.18.
//

#include "Weight.h"

Weight::Weight() {
    this->has_weight = false;
    this->weight = 0;
}

Weight::Weight(long weight) {
    this->has_weight = true;
    this->weight = weight;
}

long Weight::GetWeight() {
    if (this->has_weight) {
        return this->weight;
    } else {
        return 0;
    }
}

bool Weight::IsWeighted() {
    return this->has_weight;
}