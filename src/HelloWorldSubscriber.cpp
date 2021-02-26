/**
 * @file HelloWorldSubscriber.cpp
 *
 */

#include <WrapperDDSLibrary/MessageTestPubSubTypes.h>
#include <WrapperDDSLibrary/WrapperSubscriber.h>

int main(
        int argc,
        char** argv)
{
    std::cout << "Starting subscriber." << std::endl;
    int samples = 10;

    WrapperSubscriber* myWrapSub = new WrapperSubscriber(0);
    if(myWrapSub->init())
    {
        myWrapSub->run(static_cast<uint32_t>(samples));
    }

    delete myWrapSub;
    return 0;
}
