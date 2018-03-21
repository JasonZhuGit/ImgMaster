#include "corecontroller.h"

CoreController * CoreController::pSingleton = 0;

CoreController::CoreController()
{
}

CoreController::~CoreController()
{

}

CoreController * CoreController::getInstance()
{
    if (pSingleton == 0)
        pSingleton = new CoreController;
    return pSingleton;
}

void CoreController::destroy()
{
    if (pSingleton)
    {
        delete pSingleton;
        pSingleton = 0;
    }
}

bool CoreController::loadImg(const string & filename)
{
    CoreImage * pImg = new CoreImage();
    if (pImg->loadImage(filename))
    {
       //images.push_back(pImg);
        pushImageBack(pImg);
        return true;
    }
    else
    {
        std::cout << "fail to load image" << std::endl;
        return false;
    }
}

CoreImage * CoreController::getImageBack()
{
    return images.back();
}

CoreImage * CoreController::getImage(int index)
{
    return images.at(index);
}

CoreImage * CoreController::getImageFront()
{
    return images.front();
}

void CoreController::pushImageBack(CoreImage * & pCoreImage)
{
    images.push_back(pCoreImage);
}

std::vector<string> CoreController::getTitleList()
{
    std::vector<CoreImage * >::iterator it = images.begin();
    std::vector<CoreImage * >::iterator itEnd = images.end();
    std::vector<string> strlist;
    while (it != itEnd)
    {
        strlist.push_back((*it)->getTitle());
        it++;
    }
    return strlist;
}
