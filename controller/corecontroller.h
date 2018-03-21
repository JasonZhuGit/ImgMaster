#ifndef CORECONTROLLER_H
#define CORECONTROLLER_H

#include <iostream>
#include <list>
#include <opencv2/core/core.hpp>
#include <model/coreimage.h>

class CoreController
{
public:
    CoreController();
    ~CoreController();

    static CoreController * pSingleton;
    static CoreController * getInstance();
    static void destroy();

    vector<CoreImage *> images;

    bool loadImg(const string & filename);
    void pushImageBack(CoreImage * & pCoreImage);
    CoreImage * getImageFront();
    CoreImage * getImageBack();
    CoreImage * getImage(int index);
    std::vector<string> getTitleList();
};

#endif // CORECONTROLLER_H
