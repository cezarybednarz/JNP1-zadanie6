#ifndef PLAYINGMODE_H
#define PLAYINGMODE_H

#include <random>
#include <algorithm>

class PlayingMode {

public:
    PlayingMode() = default;
    ~PlayingMode() = default;

    virtual std::vector<size_t> getOrder(size_t size) = 0;
};

class SequenceMode : public PlayingMode {
    std::vector<size_t> getOrder(size_t size) override;
};

class ShuffleMode : public PlayingMode {
public:
    explicit ShuffleMode(int seed);
    std::vector<size_t> getOrder(size_t size) override;
private:
    std::default_random_engine randomEngine;
};

class OddEvenMode : public PlayingMode {
    std::vector<size_t> getOrder(size_t size) override;
};


SequenceMode createSequenceMode() {
    return SequenceMode();
}

ShuffleMode createShuffleMode(int seed) {
    return ShuffleMode(seed);
}

OddEvenMode createOddEvenMode() {
    return OddEvenMode();
}

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


#endif // PLAYINGMODE_H
