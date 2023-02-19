#include "include/Vector3DTests.h"

int main()
{
    pxd::TestManager testManager;
    pxd::Vector3DTests vec3DTests;

    vec3DTests.AddTests(testManager);

    testManager.Run();

    return 0;
}
