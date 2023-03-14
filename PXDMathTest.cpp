#include "include/Vector3DTests.h"
#include "include/Vector2DTests.h"

int main()
{
    pxd::TestManager testManager;

    // --------------------------------------------
    // -- Tests
    pxd::Vector3DTests vec3DTests;
    pxd::Vector2DTests vec2DTests;

    // --------------------------------------------
    // -- Add Tests
    vec3DTests.AddTests(testManager);
    vec2DTests.AddTests(testManager);

    // --------------------------------------------
    // -- Run Tests
    testManager.Run();

    return 0;
}
