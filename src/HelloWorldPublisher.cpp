/**
 * @file HelloWorldPublisher.cpp
 *
 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include <WrapperDDSLibrary/MessageTestPubSubTypes.h>
#include <WrapperDDSLibrary/WrapperPublisher.h>

int main(
        int argc,
        char** argv)
{
    std::cout << "Starting publisher." << std::endl;
    int samples = 10;
    double now = 0.0;

    MessageTest msgTest;
    msgTest.now(now);
    msgTest.message("HelloWorld");

    WrapperPublisher* myWrapPub = new WrapperPublisher(0);
    if (myWrapPub->init())
    {
	pid_t pid = getpid();

	std::cout << "PID of process that publishes messages: " << pid << std::endl;

        myWrapPub->run(static_cast<uint32_t>(samples), &msgTest);
    }

    delete myWrapPub;
    return 0;
}
