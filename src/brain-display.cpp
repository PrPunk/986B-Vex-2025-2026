#include "vex.h"
#include <brain-display.h>
#include <array>

class BrainDisplay {
    public:
        Page *pages[5];

        std::array<unsigned int, 5> availablePages () {
            std::array<unsigned int, 5> pagesAvail;
            unsigned int usedPartsAvail = 0;
            for (int i = 0; i < 5; i++) {
                if (pages[i] != NULL) {
                    pagesAvail[usedPartsAvail] = i;
                    usedPartsAvail ++;
                }
            }
            return pagesAvail;
        }

        void createPage(unsigned int pageId) {
            std::array<unsigned int, 5> reservedPages = availablePages();
            if (!(pageId < 5 && pageId >= 0 && pageId != NULL)) {
                //error: pageId is not within valid range
                return;
            }
            for (int i = 0; i < 5; i++) {
                if (reservedPages[i] == pageId) {
                    //error: pageId is in use
                    return;
                }
            }
        }

    private:
        ;
};