#include "WordingStrategyBayern.h"

WordList WordingStrategyBayern::wordsForTime(uint8_t hour, uint8_t minute)
{
    WordList words;
    words.add(wordFactory->getWordES());
    words.add(wordFactory->getWordIS());

    hour = hour % 12;
    uint8_t fiveMinuteCluster = minute / 5;

    switch (fiveMinuteCluster)
    {
        case 0:
            if (minute == 0) {
                words.add(wordFactory->getWordPUNKT());
            }
            break;

        case 1:
            words.add(wordFactory->getWordFUEMF());
            words.add(wordFactory->getWordNOCH());
            break;

        case 2:
            words.add(wordFactory->getWordZEHN());
            words.add(wordFactory->getWordNOCH());
            break;

        case 3:
            words.add(wordFactory->getWordVIADL());
            words.add(wordFactory->getWordNOCH());
            break;

        case 4:
            words.add(wordFactory->getWordZWANZG());
            words.add(wordFactory->getWordNOCH());
            break;

        case 5:
            words.add(wordFactory->getWordFUEMF());
            words.add(wordFactory->getWordVOA());
            words.add(wordFactory->getWordHOIWE());
            break;

        case 6:
            words.add(wordFactory->getWordHOIWE());
            break;

        case 7:
            words.add(wordFactory->getWordFUEMF());
            words.add(wordFactory->getWordNOCH());
            words.add(wordFactory->getWordHOIWE());
            break;

        case 8:
            words.add(wordFactory->getWordZWANZG());
            words.add(wordFactory->getWordVOA());
            break;

        case 9:
            if(useDreivaidl)
            {
                words.add(wordFactory->getWordDREIVIADL());
            }
            else
            {
                words.add(wordFactory->getWordVIADL());
                words.add(wordFactory->getWordVOA());
            }
            break;

        case 10:
            words.add(wordFactory->getWordZEHN());
            words.add(wordFactory->getWordVOA());
            break;

        case 11:
            words.add(wordFactory->getWordFUEMF());
            words.add(wordFactory->getWordVOA());
            break;
    }

    if (fiveMinuteCluster >= 5)   // Ab "fuemf voa hoiwe" wird auf die naechste Stunde bezogen
        ++hour;

    words.add(wordFactory->getWordForHour(hour));

    return words;
};


