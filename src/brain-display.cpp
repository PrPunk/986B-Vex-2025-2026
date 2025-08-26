#include "vex.h"
#include <brain-display.h>

class BrainDisplay {
    public:
        Page *pages[5];

        int pagesUsed() {
            int usedPages = 0;
            for (int i = 0; i < 5; i++) {
                usedPages += 1;
            }
            return usedPages;
        }

        void createPage(int pageId) {
            
        }

    private:
        ;
};