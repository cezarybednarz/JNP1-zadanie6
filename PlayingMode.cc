#include "PlayingMode.h"

std::vector<size_t> SequenceMode::getOrder(size_t size) {
    std::vector<size_t> ret;
    for(size_t i = 0; i < size; i++) {
        ret.push_back(i);
    }
    return ret;
};


ShuffleMode::ShuffleMode(int seed) : randomEngine(std::default_random_engine(seed)) { }

std::vector<size_t> ShuffleMode::getOrder(size_t size) {
    std::vector<size_t> ret;
    for(size_t i = 0; i < size; i++) {
        ret.push_back(i);
    }
    std::shuffle(std::begin(ret), std::end(ret), randomEngine);
    return ret;
}


std::vector<size_t> OddEvenMode::getOrder(size_t size) {
    std::vector<size_t> ret;
    for(size_t i = 1; i < size; i += 2) {
        ret.push_back(i);
    }
    for(size_t i = 0; i < size; i += 2) {
        ret.push_back(i);
    }
    return ret;
}

std::shared_ptr<SequenceMode> createSequenceMode() {
    return std::make_shared<SequenceMode> (SequenceMode());
}

std::shared_ptr<ShuffleMode> createShuffleMode(int seed) {
    return std::make_shared<ShuffleMode> (ShuffleMode(seed));
}

std::shared_ptr<OddEvenMode> createOddEvenMode() {
    return std::make_shared<OddEvenMode> (OddEvenMode());
}
