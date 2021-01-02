#include "WordingStrategyRoadaburch.h"

WordList WordingStrategyRoadaburch::wordsForTime(uint8_t hour, uint8_t minute)
{
    WordList words;
    words.add(wordFactory->getWordETZ());
    words.add(wordFactory->getWordIS());

    hour = hour % 12;
    uint8_t fiveMinuteCluster = minute / 5;

    switch (fiveMinuteCluster)
    {
        case 0:
            if (minute == 0) {
                words.add(wordFactory->getWordSCHO());
             }
            break;

        case 1:
            words.add(wordFactory->getWordFUENF());
            words.add(wordFactory->getWordNACH());
            break;

        case 2:
            words.add(wordFactory->getWordZEAH());
            words.add(wordFactory->getWordNACH());
            break;

        case 3:
            words.add(wordFactory->getWordFERDL());
            break;

        case 4:
            words.add(wordFactory->getWordZEAH());
            words.add(wordFactory->getWordVOR());
            words.add(wordFactory->getWordHALBER());
            break;

        case 5:
            words.add(wordFactory->getWordFUENF());
            words.add(wordFactory->getWordVOR());
            words.add(wordFactory->getWordHALBER());
            break;

        case 6:
            words.add(wordFactory->getWordHALBER());
            break;

        case 7:
            words.add(wordFactory->getWordFUENF());
            words.add(wordFactory->getWordNACH());
            words.add(wordFactory->getWordHALBER());
            break;

        case 8:
            words.add(wordFactory->getWordZEAH());
            words.add(wordFactory->getWordNACH());
            words.add(wordFactory->getWordHALBER());
            break;

        case 9:
            words.add(wordFactory->getWordDREIFERDL());
            break;

        case 10:
            words.add(wordFactory->getWordZEAH());
            words.add(wordFactory->getWordVOR());
            break;

        case 11:
            words.add(wordFactory->getWordFUENF());
            words.add(wordFactory->getWordVOR());
            break;
    }

    if (fiveMinuteCluster >= 3)   // Ab "ferdl" wird auf die naechste Stunde bezogen
        ++hour;

    words.add(wordFactory->getWordForHour(hour));

    return words;
};


