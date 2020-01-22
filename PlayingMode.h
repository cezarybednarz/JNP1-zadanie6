#ifndef PLAYINGMODE_H
#define PLAYINGMODE_H

#include <random>
#include <algorithm>
#include <memory>

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

std::shared_ptr<SequenceMode> createSequenceMode();
std::shared_ptr<ShuffleMode> createShuffleMode(int seed);
std::shared_ptr<OddEvenMode> createOddEvenMode(); 

#endif // PLAYINGMODE_H
